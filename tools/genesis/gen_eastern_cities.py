#!/usr/bin/env python3
"""One-shot generator: remaining Eastern AURELIA city stubs (badges 12-18).

Clones the MirageCity / ObsidianCity pattern (outdoor layout clone + Center 1F/2F + Mart + Gym),
moves leader battles from EasternAurelia_Hall into the gyms, and appends the shared registry
entries (map_groups, event_scripts.s, heal_locations, region_map_sections, map_name_popup).

Run from repo root:  python tools/genesis/gen_eastern_cities.py
One-shot (kept for reference): aborts if the Hall is already rewritten or any city map exists.
"""
import json
import os
import re
import struct
import sys
from collections import deque

ROOT = os.getcwd()
MAPS = "data/maps"


def rd(path):
    with open(path, encoding="utf-8", newline="") as f:
        return f.read()


def wr(path, text):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", encoding="utf-8", newline="") as f:
        f.write(text)


# --------------------------------------------------------------------------------------
# City table
# --------------------------------------------------------------------------------------
# door positions below are the vanilla door tiles of the cloned layout.
CITIES = [
    dict(
        name="AstralCity", const="ASTRAL_CITY", disp="ASTRAL CITY", short="Astral",
        layout="LAYOUT_SLATEPORT_CITY", src="SlateportCity", music="MUS_SOOTOPOLIS",
        theme="STONE2", gym=(10, 12), center=(19, 19), mart=(13, 26),
        gym_sign=(7, 13), town_sign=(16, 22),
        leader="DRAKE", Leader="Drake", trainer="TRAINER_GENESIS_DRAKE_GYM", badge=12,
        badge_name="ASTRAL BADGE", badge_label="GotAstralBadge", gfx="OBJ_EVENT_GFX_OLD_MAN",
        prev_leader="NOCTIS", prev_badge=11, next_hint="TIDYMOON CITY--LUNA",
        type="DRAGON", tera=True, townmon="Astral", pronoun=("him", "he"),
        sign_tag="Where the stars land first.", gym_tag="Aim higher than the sky.",
        girl="DRAKE charts the sky with his DRAGONS.\\pBeat him at the GYM first.\\nThen ask me about the DRAGON that\\lferries storm-lost ships.",
        transport="star-lift", transport_text="The star-lift hums…\\nRise toward the aurora.",
        stay_text="The stars will keep.\\nReturn when you're ready.",
        attendant_stay="Take your time in ASTRAL CITY.\\nThe star-lift will wait.",
        flavor="Cliff spires under aurora fire.",
        mart_woman="DRAKE's trainers stock up on\\nFULL HEALS and REVIVES.\\lDragon tails hit hard.",
        guide="They're tough against FIRE, WATER,\\nELECTRIC and GRASS, but weak to\\lICE, DRAGON, and FAIRY.",
        mart_late=False,
    ),
    dict(
        name="TidymoonCity", const="TIDYMOON_CITY", disp="TIDYMOON CITY", short="Tidymoon",
        layout="LAYOUT_MOSSDEEP_CITY", src="MossdeepCity", music="MUS_RG_SEVII_123",
        theme="UNDERWATER", gym=(38, 9), center=(28, 16), mart=(37, 18),
        gym_sign=(34, 9), town_sign=(25, 16),
        leader="LUNA", Leader="Luna", trainer="TRAINER_GENESIS_LUNA", badge=13,
        badge_name="MOON BADGE", badge_label="GotMoonBadge", gfx="OBJ_EVENT_GFX_WOMAN_2",
        prev_leader="DRAKE", prev_badge=12, next_hint="EON CITY--MORRIGAN",
        type="FAIRY", tera=False, townmon="Tidymoon", pronoun=("her", "she"),
        sign_tag="Wishes float in on the tide.", gym_tag="Soft power still wins wars.",
        girl="LUNA dances with FAIRY POKéMON\\nunder the moon.\\pBeat her at the GYM first.\\nThen ask me about the jubilee that\\lblesses kind hearts.",
        transport="moon-ferry", transport_text="The moon-ferry glides in…\\nStep aboard.",
        stay_text="The tide will wait.\\nReturn when you're ready.",
        attendant_stay="Take your time in TIDYMOON CITY.\\nThe moon-ferry will wait.",
        flavor="Tide gardens lit by pale moons.",
        mart_woman="LUNA's trainers stock up on\\nANTIDOTES and FULL HEALS.\\lSteel and poison bite fairies.",
        guide="They're tough against FIGHTING, BUG\\nand DARK, and DRAGON moves can't\\ltouch them. But POISON and STEEL\\lhit them hard.",
        mart_late=False,
    ),
    dict(
        name="EonCity", const="EON_CITY", disp="EON CITY", short="Eon",
        layout="LAYOUT_MAUVILLE_CITY", src="MauvilleCity", music="MUS_RG_POKE_TOWER",
        theme="MARBLE", gym=(8, 5), center=(22, 5), mart=(23, 14),
        gym_sign=(11, 6), town_sign=(19, 7),
        leader="MORRIGAN", Leader="Morrigan", trainer="TRAINER_GENESIS_MORRIGAN", badge=14,
        badge_name="EON BADGE", badge_label="GotEonBadge", gfx="OBJ_EVENT_GFX_WOMAN_5",
        prev_leader="LUNA", prev_badge=13, next_hint="GENESIS CITY--the Colleague",
        type="GHOST", tera=False, townmon="Eon", pronoun=("her", "she"),
        sign_tag="Hear the bells between hours.", gym_tag="Honor what lingers.",
        girl="MORRIGAN's GHOSTS drift between eras.\\pBeat her at the GYM first.\\nThen ask me about the nest in the\\lbelfry dark.",
        transport="echo-gate", transport_text="The echo-gate chimes…\\nStep between the hours.",
        stay_text="The past will keep.\\nReturn when you're ready.",
        attendant_stay="Take your time in EON CITY.\\nThe echo-gate will wait.",
        flavor="Clocktower streets between eras.",
        mart_woman="MORRIGAN's trainers stock up on\\nHYPER POTIONS and ULTRA BALLS.\\lSpirits slip away fast.",
        guide="They're tough against POISON and BUG,\\nand NORMAL and FIGHTING can't touch\\lthem. They're weak to GHOST and DARK.",
        mart_late=False,
    ),
    dict(
        name="GenesisCity", const="GENESIS_CITY", disp="GENESIS CITY", short="GenesisCity",
        layout="LAYOUT_PETALBURG_CITY", src="PetalburgCity", music="MUS_PETALBURG",
        theme="BRICK", gym=(15, 8), center=(20, 16), mart=(25, 12),
        gym_sign=(17, 10), town_sign=(17, 16),
        leader="COLLEAGUE", Leader="Colleague", trainer="TRAINER_GENESIS_COLLEAGUE", badge=15,
        badge_name="GENESIS BADGE", badge_label="GotGenesisBadge", gfx="OBJ_EVENT_GFX_GENTLEMAN",
        prev_leader="MORRIGAN", prev_badge=14, next_hint="AURELIA SUMMIT--Mentor's ROCK",
        type="NORMAL", tera=False, townmon="GenesisCity", pronoun=("them", "they"),
        sign_tag="Potential is measured in battle.", gym_tag="Adapt. Prepare. Prevail.",
        girl="The COLLEAGUE favors NORMAL types--\\nplain, but never simple.\\pBeat them at the GYM first.\\nThen ask me about the lazy giant in\\lthe training yards.",
        transport="hub shuttle", transport_text="The hub shuttle spins up…\\nMind the gap.",
        stay_text="The lab will keep.\\nReturn when you're ready.",
        attendant_stay="Take your time in GENESIS CITY.\\nThe hub shuttle will wait.",
        flavor="The Colleague's lab-city hub.",
        mart_woman="The COLLEAGUE's trainers stock up on\\nMAX POTIONS and FULL HEALS.\\lAdaptability is our creed.",
        guide="They're plain but dependable.\\nThey're weak to FIGHTING only, and\\lGHOST moves can't touch them.",
        mart_late=True,
    ),
    dict(
        name="SummitCity", const="SUMMIT_CITY", disp="SUMMIT CITY", short="Summit",
        layout="LAYOUT_RUSTBORO_CITY", src="RustboroCity", music="MUS_RG_MT_MOON",
        theme="STONE", gym=(27, 19), center=(16, 38), mart=(16, 45),
        gym_sign=(23, 19), town_sign=(19, 49),
        leader="MENTOR", Leader="Mentor", trainer="TRAINER_GENESIS_MENTOR", badge=16,
        badge_name="ASCENSION BADGE", badge_label="GotAscensionBadge", gfx="OBJ_EVENT_GFX_EXPERT_M",
        prev_leader="COLLEAGUE", prev_badge=15, next_hint="VENOM HOLLOW--VESPER",
        type="ROCK", tera=False, townmon="Summit", pronoun=("him", "he"),
        sign_tag="Stone remembers every ascent.", gym_tag="Build on bedrock.",
        girl="The MENTOR guards the eastern peak\\nwith ROCK POKéMON.\\pBeat him at the GYM first.\\nThen ask me about the armored\\lmountain that woke below.",
        transport="cliff-lift", transport_text="The cliff-lift grinds upward…\\nHold fast.",
        stay_text="The mountain will keep.\\nReturn when you're ready.",
        attendant_stay="Take your time in SUMMIT CITY.\\nThe cliff-lift will wait.",
        flavor="Eastern peak of the old road.",
        mart_woman="The MENTOR's trainers stock up on\\nSUPER REPELS and HYPER POTIONS.\\lThe climb is long.",
        guide="They're tough against NORMAL, FIRE,\\nPOISON and FLYING, but weak to\\lWATER, GRASS, FIGHTING, GROUND\\land STEEL.",
        mart_late=True,
    ),
    dict(
        name="VenomHollow", const="VENOM_HOLLOW", disp="VENOM HOLLOW", short="Venom",
        layout="LAYOUT_FALLARBOR_TOWN", src="FallarborTown", music="MUS_RG_ROCKET_HIDEOUT",
        theme="WOOD", gym=(8, 7), center=(14, 7), mart=(15, 15),
        gym_sign=(6, 8), town_sign=(10, 11),
        leader="VESPER", Leader="Vesper", trainer="TRAINER_GENESIS_VESPER", badge=17,
        badge_name="VENOM BADGE", badge_label="GotVenomBadge", gfx="OBJ_EVENT_GFX_HEX_MANIAC",
        prev_leader="MENTOR", prev_badge=16, next_hint="TERRACOTTA MESA--TERRA",
        type="POISON", tera=False, townmon="Venom", pronoun=("her", "she"),
        sign_tag="Antidotes sell better than gold.", gym_tag="Poison is honesty.",
        girl="VESPER brews POISON like others\\npour tea.\\pBeat her at the GYM first.\\nThen ask me about the trickster\\lthat haunts the vapor vents.",
        transport="lantern-boat", transport_text="The lantern-boat drifts in…\\nMind the fumes.",
        stay_text="The mist will keep.\\nReturn when you're ready.",
        attendant_stay="Take your time in VENOM HOLLOW.\\nThe lantern-boat will wait.",
        flavor="Marsh lanterns over toxic bloom.",
        mart_woman="VESPER's trainers stock up on\\nANTIDOTES and FULL HEALS.\\lEveryone leaves here immune.",
        guide="They're tough against GRASS, FIGHTING,\\nPOISON, BUG and FAIRY, but weak to\\lGROUND and PSYCHIC.",
        mart_late=True,
    ),
    dict(
        name="TerracottaMesa", const="TERRACOTTA_MESA", disp="TERRACOTTA MESA", short="Terracotta",
        layout="LAYOUT_VERDANTURF_TOWN", src="VerdanturfTown", music="MUS_DESERT",
        theme="BRICK", gym=(3, 7), center=(16, 3), mart=(12, 3),
        gym_sign=(1, 8), town_sign=(14, 6),
        leader="TERRA", Leader="Terra", trainer="TRAINER_GENESIS_TERRA", badge=18,
        badge_name="TERRA BADGE", badge_label="GotTerraBadge", gfx="OBJ_EVENT_GFX_EXPERT_F",
        prev_leader="VESPER", prev_badge=17, next_hint=None,
        type="GROUND", tera=False, townmon="Terracotta", pronoun=("her", "she"),
        sign_tag="The last type closes the circle.", gym_tag="Stand firm.",
        girl="TERRA's GROUND POKéMON never yield.\\pBeat her at the GYM first.\\nThen ask me about the land shark\\lthat patrols the mesa dunes.",
        transport="dune-runner", transport_text="The dune-runner kicks up dust…\\nHold your hat.",
        stay_text="The mesa will keep.\\nReturn when you're ready.",
        attendant_stay="Take your time in TERRACOTTA MESA.\\nThe dune-runner will wait.",
        flavor="Red clay mesas and buried ruins.",
        mart_woman="TERRA's trainers stock up on\\nMAX POTIONS and REVIVES.\\lClay dust gets everywhere.",
        guide="They're tough against POISON and ROCK,\\nand ELECTRIC can't touch them.\\lThey're weak to WATER, GRASS and ICE.",
        mart_late=True,
    ),
]

# Hall NPC / desk label names per leader / city
HALL_DESK = {"AstralCity": "Astral", "TidymoonCity": "Tidymoon", "EonCity": "Eon", "GenesisCity": "Genesis",
             "SummitCity": "Summit", "VenomHollow": "Venom", "TerracottaMesa": "Terracotta"}
PREV_NEED = {  # badge -> Hall NeedX label for the previous leader's badge
    12: "Noctis", 13: "Drake", 14: "Luna", 15: "Morrigan", 16: "Colleague", 17: "Mentor", 18: "Vesper"}


# --------------------------------------------------------------------------------------
# Layout analysis (to pick safe NPC tiles)
# --------------------------------------------------------------------------------------
LAYOUTS = {l["id"]: l for l in json.loads(rd("data/layouts/layouts.json"))["layouts"] if "id" in l}
MB_INV = {}
_idx = 0
for _line in rd("include/constants/metatile_behaviors.h").splitlines():
    _m = re.match(r"\s*(MB_\w+)\s*(?:=\s*(0x[0-9A-Fa-f]+|\d+))?\s*,", _line)
    if _m:
        if _m.group(2):
            _idx = int(_m.group(2), 0)
        MB_INV[_idx] = _m.group(1)
        _idx += 1
WATER_MB = {"MB_POND_WATER", "MB_INTERIOR_DEEP_WATER", "MB_DEEP_WATER", "MB_WATERFALL", "MB_SOOTOPOLIS_DEEP_WATER",
            "MB_OCEAN_WATER", "MB_UNUSED_SOOTOPOLIS_DEEP_WATER", "MB_UNUSED_SOOTOPOLIS_DEEP_WATER_2", "MB_FAST_WATER",
            "MB_CYCLING_ROAD_WATER"}


def tileset_dir(sym):
    name = sym.replace("gTileset_", "")
    s = re.sub(r"(?<!^)(?=[A-Z])", "_", name).lower()
    for kind in ("primary", "secondary"):
        p = f"data/tilesets/{kind}/{s}"
        if os.path.isdir(p):
            return p
    for kind in ("primary", "secondary"):
        for d in os.listdir(f"data/tilesets/{kind}"):
            if d.replace("_", "") == s.replace("_", ""):
                return f"data/tilesets/{kind}/{d}"
    raise RuntimeError(sym)


class Layout:
    def __init__(self, lid):
        l = LAYOUTS[lid]
        self.w, self.h = l["width"], l["height"]
        raw = open(l["blockdata_filepath"], "rb").read()
        self.blk = struct.unpack("<%dH" % (len(raw) // 2), raw)
        self.pa, self.pw = self._load(tileset_dir(l["primary_tileset"]))
        self.sa, self.sw = self._load(tileset_dir(l["secondary_tileset"]))

    @staticmethod
    def _load(d):
        attrs = open(d + "/metatile_attributes.bin", "rb").read()
        count = os.path.getsize(d + "/metatiles.bin") // 16
        width = len(attrs) // count
        assert width in (2, 4), (d, width)
        return attrs, width

    def behavior_name(self, x, y):
        mid = self.blk[y * self.w + x] & 0x3FF
        data, idx, w = (self.pa, mid, self.pw) if mid < 512 else (self.sa, mid - 512, self.sw)
        if (idx + 1) * w > len(data):
            return ""
        v = struct.unpack_from("<H" if w == 2 else "<I", data, idx * w)[0]
        return MB_INV.get(v & (0xFF if w == 2 else 0x1FF), "")

    def elevation(self, x, y):
        return self.blk[y * self.w + x] >> 12

    def passable(self, x, y):
        if not (0 <= x < self.w and 0 <= y < self.h):
            return False
        if (self.blk[y * self.w + x] >> 10) & 3:
            return False
        return self.behavior_name(x, y) not in WATER_MB

    def bfs(self, start):
        dist = {start: 0}
        q = deque([start])
        while q:
            x, y = q.popleft()
            for dx, dy in ((1, 0), (-1, 0), (0, 1), (0, -1)):
                n = (x + dx, y + dy)
                if n not in dist and self.passable(*n):
                    dist[n] = dist[(x, y)] + 1
                    q.append(n)
        return dist


def pick_npcs(c):
    lay = Layout(c["layout"])
    ax, ay = c["center"][0], c["center"][1] + 1
    assert lay.passable(ax, ay), (c["name"], "arrival not passable")
    dist = lay.bfs((ax, ay))
    for k in ("gym", "mart"):
        gx, gy = c[k]
        assert (gx, gy + 1) in dist, (c["name"], k, "unreachable")
    reserved = set()
    for k in ("gym", "mart", "center"):
        gx, gy = c[k]
        for dx in (-1, 0, 1):
            for dy in (-1, 0, 1, 2):
                reserved.add((gx + dx, gy + dy))
    for k in ("gym_sign", "town_sign"):
        reserved.add(tuple(c[k]))
        reserved.add((c[k][0], c[k][1] + 1))
    elev = lay.elevation(ax, ay)

    def ok(p):
        return (p in dist and p not in reserved and p != (ax, ay)
                and lay.behavior_name(*p) == "MB_NORMAL" and lay.elevation(*p) == elev)

    att = None
    cands = sorted(((abs(p[0] - ax) + abs(p[1] - ay), abs(p[1] - ay), p) for p in dist if ok(p)))
    for md, _, p in cands:
        if 2 <= md <= 5:
            dx, dy = p[0] - ax, p[1] - ay
            mv = ("MOVEMENT_TYPE_FACE_RIGHT" if dx < 0 else "MOVEMENT_TYPE_FACE_LEFT") if dx else (
                "MOVEMENT_TYPE_FACE_DOWN" if dy < 0 else "MOVEMENT_TYPE_FACE_UP")
            att = (p, mv)
            break
    assert att, (c["name"], "no attendant tile")
    girl = None
    for p, d in sorted(dist.items(), key=lambda kv: (kv[1], kv[0])):
        if 5 <= d <= 14 and ok(p) and p != att[0] and abs(p[0] - att[0][0]) + abs(p[1] - att[0][1]) > 3:
            girl = p
            break
    assert girl, (c["name"], "no girl tile")
    return (ax, ay), elev, att, girl


# --------------------------------------------------------------------------------------
# Writers
# --------------------------------------------------------------------------------------
def j(obj):
    return json.dumps(obj, indent=2, ensure_ascii=False) + "\n"


def split_str(s):
    """Break a single .string literal into one .string line per \\n / \\l / \\p chunk."""
    return re.sub(r'(\\[nlp])', lambda m: m.group(1) + '"\n\t.string "', s)


def obj(gfx, x, y, elev, mv, script, rx=0, ry=0, local_id=None, flag="0"):
    o = {}
    if local_id:
        o["local_id"] = local_id
    o.update({
        "graphics_id": gfx, "x": x, "y": y, "elevation": elev, "movement_type": mv,
        "movement_range_x": rx, "movement_range_y": ry, "trainer_type": "TRAINER_TYPE_NONE",
        "trainer_sight_or_berry_tree_id": "0", "script": script, "flag": flag})
    return o


def warp(x, y, dest, wid, elev=0):
    return {"x": x, "y": y, "elevation": elev, "dest_map": dest, "dest_warp_id": str(wid)}


def sign(x, y, script, facing="BG_EVENT_PLAYER_FACING_ANY"):
    return {"type": "sign", "x": x, "y": y, "elevation": 0, "player_facing_dir": facing, "script": script}


def clone_interior(c, tmpl_city, kind, subs):
    """Clone ObsidianCity_<kind>/map.json + scripts.inc with string substitutions."""
    for fn in ("map.json", "scripts.inc"):
        t = rd(f"{MAPS}/{tmpl_city}_{kind}/{fn}")
        for a, b in subs:
            t = t.replace(a, b)
        wr(f"{MAPS}/{c['name']}_{kind}/{fn}", t)


def gen_city(c, hall_texts):
    n = c["name"]
    CN = c["const"]
    (ax, ay), elev, (att_pos, att_mv), girl_pos = pick_npcs(c)
    c["arrival"] = (ax, ay)
    cx, cy = c["center"]
    gx, gy = c["gym"]
    mx, my = c["mart"]

    # ---- outdoor map.json
    lid = CN.split("_")[0]  # short LOCALID stem (LOCALID_MIRAGE_NURSE style)
    c["lid"] = lid
    outdoor = {
        "id": f"MAP_{CN}", "name": n, "layout": c["layout"], "music": c["music"], "region": "REGION_HOENN",
        "region_map_section": f"MAPSEC_{CN}", "requires_flash": False, "weather": "WEATHER_SUNNY",
        "map_type": "MAP_TYPE_TOWN", "allow_cycling": True, "allow_escaping": False, "allow_running": True,
        "show_map_name": True, "battle_scene": "MAP_BATTLE_SCENE_NORMAL", "connections": None,
        "object_events": [
            obj("OBJ_EVENT_GFX_GIRL_3", girl_pos[0], girl_pos[1], elev, "MOVEMENT_TYPE_FACE_LEFT", f"{n}_EventScript_Girl"),
            obj("OBJ_EVENT_GFX_TEALA", att_pos[0], att_pos[1], elev, att_mv, f"{n}_EventScript_TransitAttendant"),
        ],
        "warp_events": [
            warp(gx, gy, f"MAP_{CN}_GYM", 0),
            warp(cx, cy, f"MAP_{CN}_POKEMON_CENTER_1F", 0),
            warp(mx, my, f"MAP_{CN}_MART", 0),
        ],
        "coord_events": [],
        "bg_events": [
            sign(*c["town_sign"], f"{n}_EventScript_TownSign"),
            sign(*c["gym_sign"], f"{n}_EventScript_GymSign"),
            sign(cx + 1, cy, "Common_EventScript_ShowPokemonCenterSign", "BG_EVENT_PLAYER_FACING_NORTH"),
            sign(mx + 2, my, "Common_EventScript_ShowPokemartSign", "BG_EVENT_PLAYER_FACING_NORTH"),
            sign(cx + 2, cy, "Common_EventScript_ShowPokemonCenterSign", "BG_EVENT_PLAYER_FACING_NORTH"),
            sign(mx + 1, my, "Common_EventScript_ShowPokemartSign", "BG_EVENT_PLAYER_FACING_NORTH"),
        ],
    }
    # Sign tiles on top of door-adjacent metatiles are the vanilla sign positions; use them where they exist.
    wr(f"{MAPS}/{n}/map.json", j(outdoor))

    lead = c["leader"]
    pro_obj, pro_sub = c["pronoun"]
    badge = c["badge"]
    prev_flag = f"FLAG_GENESIS_BADGE_{c['prev_badge']:02d}_GET"
    flag = f"FLAG_GENESIS_BADGE_{badge:02d}_GET"
    remaining = 18 - badge
    more_text = (f"{['Zero','One','Two','Three','Four','Five','Six','Seven','Eight','Nine'][remaining]} more desks wait in EASTERN\\nAURELIA HALL."
                 if remaining > 0 else "All eighteen badges are yours!\\nThe EASTERN AURELIA HALL clerk\\lhas a reward for you.")
    T = c["townmon"]

    # ---- outdoor scripts.inc
    sc = f"""@ {c['disp']} -- {c['type'].title()} / {lead} / Badge {badge}. Layout-clone stub ({c['layout']}).
@ Entered from the Eastern AURELIA HALL {c['short']} desk; the Transit Attendant warps back.

{n}_MapScripts::
	.byte 0

{n}_EventScript_TownSign::
	msgbox {n}_Text_TownSign, MSGBOX_SIGN
	end

{n}_EventScript_GymSign::
	msgbox {n}_Text_GymSign, MSGBOX_SIGN
	end

@ Town totem quest ({T.upper()}) -- unlocks once {lead} has granted the {c['badge_name']}
{n}_EventScript_Girl::
	goto_if_set {flag}, Genesis_EventScript_TownMon_{T}
	lock
	faceplayer
	msgbox {n}_Text_GirlNoBadge, MSGBOX_DEFAULT
	release
	end

{n}_EventScript_TransitAttendant::
	lock
	faceplayer
	msgbox {n}_Text_AttendantAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, {n}_EventScript_AttendantStay
	msgbox {n}_Text_AttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 1, 6
	waitstate
	release
	end

{n}_EventScript_AttendantStay::
	msgbox {n}_Text_AttendantStay, MSGBOX_DEFAULT
	release
	end

{n}_Text_TownSign:
	.string "{c['disp']}\\n"
	.string "“{c['sign_tag']}”$"

{n}_Text_GymSign:
	.string "{c['disp']} POKéMON GYM\\n"
	.string "LEADER: {lead}\\l"
	.string "“{c['gym_tag']}”$"

{n}_Text_GirlNoBadge:
	.string "{c['girl']}$"

{n}_Text_AttendantAsk:
	.string "EASTERN AURELIA transit desk.\\nReturn to the EASTERN AURELIA HALL?$"

{n}_Text_AttendantWarp:
	.string "{c['transport_text']}$"

{n}_Text_AttendantStay:
	.string "{c['attendant_stay']}$"
"""
    wr(f"{MAPS}/{n}/scripts.inc", sc)

    # ---- Center 1F / 2F, Mart: clone from ObsidianCity
    subs = [("LOCALID_OBSIDIAN_", f"LOCALID_{lid}_"), ("ObsidianCity", n), ("OBSIDIAN_CITY", CN)]
    clone_interior(c, "ObsidianCity", "PokemonCenter_1F", subs)
    clone_interior(c, "ObsidianCity", "PokemonCenter_2F", subs)
    clone_interior(c, "ObsidianCity", "Mart", subs)
    mart_items = ("\t.2byte ITEM_ULTRA_BALL\n\t.2byte ITEM_HYPER_POTION\n\t.2byte ITEM_MAX_POTION\n\t.2byte ITEM_FULL_HEAL\n"
                  "\t.2byte ITEM_REVIVE\n\t.2byte ITEM_MAX_REVIVE\n\t.2byte ITEM_SUPER_REPEL\n\t.2byte ITEM_MAX_REPEL\n")
    mp = f"{MAPS}/{n}_Mart/scripts.inc"
    t = rd(mp)
    t = re.sub(r'(_Text_TypeSupplies:\n\t\.string ")[^\n]*', lambda m: m.group(1) + c["mart_woman"] + '$"', t)
    t = t.replace("OBSIDIAN MART", f"{c['disp'].replace(' CITY', '')} MART")
    if c["mart_late"]:
        t = re.sub(r"\t\.2byte ITEM_GREAT_BALL\n.*?\tpokemartlistend", lambda m: mart_items + "\tpokemartlistend", t, flags=re.S)
    wr(mp, t)

    # ---- Gym: clone and swap leader specifics
    gm = rd(f"{MAPS}/ObsidianCity_Gym/map.json")
    gm = gm.replace("ObsidianCity", n).replace("OBSIDIAN_CITY", CN).replace("OBJ_EVENT_GFX_MAN_3", c["gfx"])
    gm = gm.replace("Noctis", c["Leader"])
    wr(f"{MAPS}/{n}_Gym/map.json", gm)

    ht = hall_texts
    L = c["Leader"]
    intro = ht[f"{L}Intro"].replace("AURELIA SUMMIT--ROCK desk.", "SUMMIT CITY GYM--ROCK.").replace(" desk", " GYM")
    defeat = ht[f"{L}Defeat"]
    after = ht[f"{L}After"]
    done = ht[f"{L}Done"]
    got = ht[c["badge_label"]]
    need_prev = ht[f"Need{PREV_NEED[badge]}"].replace(" desk", " GYM")
    decline = ht["Decline"]
    tera_flags = "\tsetflag FLAG_GENESIS_TERA_UNLOCKED\n\tsetflag FLAG_SYS_TERA_ORB_CHARGED\n" if c["tera"] else ""
    story = "\tsetvar VAR_GENESIS_STORY_STATE, GENESIS_STORY_EASTERN_DONE\n" if badge == 16 else ""
    trainer = c["trainer"]
    g = f"{n}_Gym"
    tera_note = " (Tera unlock stays here on DRAKE's win)" if c["tera"] else ""
    gs = f"""@ {c['disp']} GYM -- {c['type'].title()} / {lead} / Badge {badge} (moved from EasternAurelia_Hall desk).
@ Needs the previous badge ({c['prev_leader']}){tera_note}.

{g}_MapScripts::
	.byte 0

{g}_EventScript_{L}::
	lock
	faceplayer
	goto_if_unset {prev_flag}, {g}_EventScript_NeedPrev
	goto_if_set {flag}, {g}_EventScript_{L}Done
	msgbox {g}_Text_{L}Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, {g}_EventScript_Decline
	trainerbattle_no_intro {trainer}, {g}_Text_{L}Defeat
	message {g}_Text_{c['badge_label']}
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag {flag}
{tera_flags}{story}	call Genesis_EventScript_UpdateLevelCap
	msgbox {g}_Text_{L}After, MSGBOX_DEFAULT
	release
	end

{g}_EventScript_{L}Done::
	msgbox {g}_Text_{L}Done, MSGBOX_DEFAULT
	release
	end

{g}_EventScript_NeedPrev::
	msgbox {g}_Text_NeedPrev, MSGBOX_DEFAULT
	release
	end

{g}_EventScript_Decline::
	msgbox {g}_Text_Decline, MSGBOX_DEFAULT
	release
	end

{g}_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set {flag}, {g}_EventScript_GymGuidePostVictory
	msgbox {g}_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

{g}_EventScript_GymGuidePostVictory::
	msgbox {g}_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

{g}_EventScript_LeftGymStatue::
	lockall
	goto_if_set {flag}, {g}_EventScript_GymStatueCertified
	goto {g}_EventScript_GymStatue
	end

{g}_EventScript_RightGymStatue::
	lockall
	goto_if_set {flag}, {g}_EventScript_GymStatueCertified
	goto {g}_EventScript_GymStatue
	end

{g}_EventScript_GymStatueCertified::
	msgbox {g}_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

{g}_EventScript_GymStatue::
	msgbox {g}_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

{g}_Text_Decline:
{decline}

{g}_Text_NeedPrev:
{need_prev}

{g}_Text_{L}Intro:
{intro}

{g}_Text_{L}Defeat:
{defeat}

{g}_Text_{c['badge_label']}:
{got}

{g}_Text_{L}After:
{after}

{g}_Text_{L}Done:
{done}

{g}_Text_GymGuideAdvice:
	.string "Yo! Welcome to {c['disp']} GYM!\\p"
	.string "{lead} uses {c['type']}-type POKéMON.\\p"
	.string "{c['guide']}\\p"
	.string "Go get that {c['badge_name']}!$"

{g}_Text_GymGuidePostVictory:
	.string "Nice work!\\n"
	.string "The {c['badge_name']} is yours!\\p"
	.string "{more_text}$"

{g}_Text_GymStatue:
	.string "{c['disp']} POKéMON GYM$"

{g}_Text_GymStatueCertified:
	.string "{c['disp']} POKéMON GYM\\p"
	.string "{lead}'S CERTIFIED TRAINERS:\\n"
	.string "{{PLAYER}}$"
"""
    wr(f"{MAPS}/{g}/scripts.inc", gs)


def read_hall_texts(hall):
    texts = {}
    for m in re.finditer(r"^EasternAurelia_Hall_Text_(\w+):\n((?:\t\.string [^\n]*\n)+)", hall, re.M):
        texts[m.group(1)] = m.group(2).rstrip("\n")
    return texts


# --------------------------------------------------------------------------------------
# Hall rewrite
# --------------------------------------------------------------------------------------
def rewrite_hall(cities):
    p = f"{MAPS}/EasternAurelia_Hall/scripts.inc"
    t = rd(p)
    if "AstralWarpAsk" in t:
        print("Hall already rewritten; skipping")
        return
    for c in cities:
        L, lead, n = c["Leader"], c["leader"], c["name"]
        badge, short = c["badge"], HALL_DESK[n]
        flag = f"FLAG_GENESIS_BADGE_{badge:02d}_GET"
        prev_flag = f"FLAG_GENESIS_BADGE_{c['prev_badge']:02d}_GET"
        need = PREV_NEED[badge]
        ax, ay = c["arrival"]
        key = c["short"] if c["short"] != "GenesisCity" else "Genesis"
        warp = f"{key}Warp"  # label stem used for ask / stay
        ask = f"EasternAurelia_Hall_EventScript_{key}WarpAsk"
        stay = f"EasternAurelia_Hall_EventScript_{key}Stay"
        # NPC block
        npc_re = re.compile(
            rf"EasternAurelia_Hall_EventScript_{L}::\n.*?(?=EasternAurelia_Hall_EventScript_{L}Done::)", re.S)
        assert npc_re.search(t), L
        npc = f"""@ Badge {badge} battle lives in {n}_Gym; the Hall NPC + desk just warp there.
EasternAurelia_Hall_EventScript_{L}::
	lock
	faceplayer
	goto_if_unset {prev_flag}, EasternAurelia_Hall_EventScript_Need{need}
	goto_if_set {flag}, EasternAurelia_Hall_EventScript_{L}Done
	msgbox EasternAurelia_Hall_Text_{L}Redirect, MSGBOX_DEFAULT
	goto {ask}
	end

{ask}::
	msgbox EasternAurelia_Hall_Text_{key}WarpAsk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, {stay}
	msgbox EasternAurelia_Hall_Text_{key}Warp, MSGBOX_DEFAULT
	warpsilent MAP_{c['const']}, {ax}, {ay}
	waitstate
	releaseall
	end

{stay}::
	msgbox EasternAurelia_Hall_Text_{key}Stay, MSGBOX_DEFAULT
	releaseall
	end

"""
        t = npc_re.sub(lambda m: npc, t, count=1)

        # Desk block (DeskX:: ... end)
        desk_name = {"Astral": "Astral", "Tidymoon": "Tidymoon", "Eon": "Eon", "Genesis": "Genesis",
                     "Summit": "Summit", "Venom": "Venom", "Terracotta": "Terracotta"}[key]
        desk_re = re.compile(
            rf"EasternAurelia_Hall_EventScript_Desk{desk_name}::\n.*?\n\tend\n", re.S)
        assert desk_re.search(t), desk_name
        desk = f"""EasternAurelia_Hall_EventScript_Desk{desk_name}::
	lockall
	msgbox EasternAurelia_Hall_Text_Desk{desk_name}, MSGBOX_DEFAULT
	goto_if_unset {prev_flag}, EasternAurelia_Hall_EventScript_DeskNeed{need}
	goto {ask}
	end
"""
        t = desk_re.sub(lambda m: desk, t, count=1)

        # Texts: replace Intro..After run with Redirect/WarpAsk/Warp/Stay
        text_re = re.compile(
            rf"EasternAurelia_Hall_Text_{L}Intro:\n.*?(?=EasternAurelia_Hall_Text_{L}Done:)", re.S)
        assert text_re.search(t), L
        redirect_line = f"{lead}: My GYM is in {c['disp']}."
        new_texts = f"""EasternAurelia_Hall_Text_{L}Redirect:
	.string "{redirect_line}\\n"
	.string "{c['flavor']}\\p"
	.string "The {c['transport']} can take you there.$"

EasternAurelia_Hall_Text_{key}WarpAsk:
	.string "Travel to {c['disp']}?$"

EasternAurelia_Hall_Text_{key}Warp:
	.string "{split_str(c['transport_text'])}$"

EasternAurelia_Hall_Text_{key}Stay:
	.string "{split_str(c['stay_text'])}$"

"""
        t = text_re.sub(lambda m: new_texts, t, count=1)

    # DeskNeed helpers (releaseall variants) for desks that did not have one
    helpers = ""
    for need in ("Noctis", "Drake", "Luna", "Morrigan", "Colleague", "Mentor", "Vesper"):
        helpers += f"""EasternAurelia_Hall_EventScript_DeskNeed{need}::
	msgbox EasternAurelia_Hall_Text_Need{need}, MSGBOX_DEFAULT
	releaseall
	end

"""
    anchor = "EasternAurelia_Hall_EventScript_DeskAstral::"
    t = t.replace(anchor, helpers + anchor, 1)
    t = t.replace("@ Desk plaques (bg signs) — stand-in city labels until full maps exist",
                  "@ Desk plaques (bg signs) — read the blurb, then offer the warp once the previous badge is held.", 1)
    wr(p, t)


# --------------------------------------------------------------------------------------
# Registries
# --------------------------------------------------------------------------------------
def insert_after(text, anchor, addition):
    assert anchor in text, anchor
    return text.replace(anchor, anchor + addition, 1)


def update_registries(cities):
    # event_scripts.s
    p = "data/event_scripts.s"
    t = rd(p)
    add = ""
    for c in cities:
        n = c["name"]
        add += (f'\t.include "data/maps/{n}/scripts.inc"\n'
                f'\t.include "data/maps/{n}_PokemonCenter_1F/scripts.inc"\n'
                f'\t.include "data/maps/{n}_PokemonCenter_2F/scripts.inc"\n'
                f'\t.include "data/maps/{n}_Mart/scripts.inc"\n'
                f'\t.include "data/maps/{n}_Gym/scripts.inc"\n')
    t = insert_after(t, '\t.include "data/maps/ObsidianCity_Gym/scripts.inc"\n', add)
    wr(p, t)

    # map_groups.json
    p = "data/maps/map_groups.json"
    mg = json.loads(rd(p))
    for c in cities:
        grp = f"gMapGroup_Indoor{c['name']}"
        mg["group_order"].append(grp)
        mg[grp] = [f"{c['name']}_PokemonCenter_1F", f"{c['name']}_PokemonCenter_2F", f"{c['name']}_Mart", f"{c['name']}_Gym"]
        mg["gMapGroup_TownsAndRoutes"].append(c["name"])
    wr(p, j(mg))

    # heal_locations.json
    p = "src/data/heal_locations.json"
    hl = json.loads(rd(p))
    key = [k for k, v in hl.items() if isinstance(v, list)][0]
    for c in cities:
        hl[key].append({
            "id": f"HEAL_LOCATION_{c['const']}", "map": f"MAP_{c['const']}", "x": c["arrival"][0], "y": c["arrival"][1],
            "respawn_map": f"MAP_{c['const']}_POKEMON_CENTER_1F", "respawn_npc": f"LOCALID_{c['lid']}_NURSE"})
    wr(p, j(hl))

    # region_map_sections.json (text insert, file is not byte-stable through json)
    p = "src/data/region_map/region_map_sections.json"
    t = rd(p)
    block = ""
    for c in cities:
        block += f',\n    {{\n      "id": "MAPSEC_{c["const"]}",\n      "name": "{c["disp"]}"\n    }}'
    anchor = '      "id": "MAPSEC_OBSIDIAN_CITY",\n      "name": "OBSIDIAN CITY"\n    }'
    t = insert_after(t, anchor, block)
    wr(p, t)

    # map_name_popup.c
    p = "src/map_name_popup.c"
    t = rd(p)
    a1 = "    [MAPSEC_OBSIDIAN_CITY - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_STONE,\n"
    a2 = "    [MAPSEC_OBSIDIAN_CITY - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BW_DEFAULT,\n"
    t = insert_after(t, a1, "".join(f"    [MAPSEC_{c['const']} - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_{c['theme']},\n" for c in cities))
    t = insert_after(t, a2, "".join(f"    [MAPSEC_{c['const']} - KANTO_MAPSEC_COUNT] = MAPPOPUP_THEME_BW_DEFAULT,\n" for c in cities))
    wr(p, t)


def main():
    hall = rd(f"{MAPS}/EasternAurelia_Hall/scripts.inc")
    if "AstralWarpAsk" in hall:
        print("Hall already rewritten -- aborting (generator is one-shot).")
        sys.exit(1)
    hall_texts = read_hall_texts(hall)
    for c in CITIES:
        if os.path.exists(f"{MAPS}/{c['name']}/map.json"):
            print("exists, aborting:", c["name"])
            sys.exit(1)
    for c in CITIES:
        gen_city(c, hall_texts)
        print(c["name"], "arrival", c["arrival"])
    rewrite_hall(CITIES)
    update_registries(CITIES)


if __name__ == "__main__":
    main()
