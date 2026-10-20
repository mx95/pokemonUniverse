#!/usr/bin/env python3
"""GENESIS: Scaffold eastern cities 10–16 + World Tournament lobby.

Idempotent: safe to re-run. Creates map folders, registers layouts/map groups/
MAPSEC/heals/trainers, rewrites Hall desks to warps, and builds layout bins.

Usage (repo root):
  python3 tools/genesis/scaffold_eastern_cities.py
"""

from __future__ import annotations

import json
import re
import subprocess
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]

CITIES = [
    {
        "folder": "VerdantisCity",
        "mapsec": "MAPSEC_VERDANTIS_CITY",
        "mapsec_name": "VERDANTIS CITY",
        "display": "VERDANTIS CITY",
        "tagline": "“Canopy and buzz.”",
        "leader": "CELIA",
        "leader_key": "Celia",
        "trainer": "TRAINER_GENESIS_CELIA",
        "badge_flag": "FLAG_GENESIS_BADGE_10_GET",
        "badge_name": "JUNGLE BADGE",
        "type_word": "BUG",
        "type_advice": "BUG-type POKéMON.\\pThey're strong against GRASS, PSYCHIC,\\nand DARK, but watch for FIRE, FLYING,\\land ROCK moves.",
        "prev_flag": "FLAG_GENESIS_BADGE_09_GET",
        "prev_need": "NeedIris",
        "hall_key": "Celia",
        "desk_key": "Verdantis",
        "music": "MUS_VERDANTURF",
        "leader_gfx": "OBJ_EVENT_GFX_ROXANNE",
        "minion_class": "Bug Catcher",
        "minion_pic": "Bug Catcher",
        "minion_gfx": ["OBJ_EVENT_GFX_BUG_CATCHER", "OBJ_EVENT_GFX_LASS", "OBJ_EVENT_GFX_YOUNGSTER"],
        "prefix": "VERDANTIS",
        "x": 22,
        "y": 12,
        "extra_badge": "",
        "levels": (54, 54, 55),
        "parties": [
            ("Weedle", "Poison Sting / String Shot / Tackle / Harden"),
            ("Beautifly", "Bug Buzz / Giga Drain / Quiver Dance / Psychic"),
            ("Heracross", "Megahorn / Brick Break / Aerial Ace / Swords Dance"),
        ],
    },
    {
        "folder": "ObsidianCity",
        "mapsec": "MAPSEC_OBSIDIAN_CITY",
        "mapsec_name": "OBSIDIAN CITY",
        "display": "OBSIDIAN CITY",
        "tagline": "“Glass streets, quiet night.”",
        "leader": "NOCTIS",
        "leader_key": "Noctis",
        "trainer": "TRAINER_GENESIS_NOCTIS",
        "badge_flag": "FLAG_GENESIS_BADGE_11_GET",
        "badge_name": "OBSIDIAN BADGE",
        "type_word": "DARK",
        "type_advice": "DARK-type POKéMON.\\pThey're strong against PSYCHIC and\\nGHOST, but watch for FIGHTING, BUG,\\land FAIRY moves.",
        "prev_flag": "FLAG_GENESIS_BADGE_10_GET",
        "prev_need": "NeedCelia",
        "hall_key": "Noctis",
        "desk_key": "Obsidian",
        "music": "MUS_FALLARBOR",
        "leader_gfx": "OBJ_EVENT_GFX_SIDNEY",
        "minion_class": "Cooltrainer",
        "minion_pic": "Cooltrainer M",
        "minion_gfx": ["OBJ_EVENT_GFX_MAN_3", "OBJ_EVENT_GFX_WOMAN_5", "OBJ_EVENT_GFX_MAN_5"],
        "prefix": "OBSIDIAN",
        "x": 23,
        "y": 12,
        "extra_badge": "",
        "levels": (55, 55, 56),
        "parties": [
            ("Poochyena", "Bite / Howl / Sand Attack / Tackle"),
            ("Mightyena", "Crunch / Take Down / Swagger / Scary Face"),
            ("Absol", "Night Slash / Slash / Swords Dance / Quick Attack"),
        ],
    },
    {
        "folder": "AstralCity",
        "mapsec": "MAPSEC_ASTRAL_CITY",
        "mapsec_name": "ASTRAL CITY",
        "display": "ASTRAL CITY",
        "tagline": "“Where dragons chart the sky.”",
        "leader": "DRAKE",
        "leader_key": "Drake",
        "trainer": "TRAINER_GENESIS_DRAKE_GYM",
        "badge_flag": "FLAG_GENESIS_BADGE_12_GET",
        "badge_name": "ASTRAL BADGE",
        "type_word": "DRAGON",
        "type_advice": "DRAGON-type POKéMON.\\pThey're strong against other DRAGONS\\nin a clash, but watch for ICE,\\nDRAGON, and FAIRY moves.\\pWin here to unlock TERASTALLIZATION!",
        "prev_flag": "FLAG_GENESIS_BADGE_11_GET",
        "prev_need": "NeedNoctis",
        "hall_key": "Drake",
        "desk_key": "Astral",
        "music": "MUS_FORTREE",
        "leader_gfx": "OBJ_EVENT_GFX_DRAKE",
        "minion_class": "Dragon Tamer",
        "minion_pic": "Dragon Tamer",
        "minion_gfx": ["OBJ_EVENT_GFX_MAN_3", "OBJ_EVENT_GFX_MAN_4", "OBJ_EVENT_GFX_EXPERT_M"],
        "prefix": "ASTRAL",
        "x": 24,
        "y": 12,
        "extra_badge": (
            "\tsetflag FLAG_GENESIS_TERA_UNLOCKED\n"
            "\tsetflag FLAG_SYS_TERA_ORB_CHARGED\n"
        ),
        "levels": (56, 56, 57),
        "parties": [
            ("Bagon", "Dragon Breath / Headbutt / Bite / Ember"),
            ("Shelgon", "Dragon Claw / Zen Headbutt / Crunch / Protect"),
            ("Flygon", "Dragon Claw / Earthquake / Rock Slide / Crunch"),
        ],
    },
    {
        "folder": "TidymoonCity",
        "mapsec": "MAPSEC_TIDYMOON_CITY",
        "mapsec_name": "TIDYMOON CITY",
        "display": "TIDYMOON CITY",
        "tagline": "“Tide pools under soft light.”",
        "leader": "LUNA",
        "leader_key": "Luna",
        "trainer": "TRAINER_GENESIS_LUNA",
        "badge_flag": "FLAG_GENESIS_BADGE_13_GET",
        "badge_name": "MOON BADGE",
        "type_word": "FAIRY",
        "type_advice": "FAIRY-type POKéMON.\\pThey're strong against FIGHTING,\\nDRAGON, and DARK, but watch for\\nPOISON and STEEL moves.",
        "prev_flag": "FLAG_GENESIS_BADGE_12_GET",
        "prev_need": "NeedDrake",
        "hall_key": "Luna",
        "desk_key": "Tidymoon",
        "music": "MUS_DEWFORD",
        "leader_gfx": "OBJ_EVENT_GFX_LIZA",
        "minion_class": "Lass",
        "minion_pic": "Lass",
        "minion_gfx": ["OBJ_EVENT_GFX_LASS", "OBJ_EVENT_GFX_GIRL_1", "OBJ_EVENT_GFX_WOMAN_2"],
        "prefix": "TIDYMOON",
        "x": 22,
        "y": 13,
        "extra_badge": "",
        "levels": (57, 57, 58),
        "parties": [
            ("Cleffa", "Charm / Sing / Sweet Kiss / Magical Leaf"),
            ("Clefairy", "Moonblast / Cosmic Power / Recover / Metronome"),
            ("Gardevoir", "Moonblast / Psychic / Calm Mind / Thunderbolt"),
        ],
    },
    {
        "folder": "EonCity",
        "mapsec": "MAPSEC_EON_CITY",
        "mapsec_name": "EON CITY",
        "display": "EON CITY",
        "tagline": "“Where spirits linger between eras.”",
        "leader": "MORRIGAN",
        "leader_key": "Morrigan",
        "trainer": "TRAINER_GENESIS_MORRIGAN",
        "badge_flag": "FLAG_GENESIS_BADGE_14_GET",
        "badge_name": "EON BADGE",
        "type_word": "GHOST",
        "type_advice": "GHOST-type POKéMON.\\pThey're strong against PSYCHIC and\\nGHOST, but watch for DARK and\\nGHOST moves in return.",
        "prev_flag": "FLAG_GENESIS_BADGE_13_GET",
        "prev_need": "NeedLuna",
        "hall_key": "Morrigan",
        "desk_key": "Eon",
        "music": "MUS_MT_PYRE",
        "leader_gfx": "OBJ_EVENT_GFX_PHOEBE",
        "minion_class": "Psychic",
        "minion_pic": "Psychic F",
        "minion_gfx": ["OBJ_EVENT_GFX_HEX_MANIAC", "OBJ_EVENT_GFX_PSYCHIC_M", "OBJ_EVENT_GFX_WOMAN_2"],
        "prefix": "EON",
        "x": 23,
        "y": 13,
        "extra_badge": "",
        "levels": (58, 58, 59),
        "parties": [
            ("Gastly", "Shadow Ball / Hypnosis / Curse / Night Shade"),
            ("Haunter", "Shadow Ball / Psychic / Curse / Confuse Ray"),
            ("Banette", "Shadow Ball / Thunderbolt / Will-O-Wisp / Knock Off"),
        ],
    },
    {
        "folder": "GenesisCity",
        "mapsec": "MAPSEC_GENESIS_CITY",
        "mapsec_name": "GENESIS CITY",
        "display": "GENESIS CITY",
        "tagline": "“Prep hub of Eastern Aurelia.”",
        "leader": "COLLEAGUE",
        "leader_key": "Colleague",
        "trainer": "TRAINER_GENESIS_COLLEAGUE",
        "badge_flag": "FLAG_GENESIS_BADGE_15_GET",
        "badge_name": "GENESIS BADGE",
        "type_word": "MIXED",
        "type_advice": "mixed teams--no single type owns\\nthis city. Bring coverage and\\nstatus answers.",
        "prev_flag": "FLAG_GENESIS_BADGE_14_GET",
        "prev_need": "NeedMorrigan",
        "hall_key": "Colleague",
        "desk_key": "Genesis",
        "music": "MUS_SLATEPORT",
        "leader_gfx": "OBJ_EVENT_GFX_MAXIE",
        "minion_class": "Cooltrainer",
        "minion_pic": "Cooltrainer F",
        "minion_gfx": ["OBJ_EVENT_GFX_WOMAN_5", "OBJ_EVENT_GFX_MAN_3", "OBJ_EVENT_GFX_SCIENTIST_1"],
        "prefix": "GENESISCITY",
        "x": 24,
        "y": 13,
        "extra_badge": "",
        "levels": (59, 59, 60),
        "parties": [
            ("Magneton", "Thunderbolt / Tri Attack / Thunder Wave / Supersonic"),
            ("Milotic", "Surf / Ice Beam / Recover / Toxic"),
            ("Garchomp", "Earthquake / Dragon Claw / Crunch / Swords Dance"),
        ],
    },
    {
        "folder": "SummitCity",
        "mapsec": "MAPSEC_SUMMIT_CITY",
        "mapsec_name": "SUMMIT CITY",
        "display": "AURELIA SUMMIT",
        "tagline": "“Not a throne. A threshold.”",
        "leader": "MENTOR",
        "leader_key": "Mentor",
        "trainer": "TRAINER_GENESIS_MENTOR",
        "badge_flag": "FLAG_GENESIS_BADGE_16_GET",
        "badge_name": "ASCENSION BADGE",
        "type_word": "MIXED",
        "type_advice": "the full toolkit you've forged\\nacross Aurelia. Bring everything.",
        "prev_flag": "FLAG_GENESIS_BADGE_15_GET",
        "prev_need": "NeedColleague",
        "hall_key": "Mentor",
        "desk_key": "Summit",
        "music": "MUS_EVER_GRANDE",
        "leader_gfx": "OBJ_EVENT_GFX_STEVEN",
        "minion_class": "Cooltrainer",
        "minion_pic": "Cooltrainer M",
        "minion_gfx": ["OBJ_EVENT_GFX_MAN_3", "OBJ_EVENT_GFX_EXPERT_M", "OBJ_EVENT_GFX_MAN_5"],
        "prefix": "SUMMIT",
        "x": 25,
        "y": 12,
        "extra_badge": "\tsetvar VAR_GENESIS_STORY_STATE, GENESIS_STORY_EASTERN_DONE\n",
        "levels": (60, 60, 61),
        "parties": [
            ("Metang", "Meteor Mash / Psychic / Pursuit / Agility"),
            ("Aggron", "Iron Tail / Earthquake / Rock Slide / Protect"),
            ("Metagross", "Meteor Mash / Earthquake / Psychic / Agility"),
        ],
    },
]


def write(path: Path, text: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(text, encoding="utf-8")


def city_map_json(c: dict) -> str:
    folder = c["folder"]
    map_id = camel_to_map(folder)
    return json.dumps(
        {
            "id": map_id,
            "name": folder,
            "layout": layout_id(folder),
            "music": c["music"],
            "region": "REGION_HOENN",
            "region_map_section": c["mapsec"],
            "requires_flash": False,
            "weather": "WEATHER_SUNNY",
            "map_type": "MAP_TYPE_CITY",
            "allow_cycling": True,
            "allow_escaping": False,
            "allow_running": True,
            "show_map_name": True,
            "battle_scene": "MAP_BATTLE_SCENE_NORMAL",
            "connections": None,
            "object_events": [
                {
                    "graphics_id": "OBJ_EVENT_GFX_GIRL_1",
                    "x": 6,
                    "y": 11,
                    "elevation": 3,
                    "movement_type": "MOVEMENT_TYPE_FACE_RIGHT",
                    "movement_range_x": 0,
                    "movement_range_y": 1,
                    "trainer_type": "TRAINER_TYPE_NONE",
                    "trainer_sight_or_berry_tree_id": "0",
                    "script": f"{folder}_EventScript_Girl",
                    "flag": "0",
                },
                {
                    "graphics_id": "OBJ_EVENT_GFX_EXPERT_M",
                    "x": 10,
                    "y": 8,
                    "elevation": 3,
                    "movement_type": "MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT",
                    "movement_range_x": 1,
                    "movement_range_y": 0,
                    "trainer_type": "TRAINER_TYPE_NONE",
                    "trainer_sight_or_berry_tree_id": "0",
                    "script": f"{folder}_EventScript_ExpertM",
                    "flag": "0",
                },
                {
                    "graphics_id": "OBJ_EVENT_GFX_GENTLEMAN",
                    "x": 12,
                    "y": 16,
                    "elevation": 3,
                    "movement_type": "MOVEMENT_TYPE_WANDER_UP_AND_DOWN",
                    "movement_range_x": 1,
                    "movement_range_y": 1,
                    "trainer_type": "TRAINER_TYPE_NONE",
                    "trainer_sight_or_berry_tree_id": "0",
                    "script": f"{folder}_EventScript_Gentleman",
                    "flag": "0",
                },
                {
                    "graphics_id": "OBJ_EVENT_GFX_TEALA",
                    "x": 5,
                    "y": 17,
                    "elevation": 3,
                    "movement_type": "MOVEMENT_TYPE_FACE_DOWN",
                    "movement_range_x": 0,
                    "movement_range_y": 0,
                    "trainer_type": "TRAINER_TYPE_NONE",
                    "trainer_sight_or_berry_tree_id": "0",
                    "script": f"{folder}_EventScript_HallAttendant",
                    "flag": "0",
                },
            ],
            "warp_events": [
                {"x": 15, "y": 14, "elevation": 0, "dest_map": f"{map_id}_MART", "dest_warp_id": "0"},
                {"x": 9, "y": 6, "elevation": 0, "dest_map": f"{map_id}_GYM", "dest_warp_id": "0"},
                {"x": 15, "y": 6, "elevation": 0, "dest_map": f"{map_id}_POKEMON_CENTER_1F", "dest_warp_id": "0"},
                {"x": 4, "y": 16, "elevation": 0, "dest_map": "MAP_EASTERN_AURELIA_HALL", "dest_warp_id": "0"},
                {"x": 1, "y": 9, "elevation": 0, "dest_map": "MAP_EASTERN_AURELIA_HALL", "dest_warp_id": "0"},
            ],
            "coord_events": [],
            "bg_events": [
                {"type": "sign", "x": 16, "y": 14, "elevation": 0, "player_facing_dir": "BG_EVENT_PLAYER_FACING_NORTH", "script": "Common_EventScript_ShowPokemartSign"},
                {"type": "sign", "x": 16, "y": 6, "elevation": 0, "player_facing_dir": "BG_EVENT_PLAYER_FACING_NORTH", "script": "Common_EventScript_ShowPokemonCenterSign"},
                {"type": "sign", "x": 8, "y": 7, "elevation": 0, "player_facing_dir": "BG_EVENT_PLAYER_FACING_ANY", "script": f"{folder}_EventScript_GymSign"},
                {"type": "sign", "x": 14, "y": 6, "elevation": 0, "player_facing_dir": "BG_EVENT_PLAYER_FACING_NORTH", "script": "Common_EventScript_ShowPokemonCenterSign"},
                {"type": "sign", "x": 6, "y": 12, "elevation": 0, "player_facing_dir": "BG_EVENT_PLAYER_FACING_ANY", "script": f"{folder}_EventScript_CitySign"},
                {"type": "sign", "x": 17, "y": 14, "elevation": 0, "player_facing_dir": "BG_EVENT_PLAYER_FACING_NORTH", "script": "Common_EventScript_ShowPokemartSign"},
                {"type": "sign", "x": 3, "y": 10, "elevation": 0, "player_facing_dir": "BG_EVENT_PLAYER_FACING_ANY", "script": f"{folder}_EventScript_TeleportSign"},
            ],
        },
        indent=2,
    ) + "\n"


def camel_to_map(folder: str) -> str:
    # VerdantisCity -> MAP_VERDANTIS_CITY
    parts = re.findall(r"[A-Z][a-z0-9]*", folder)
    return "MAP_" + "_".join(p.upper() for p in parts)


def layout_id(folder: str) -> str:
    return "LAYOUT_" + camel_to_map(folder)[4:]


def city_scripts(c: dict) -> str:
    f = c["folder"]
    mid = camel_to_map(f)
    return f"""{f}_MapScripts::
	.byte 0

{f}_EventScript_Girl::
	msgbox {f}_Text_Girl, MSGBOX_NPC
	end

{f}_EventScript_ExpertM::
	msgbox {f}_Text_ExpertM, MSGBOX_NPC
	end

{f}_EventScript_Gentleman::
	msgbox {f}_Text_Gentleman, MSGBOX_NPC
	end

{f}_EventScript_HallAttendant::
	lock
	faceplayer
	msgbox {f}_Text_HallAttendant, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, {f}_EventScript_HallAttendantStay
	msgbox {f}_Text_HallAttendantWarp, MSGBOX_DEFAULT
	warpsilent MAP_EASTERN_AURELIA_HALL, 2, 6
	waitstate
	release
	end

{f}_EventScript_HallAttendantStay::
	msgbox {f}_Text_HallAttendantStay, MSGBOX_DEFAULT
	release
	end

{f}_EventScript_CitySign::
	msgbox {f}_Text_CitySign, MSGBOX_SIGN
	end

{f}_EventScript_GymSign::
	msgbox {f}_Text_GymSign, MSGBOX_SIGN
	end

{f}_EventScript_TeleportSign::
	msgbox {f}_Text_TeleportSign, MSGBOX_SIGN
	end

{f}_Text_Girl:
	.string "Welcome to {c['display']}!\\n"
	.string "The Hall teleport net hums nearby.$"

{f}_Text_ExpertM:
	.string "{c['leader']} keeps the {c['type_word']} GYM honest.\\n"
	.string "Challenge the GYM when you're ready.$"

{f}_Text_Gentleman:
	.string "Eastern Aurelia Hall links the cities.\\n"
	.string "Our attendant can send you back.$"

{f}_Text_HallAttendant:
	.string "Return to EASTERN AURELIA HALL?$"

{f}_Text_HallAttendantWarp:
	.string "Safe travels through the net.$"

{f}_Text_HallAttendantStay:
	.string "Explore at your own pace.$"

{f}_Text_CitySign:
	.string "{c['display']}\\n"
	.string "{c['tagline']}$"

{f}_Text_GymSign:
	.string "{c['display']} POKéMON GYM\\n"
	.string "LEADER: {c['leader']}\\l"
	.string "“The {c['type_word']} trial!”$"

{f}_Text_TeleportSign:
	.string "{c['display']} TELEPORT NET\\n"
	.string "Gateways link Hall and city.$"
"""


def gym_map_json(c: dict) -> str:
    f = c["folder"]
    mid = camel_to_map(f)
    prefix = c["prefix"]
    return json.dumps(
        {
            "id": f"{mid}_GYM",
            "name": f"{f}_Gym",
            "layout": f"{layout_id(f)}_GYM",
            "music": "MUS_GYM",
            "region": "REGION_HOENN",
            "region_map_section": c["mapsec"],
            "requires_flash": False,
            "weather": "WEATHER_NONE",
            "map_type": "MAP_TYPE_INDOOR",
            "allow_cycling": False,
            "allow_escaping": False,
            "allow_running": False,
            "show_map_name": False,
            "battle_scene": "MAP_BATTLE_SCENE_GYM",
            "connections": None,
            "object_events": [
                {
                    "graphics_id": c["leader_gfx"],
                    "x": 5,
                    "y": 2,
                    "elevation": 3,
                    "movement_type": "MOVEMENT_TYPE_FACE_DOWN",
                    "movement_range_x": 0,
                    "movement_range_y": 0,
                    "trainer_type": "TRAINER_TYPE_NONE",
                    "trainer_sight_or_berry_tree_id": "0",
                    "script": f"{f}_Gym_EventScript_{c['leader_key']}",
                    "flag": "0",
                },
                {
                    "graphics_id": c["minion_gfx"][0],
                    "x": 5,
                    "y": 13,
                    "elevation": 3,
                    "movement_type": "MOVEMENT_TYPE_FACE_DOWN",
                    "movement_range_x": 0,
                    "movement_range_y": 0,
                    "trainer_type": "TRAINER_TYPE_NORMAL",
                    "trainer_sight_or_berry_tree_id": "2",
                    "script": f"{f}_Gym_EventScript_TrainerA",
                    "flag": "0",
                },
                {
                    "graphics_id": c["minion_gfx"][1],
                    "x": 4,
                    "y": 8,
                    "elevation": 3,
                    "movement_type": "MOVEMENT_TYPE_FACE_DOWN",
                    "movement_range_x": 0,
                    "movement_range_y": 0,
                    "trainer_type": "TRAINER_TYPE_NORMAL",
                    "trainer_sight_or_berry_tree_id": "3",
                    "script": f"{f}_Gym_EventScript_TrainerB",
                    "flag": "0",
                },
                {
                    "graphics_id": "OBJ_EVENT_GFX_MAN_2",
                    "x": 3,
                    "y": 18,
                    "elevation": 3,
                    "movement_type": "MOVEMENT_TYPE_FACE_DOWN",
                    "movement_range_x": 0,
                    "movement_range_y": 0,
                    "trainer_type": "TRAINER_TYPE_NONE",
                    "trainer_sight_or_berry_tree_id": "0",
                    "script": f"{f}_Gym_EventScript_GymGuide",
                    "flag": "0",
                },
                {
                    "graphics_id": c["minion_gfx"][2],
                    "x": 4,
                    "y": 6,
                    "elevation": 3,
                    "movement_type": "MOVEMENT_TYPE_FACE_DOWN",
                    "movement_range_x": 1,
                    "movement_range_y": 1,
                    "trainer_type": "TRAINER_TYPE_NORMAL",
                    "trainer_sight_or_berry_tree_id": "3",
                    "script": f"{f}_Gym_EventScript_TrainerC",
                    "flag": "0",
                },
            ],
            "warp_events": [
                {"x": 5, "y": 19, "elevation": 0, "dest_map": mid, "dest_warp_id": "1"},
                {"x": 6, "y": 19, "elevation": 0, "dest_map": mid, "dest_warp_id": "1"},
            ],
            "coord_events": [],
            "bg_events": [
                {"type": "sign", "x": 2, "y": 18, "elevation": 0, "player_facing_dir": "BG_EVENT_PLAYER_FACING_NORTH", "script": f"{f}_Gym_EventScript_LeftGymStatue"},
                {"type": "sign", "x": 8, "y": 18, "elevation": 0, "player_facing_dir": "BG_EVENT_PLAYER_FACING_NORTH", "script": f"{f}_Gym_EventScript_RightGymStatue"},
            ],
        },
        indent=2,
    ) + "\n"


def gym_scripts(c: dict) -> str:
    f = c["folder"]
    lk = c["leader_key"]
    leader = c["leader"]
    prefix = c["prefix"]
    return f"""{f}_Gym_MapScripts::
	.byte 0

{f}_Gym_EventScript_{lk}::
	trainerbattle_single {c['trainer']}, {f}_Gym_Text_{lk}Intro, {f}_Gym_Text_{lk}Defeat, {f}_Gym_EventScript_{lk}Defeated, NO_MUSIC
	goto_if_set {c['badge_flag']}, {f}_Gym_EventScript_{lk}PostBadge
	release
	end

{f}_Gym_EventScript_{lk}Defeated::
	message {f}_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox {f}_Gym_Text_BadgeInfo, MSGBOX_DEFAULT
	setflag {c['badge_flag']}
{c['extra_badge']}\tcall Genesis_EventScript_UpdateLevelCap
	msgbox {f}_Gym_Text_{lk}After, MSGBOX_DEFAULT
	release
	end

{f}_Gym_EventScript_{lk}PostBadge::
	msgbox {f}_Gym_Text_{lk}Done, MSGBOX_DEFAULT
	release
	end

{f}_Gym_EventScript_TrainerA::
	trainerbattle_single TRAINER_GENESIS_{prefix}_A, {f}_Gym_Text_TrainerAIntro, {f}_Gym_Text_TrainerADefeat
	msgbox {f}_Gym_Text_TrainerAPost, MSGBOX_AUTOCLOSE
	end

{f}_Gym_EventScript_TrainerB::
	trainerbattle_single TRAINER_GENESIS_{prefix}_B, {f}_Gym_Text_TrainerBIntro, {f}_Gym_Text_TrainerBDefeat
	msgbox {f}_Gym_Text_TrainerBPost, MSGBOX_AUTOCLOSE
	end

{f}_Gym_EventScript_TrainerC::
	trainerbattle_single TRAINER_GENESIS_{prefix}_C, {f}_Gym_Text_TrainerCIntro, {f}_Gym_Text_TrainerCDefeat
	msgbox {f}_Gym_Text_TrainerCPost, MSGBOX_AUTOCLOSE
	end

{f}_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set {c['badge_flag']}, {f}_Gym_EventScript_GymGuidePostVictory
	msgbox {f}_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

{f}_Gym_EventScript_GymGuidePostVictory::
	msgbox {f}_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

{f}_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set {c['badge_flag']}, {f}_Gym_EventScript_GymStatueCertified
	goto {f}_Gym_EventScript_GymStatue
	end

{f}_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set {c['badge_flag']}, {f}_Gym_EventScript_GymStatueCertified
	goto {f}_Gym_EventScript_GymStatue
	end

{f}_Gym_EventScript_GymStatueCertified::
	msgbox {f}_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

{f}_Gym_EventScript_GymStatue::
	msgbox {f}_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

{f}_Gym_Text_GymGuideAdvice:
	.string "Yo! Welcome to {c['display']} GYM!\\p"
	.string "{leader} uses {c['type_advice']}\\p"
	.string "Claim the {c['badge_name']}!$"

{f}_Gym_Text_GymGuidePostVictory:
	.string "Nice work!\\n"
	.string "The {c['badge_name']} is yours!$"

{f}_Gym_Text_TrainerAIntro:
	.string "This GYM tests your resolve!$"

{f}_Gym_Text_TrainerADefeat:
	.string "You broke through…$"

{f}_Gym_Text_TrainerAPost:
	.string "{leader} is still ahead.$"

{f}_Gym_Text_TrainerBIntro:
	.string "Don't underestimate us!$"

{f}_Gym_Text_TrainerBDefeat:
	.string "Sharp work…$"

{f}_Gym_Text_TrainerBPost:
	.string "Trust your team.$"

{f}_Gym_Text_TrainerCIntro:
	.string "Pressure incoming!$"

{f}_Gym_Text_TrainerCDefeat:
	.string "My plan broke…$"

{f}_Gym_Text_TrainerCPost:
	.string "The {c['badge_name']} opens the path ahead.$"

{f}_Gym_Text_{lk}Intro:
	.string "{leader}: Welcome to {c['display']} GYM.\\n"
	.string "I am the {c['type_word']} LEADER.\\p"
	.string "Show me your strength--shall we begin?$"

{f}_Gym_Text_{lk}Defeat:
	.string "Well fought… The city is yours to stamp.$"

{f}_Gym_Text_ReceivedBadge:
	.string "{{PLAYER}} received the {c['badge_name']}\\n"
	.string "from {leader}!$"

{f}_Gym_Text_BadgeInfo:
	.string "{leader}: With the {c['badge_name']}, your\\n"
	.string "Eastern Aurelia journey deepens.\\p"
	.string "Return to the Hall when you're ready\\n"
	.string "for the next city.$"

{f}_Gym_Text_{lk}After:
	.string "{leader}: {c['display']} stamps your path.\\n"
	.string "Carry what you learned.$"

{f}_Gym_Text_{lk}Done:
	.string "{leader}: The teleport net still hums.\\n"
	.string "Walk tall, Champion.$"

{f}_Gym_Text_GymStatue:
	.string "{c['display']} POKéMON GYM$"

{f}_Gym_Text_GymStatueCertified:
	.string "{c['display']} POKéMON GYM\\p"
	.string "{leader}'S CERTIFIED TRAINERS:\\n"
	.string "{{PLAYER}}$"
"""


def center_1f(c: dict) -> tuple[str, str]:
    f = c["folder"]
    mid = camel_to_map(f)
    nurse = f"LOCALID_{c['prefix']}_NURSE"
    # shorten nurse local id for long prefixes
    nurse = f"LOCALID_{c['folder'].replace('City','').upper()}_NURSE"
    heal = f"HEAL_LOCATION_{mid[4:]}"
    mj = json.dumps(
        {
            "id": f"{mid}_POKEMON_CENTER_1F",
            "name": f"{f}_PokemonCenter_1F",
            "layout": "LAYOUT_POKEMON_CENTER_1F",
            "music": "MUS_POKE_CENTER",
            "region": "REGION_HOENN",
            "region_map_section": c["mapsec"],
            "requires_flash": False,
            "weather": "WEATHER_NONE",
            "map_type": "MAP_TYPE_INDOOR",
            "allow_cycling": False,
            "allow_escaping": False,
            "allow_running": False,
            "show_map_name": False,
            "battle_scene": "MAP_BATTLE_SCENE_NORMAL",
            "connections": None,
            "object_events": [
                {
                    "local_id": nurse,
                    "graphics_id": "OBJ_EVENT_GFX_NURSE",
                    "x": 7,
                    "y": 2,
                    "elevation": 3,
                    "movement_type": "MOVEMENT_TYPE_FACE_DOWN",
                    "movement_range_x": 0,
                    "movement_range_y": 0,
                    "trainer_type": "TRAINER_TYPE_NONE",
                    "trainer_sight_or_berry_tree_id": "0",
                    "script": f"{f}_PokemonCenter_1F_EventScript_Nurse",
                    "flag": "0",
                },
                {
                    "graphics_id": "OBJ_EVENT_GFX_GIRL_3",
                    "x": 10,
                    "y": 6,
                    "elevation": 3,
                    "movement_type": "MOVEMENT_TYPE_FACE_RIGHT",
                    "movement_range_x": 0,
                    "movement_range_y": 0,
                    "trainer_type": "TRAINER_TYPE_NONE",
                    "trainer_sight_or_berry_tree_id": "0",
                    "script": f"{f}_PokemonCenter_1F_EventScript_Girl",
                    "flag": "0",
                },
                {
                    "graphics_id": "OBJ_EVENT_GFX_EXPERT_M",
                    "x": 2,
                    "y": 3,
                    "elevation": 3,
                    "movement_type": "MOVEMENT_TYPE_FACE_DOWN",
                    "movement_range_x": 0,
                    "movement_range_y": 0,
                    "trainer_type": "TRAINER_TYPE_NONE",
                    "trainer_sight_or_berry_tree_id": "0",
                    "script": f"{f}_PokemonCenter_1F_EventScript_ExpertM",
                    "flag": "0",
                },
            ],
            "warp_events": [
                {"x": 7, "y": 8, "elevation": 3, "dest_map": mid, "dest_warp_id": "2"},
                {"x": 6, "y": 8, "elevation": 3, "dest_map": mid, "dest_warp_id": "2"},
                {"x": 1, "y": 6, "elevation": 4, "dest_map": f"{mid}_POKEMON_CENTER_2F", "dest_warp_id": "0"},
            ],
            "coord_events": [],
            "bg_events": [],
        },
        indent=2,
    ) + "\n"
    sc = f"""{f}_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, {f}_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

{f}_PokemonCenter_1F_OnTransition:
	setrespawn {heal}
	call Common_EventScript_UpdateBrineyLocation
	end

{f}_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, {nurse}
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

{f}_PokemonCenter_1F_EventScript_Girl::
	msgbox {f}_PokemonCenter_1F_Text_Girl, MSGBOX_NPC
	end

{f}_PokemonCenter_1F_EventScript_ExpertM::
	msgbox {f}_PokemonCenter_1F_Text_ExpertM, MSGBOX_NPC
	end

{f}_PokemonCenter_1F_Text_Girl:
	.string "Heal up before {c['leader']}.\\n"
	.string "{c['display']} doesn't go easy.$"

{f}_PokemonCenter_1F_Text_ExpertM:
	.string "The Hall attendant outside will send\\n"
	.string "you back when you're done.$"
"""
    c["_nurse"] = nurse
    c["_heal"] = heal
    c["_map_id"] = mid
    return mj, sc


def center_2f(c: dict) -> tuple[str, str]:
    f = c["folder"]
    mid = c["_map_id"]
    mj = json.dumps(
        {
            "id": f"{mid}_POKEMON_CENTER_2F",
            "name": f"{f}_PokemonCenter_2F",
            "layout": "LAYOUT_POKEMON_CENTER_2F",
            "music": "MUS_POKE_CENTER",
            "region": "REGION_HOENN",
            "region_map_section": c["mapsec"],
            "requires_flash": False,
            "weather": "WEATHER_NONE",
            "map_type": "MAP_TYPE_INDOOR",
            "allow_cycling": False,
            "allow_escaping": False,
            "allow_running": False,
            "show_map_name": False,
            "battle_scene": "MAP_BATTLE_SCENE_NORMAL",
            "connections": None,
            "object_events": [
                {"graphics_id": "OBJ_EVENT_GFX_TEALA", "x": 6, "y": 2, "elevation": 0, "movement_type": "MOVEMENT_TYPE_FACE_DOWN", "movement_range_x": 1, "movement_range_y": 1, "trainer_type": "TRAINER_TYPE_NONE", "trainer_sight_or_berry_tree_id": "0", "script": "Common_EventScript_UnionRoomAttendant", "flag": "0"},
                {"graphics_id": "OBJ_EVENT_GFX_TEALA", "x": 2, "y": 2, "elevation": 3, "movement_type": "MOVEMENT_TYPE_FACE_DOWN", "movement_range_x": 1, "movement_range_y": 1, "trainer_type": "TRAINER_TYPE_NONE", "trainer_sight_or_berry_tree_id": "0", "script": "Common_EventScript_WirelessClubAttendant", "flag": "0"},
                {"graphics_id": "OBJ_EVENT_GFX_TEALA", "x": 10, "y": 2, "elevation": 0, "movement_type": "MOVEMENT_TYPE_FACE_DOWN", "movement_range_x": 1, "movement_range_y": 1, "trainer_type": "TRAINER_TYPE_NONE", "trainer_sight_or_berry_tree_id": "0", "script": "Common_EventScript_DirectCornerAttendant", "flag": "0"},
                {"graphics_id": "OBJ_EVENT_GFX_MYSTERY_GIFT_MAN", "x": 1, "y": 2, "elevation": 0, "movement_type": "MOVEMENT_TYPE_FACE_DOWN", "movement_range_x": 1, "movement_range_y": 1, "trainer_type": "TRAINER_TYPE_NONE", "trainer_sight_or_berry_tree_id": "0", "script": "CableClub_EventScript_MysteryGiftMan", "flag": "FLAG_HIDE_POKEMON_CENTER_2F_MYSTERY_GIFT_MAN"},
            ],
            "warp_events": [
                {"x": 1, "y": 6, "elevation": 4, "dest_map": f"{mid}_POKEMON_CENTER_1F", "dest_warp_id": "2"},
                {"x": 5, "y": 1, "elevation": 3, "dest_map": "MAP_UNION_ROOM", "dest_warp_id": "0"},
                {"x": 9, "y": 1, "elevation": 3, "dest_map": "MAP_TRADE_CENTER", "dest_warp_id": "0"},
            ],
            "coord_events": [],
            "bg_events": [],
        },
        indent=2,
    ) + "\n"
    sc = f"""{f}_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0
"""
    return mj, sc


def mart(c: dict) -> tuple[str, str]:
    f = c["folder"]
    mid = c["_map_id"]
    mj = json.dumps(
        {
            "id": f"{mid}_MART",
            "name": f"{f}_Mart",
            "layout": "LAYOUT_MART",
            "music": "MUS_POKE_MART",
            "region": "REGION_HOENN",
            "region_map_section": c["mapsec"],
            "requires_flash": False,
            "weather": "WEATHER_NONE",
            "map_type": "MAP_TYPE_INDOOR",
            "allow_cycling": False,
            "allow_escaping": False,
            "allow_running": False,
            "show_map_name": False,
            "battle_scene": "MAP_BATTLE_SCENE_NORMAL",
            "connections": None,
            "object_events": [
                {"graphics_id": "OBJ_EVENT_GFX_MART_EMPLOYEE", "x": 1, "y": 3, "elevation": 3, "movement_type": "MOVEMENT_TYPE_FACE_RIGHT", "movement_range_x": 0, "movement_range_y": 0, "trainer_type": "TRAINER_TYPE_NONE", "trainer_sight_or_berry_tree_id": "0", "script": f"{f}_Mart_EventScript_Clerk", "flag": "0"},
                {"graphics_id": "OBJ_EVENT_GFX_WOMAN_2", "x": 5, "y": 3, "elevation": 3, "movement_type": "MOVEMENT_TYPE_WANDER_AROUND", "movement_range_x": 1, "movement_range_y": 1, "trainer_type": "TRAINER_TYPE_NONE", "trainer_sight_or_berry_tree_id": "0", "script": f"{f}_Mart_EventScript_Woman", "flag": "0"},
                {"graphics_id": "OBJ_EVENT_GFX_POKEFAN_M", "x": 9, "y": 6, "elevation": 3, "movement_type": "MOVEMENT_TYPE_FACE_DOWN", "movement_range_x": 0, "movement_range_y": 0, "trainer_type": "TRAINER_TYPE_NONE", "trainer_sight_or_berry_tree_id": "0", "script": f"{f}_Mart_EventScript_PokefanM", "flag": "0"},
            ],
            "warp_events": [
                {"x": 3, "y": 7, "elevation": 0, "dest_map": mid, "dest_warp_id": "0"},
                {"x": 4, "y": 7, "elevation": 0, "dest_map": mid, "dest_warp_id": "0"},
            ],
            "coord_events": [],
            "bg_events": [],
        },
        indent=2,
    ) + "\n"
    sc = f"""{f}_Mart_MapScripts::
	.byte 0

{f}_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart {f}_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
{f}_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SP_ATK
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_DEFENSE
	pokemartlistend

{f}_Mart_EventScript_Woman::
	msgbox {f}_Mart_Text_Woman, MSGBOX_NPC
	end

{f}_Mart_EventScript_PokefanM::
	msgbox {f}_Mart_Text_PokefanM, MSGBOX_NPC
	end

{f}_Mart_Text_Woman:
	.string "Stock up before {c['leader']}.\\n"
	.string "{c['type_word']} pressure hits hard.$"

{f}_Mart_Text_PokefanM:
	.string "Escape Ropes are a habit of mine.\\n"
	.string "Eastern caves can surprise you.$"
"""
    return mj, sc


def ensure_layouts_json() -> None:
    path = ROOT / "data/layouts/layouts.json"
    data = json.loads(path.read_text(encoding="utf-8"))
    by_id = {L["id"]: i for i, L in enumerate(data["layouts"])}
    entries = []
    for c in CITIES:
        f = c["folder"]
        lid = layout_id(f)
        gid = f"{lid}_GYM"
        entries.append(
            {
                "id": lid,
                "name": f"{f}_Layout",
                "width": 20,
                "height": 20,
                "primary_tileset": "gTileset_General",
                "secondary_tileset": "gTileset_Fallarbor",
                "border_filepath": f"data/layouts/{f}/border.bin",
                "blockdata_filepath": f"data/layouts/{f}/map.bin",
                "layout_version": "emerald",
            }
        )
        entries.append(
            {
                "id": gid,
                "name": f"{f}_Gym_Layout",
                "width": 11,
                "height": 20,
                "primary_tileset": "gTileset_Building",
                "secondary_tileset": "gTileset_RustboroGym",
                "border_filepath": f"data/layouts/{f}_Gym/border.bin",
                "blockdata_filepath": f"data/layouts/{f}_Gym/map.bin",
                "layout_version": "emerald",
            }
        )
    entries.append(
        {
            "id": "LAYOUT_WORLD_TOURNAMENT_LOBBY",
            "name": "WorldTournament_Lobby_Layout",
            "width": 25,
            "height": 10,
            "primary_tileset": "gTileset_Building",
            "secondary_tileset": "gTileset_BattleFrontier",
            "border_filepath": "data/layouts/WorldTournament_Lobby/border.bin",
            "blockdata_filepath": "data/layouts/WorldTournament_Lobby/map.bin",
            "layout_version": "emerald",
        }
    )
    for entry in entries:
        if entry["id"] in by_id:
            data["layouts"][by_id[entry["id"]]] = entry
        else:
            data["layouts"].append(entry)
            by_id[entry["id"]] = len(data["layouts"]) - 1
    path.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")


def ensure_map_groups() -> None:
    path = ROOT / "data/maps/map_groups.json"
    data = json.loads(path.read_text(encoding="utf-8"))
    special = data["gMapGroup_SpecialArea"]
    names = []
    for c in CITIES:
        f = c["folder"]
        names.extend([f, f"{f}_Gym", f"{f}_PokemonCenter_1F", f"{f}_PokemonCenter_2F", f"{f}_Mart"])
    names.append("WorldTournament_Lobby")
    for n in names:
        if n not in special:
            special.append(n)
    path.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")


def ensure_event_scripts() -> None:
    path = ROOT / "data/event_scripts.s"
    text = path.read_text(encoding="utf-8")
    lines = []
    for c in CITIES:
        f = c["folder"]
        for name in [f, f"{f}_Gym", f"{f}_PokemonCenter_1F", f"{f}_PokemonCenter_2F", f"{f}_Mart"]:
            needle = f'\t.include "data/maps/{name}/scripts.inc"\n'
            if needle not in text:
                lines.append(needle)
    wt = '\t.include "data/maps/WorldTournament_Lobby/scripts.inc"\n'
    if wt not in text:
        lines.append(wt)
    if lines:
        # Insert after MirageCity_Mart include if present
        anchor = '\t.include "data/maps/MirageCity_Mart/scripts.inc"\n'
        if anchor in text:
            text = text.replace(anchor, anchor + "".join(lines))
        else:
            text += "".join(lines)
        path.write_text(text, encoding="utf-8")


def ensure_mapsec() -> None:
    path = ROOT / "src/data/region_map/region_map_sections.json"
    data = json.loads(path.read_text(encoding="utf-8"))
    sections = data["map_sections"]
    ids = {s["id"] for s in sections}
    for c in CITIES:
        if c["mapsec"] not in ids:
            sections.append(
                {
                    "id": c["mapsec"],
                    "name": c["mapsec_name"],
                    "x": c["x"],
                    "y": c["y"],
                    "width": 1,
                    "height": 1,
                }
            )
            ids.add(c["mapsec"])
    if "MAPSEC_WORLD_TOURNAMENT" not in ids:
        sections.append(
            {
                "id": "MAPSEC_WORLD_TOURNAMENT",
                "name": "WORLD TOURNAMENT",
                "x": 26,
                "y": 4,
                "width": 1,
                "height": 1,
            }
        )
    path.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")


def ensure_heals() -> None:
    path = ROOT / "src/data/heal_locations.json"
    data = json.loads(path.read_text(encoding="utf-8"))
    ids = {h["id"] for h in data["heal_locations"]}
    for c in CITIES:
        mid = c["_map_id"]
        hid = c["_heal"]
        if hid not in ids:
            data["heal_locations"].append(
                {
                    "id": hid,
                    "map": mid,
                    "x": 14,
                    "y": 8,
                    "respawn_map": f"{mid}_POKEMON_CENTER_1F",
                    "respawn_npc": c["_nurse"],
                }
            )
            ids.add(hid)
    path.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")


def ensure_localids() -> None:
    path = ROOT / "include/constants/map_event_ids.h"
    text = path.read_text(encoding="utf-8")
    block_lines = []
    for c in CITIES:
        mid = c["_map_id"]
        nurse = c["_nurse"]
        marker = f"// {mid}_POKEMON_CENTER_1F"
        if marker not in text and f"#define {nurse}" not in text:
            block_lines.append(f"\n{marker}\n#define {nurse} 1\n")
    if "LOCALID_WT_ATTENDANT" not in text:
        block_lines.append("\n// MAP_WORLD_TOURNAMENT_LOBBY\n#define LOCALID_WT_ATTENDANT 1\n")
    if block_lines:
        text = text.replace(
            "#endif // GUARD_CONSTANTS_MAP_EVENT_IDS_H",
            "".join(block_lines) + "\n#endif // GUARD_CONSTANTS_MAP_EVENT_IDS_H",
        )
        path.write_text(text, encoding="utf-8")


def ensure_opponents_and_party() -> None:
    opp = ROOT / "include/constants/opponents.h"
    text = opp.read_text(encoding="utf-8")
    # Assign IDs starting after MIRAGE_C (868)
    next_id = 869
    defs = []
    for c in CITIES:
        for letter in "ABC":
            name = f"TRAINER_GENESIS_{c['prefix']}_{letter}"
            if name not in text:
                defs.append((name, next_id, c["folder"]))
            next_id += 1
    if defs:
        insert = ""
        for name, tid, folder in defs:
            insert += f"#define {name:<32} {tid} // {folder} Gym trainer\n"
        text = text.replace(
            "#define TRAINER_GENESIS_MIRAGE_C            868\n",
            "#define TRAINER_GENESIS_MIRAGE_C            868\n" + insert,
        )
        # bump counts: last id + 1
        last = defs[-1][1] + 1
        text = re.sub(
            r"#define TRAINERS_COUNT_EMERALD\s+\d+",
            f"#define TRAINERS_COUNT_EMERALD     {last}",
            text,
        )
        text = re.sub(
            r"#define MAX_TRAINERS_COUNT_EMERALD\s+\d+",
            f"#define MAX_TRAINERS_COUNT_EMERALD {last}",
            text,
        )
        text = text.replace(
            "// GENESIS: expanded past Emerald for Ace (+2) and Mirage Gym (+3). Shifts SYSTEM_FLAGS; bump save version.",
            "// GENESIS: expanded for Ace, Mirage, and eastern gyms 10-16. Shifts SYSTEM_FLAGS; bump save version.",
        )
        opp.write_text(text, encoding="utf-8")

    party = ROOT / "src/data/trainers.party"
    ptext = party.read_text(encoding="utf-8")
    names = ["RIVER", "BLAZE", "QUILL", "SHADE", "VINCE", "NYX", "ORION", "IVY", "KAI", "REM", "SOL", "ASH", "LEX", "MIRA", "JON", "EVA", "REX", "UNA", "PIO", "SKYE", "VAL"]
    ni = 0
    additions = []
    for c in CITIES:
        for i, letter in enumerate("ABC"):
            tname = f"TRAINER_GENESIS_{c['prefix']}_{letter}"
            if f"=== {tname} ===" in ptext:
                continue
            species, moves = c["parties"][i]
            level = c["levels"][i]
            move_lines = "\n".join(f"- {m.strip()}" for m in moves.split("/"))
            tainer_name = names[ni % len(names)]
            ni += 1
            gender = "Female" if i == 1 else "Male"
            pic = c["minion_pic"] if i != 1 or "F" in c["minion_pic"] else c["minion_pic"]
            if i == 1 and "F" not in pic and pic.endswith(" M"):
                pic = pic[:-2] + " F"
            elif i == 1 and pic == "Bug Catcher":
                pic = "Lass"
            elif i == 1 and pic == "Dragon Tamer":
                pic = "Cooltrainer F"
            additions.append(
                f"""
=== {tname} ===
Name: {tainer_name}
Class: {c['minion_class']}
Pic: {pic}
Gender: {gender}
Music: Intense
Double Battle: No
AI: Check Bad Move

{species}
Level: {level}
IVs: 20 HP / 20 Atk / 20 Def / 20 SpA / 20 SpD / 20 Spe
{move_lines}
"""
            )
    if additions:
        party.write_text(ptext.rstrip() + "\n" + "".join(additions) + "\n", encoding="utf-8")


def rewrite_hall_scripts() -> None:
    """Fully rewrite Hall leader/desk scripts from a clean template (idempotent)."""
    path = ROOT / "data/maps/EasternAurelia_Hall/scripts.inc"
    text = path.read_text(encoding="utf-8")

    # Keep everything up through IrisDone (Mirage already live), then rebuild 10-16 + shared tails.
    iris_end = text.find("EasternAurelia_Hall_EventScript_Celia::")
    if iris_end < 0:
        raise SystemExit("Hall scripts missing Celia marker")
    head = text[:iris_end]

    leader_blocks = []
    for c in CITIES:
        mid = camel_to_map(c["folder"])
        key = c["hall_key"]
        leader_blocks.append(
            f"""EasternAurelia_Hall_EventScript_{key}::
	lock
	faceplayer
	goto_if_unset {c['prev_flag']}, EasternAurelia_Hall_EventScript_{c['prev_need']}
	goto_if_set {c['badge_flag']}, EasternAurelia_Hall_EventScript_{key}Done
	msgbox EasternAurelia_Hall_Text_{key}Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_{key}Warp, MSGBOX_DEFAULT
	warpsilent {mid}, 9, 8
	waitstate
	release
	end

EasternAurelia_Hall_EventScript_{key}Done::
	msgbox EasternAurelia_Hall_Text_{key}Done, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Decline
	msgbox EasternAurelia_Hall_Text_{key}Warp, MSGBOX_DEFAULT
	warpsilent {mid}, 9, 8
	waitstate
	release
	end
"""
        )

    # Preserve Need*/Decline/Legend/Clerk scripts from original by slicing from NeedIris
    need_idx = text.find("EasternAurelia_Hall_EventScript_NeedIris::")
    desk_mirage_idx = text.find("EasternAurelia_Hall_EventScript_DeskMirage::")
    if need_idx < 0 or desk_mirage_idx < 0:
        raise SystemExit("Hall scripts missing NeedIris/DeskMirage markers")
    mid_scripts = text[need_idx:desk_mirage_idx]

    desk_blocks = []
    # Keep DeskMirage as-is from file until Verdantis
    desk_mirage_end = text.find("EasternAurelia_Hall_EventScript_DeskVerdantis::")
    if desk_mirage_end < 0:
        raise SystemExit("Hall missing DeskVerdantis")
    desk_mirage = text[desk_mirage_idx:desk_mirage_end]

    for c in CITIES:
        mid = camel_to_map(c["folder"])
        desk = c["desk_key"]
        desk_blocks.append(
            f"""EasternAurelia_Hall_EventScript_Desk{desk}::
	msgbox EasternAurelia_Hall_Text_Desk{desk}, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EasternAurelia_Hall_EventScript_Desk{desk}Cancel
	warpsilent {mid}, 9, 8
	waitstate
	end

EasternAurelia_Hall_EventScript_Desk{desk}Cancel::
	release
	end
"""
        )

    hall_dir_idx = text.find("EasternAurelia_Hall_EventScript_HallDirectory::")
    if hall_dir_idx < 0:
        raise SystemExit("Hall missing HallDirectory")
    hall_dir = text[hall_dir_idx : text.find("EasternAurelia_Hall_Text_Decline:")]

    texts = []
    # Decline + Need texts from original until IrisIntro
    text_decline_idx = text.find("EasternAurelia_Hall_Text_Decline:")
    text_iris_intro = text.find("EasternAurelia_Hall_Text_IrisIntro:")
    texts.append(text[text_decline_idx:text_iris_intro])
    # Keep Iris intro/warp/done
    text_celia_intro = text.find("EasternAurelia_Hall_Text_CeliaIntro:")
    # Prefer CeliaWarp if already inserted
    celia_warp = text.find("EasternAurelia_Hall_Text_CeliaWarp:")
    iris_texts_end = celia_warp if celia_warp > 0 else text_celia_intro
    texts.append(text[text_iris_intro:iris_texts_end])

    intro_done = {
        "Celia": (
            "VERDANTIS CITY",
            "CELIA",
            "BUG",
            "JUNGLE BADGE",
        ),
        "Noctis": ("OBSIDIAN CITY", "NOCTIS", "DARK", "OBSIDIAN BADGE"),
        "Drake": ("ASTRAL CITY", "DRAKE", "DRAGON", "ASTRAL BADGE"),
        "Luna": ("TIDYMOON CITY", "LUNA", "FAIRY", "MOON BADGE"),
        "Morrigan": ("EON CITY", "MORRIGAN", "GHOST", "EON BADGE"),
        "Colleague": ("GENESIS CITY", "the COLLEAGUE", "MIXED", "GENESIS BADGE"),
        "Mentor": ("AURELIA SUMMIT", "the MENTOR", "MIXED", "ASCENSION BADGE"),
    }
    for c in CITIES:
        key = c["hall_key"]
        city, leader, typ, badge = intro_done[key]
        if key == "Mentor":
            intro = (
                f'EasternAurelia_Hall_Text_{key}Warp:\n'
                f'\t.string "Opening the teleport net to {city}.$"\n\n'
                f'EasternAurelia_Hall_Text_{key}Intro:\n'
                f'\t.string "GUIDE: AURELIA SUMMIT (east) is open\\n"\n'
                f'\t.string "beyond this desk--the MENTOR awaits.\\p"\n'
                f'\t.string "Travel to AURELIA SUMMIT now?$"\n\n'
                f'EasternAurelia_Hall_Text_{key}Done:\n'
                f'\t.string "GUIDE: You hold the {badge}.\\n"\n'
                f'\t.string "Return to AURELIA SUMMIT?$"\n\n'
            )
        elif key == "Colleague":
            intro = (
                f'EasternAurelia_Hall_Text_{key}Warp:\n'
                f'\t.string "Opening the teleport net to {city}.$"\n\n'
                f'EasternAurelia_Hall_Text_{key}Intro:\n'
                f'\t.string "GUIDE: GENESIS CITY is open beyond this\\n"\n'
                f'\t.string "desk--the COLLEAGUE\'s MIXED GYM awaits.\\p"\n'
                f'\t.string "Travel to GENESIS CITY now?$"\n\n'
                f'EasternAurelia_Hall_Text_{key}Done:\n'
                f'\t.string "GUIDE: You hold the {badge}.\\n"\n'
                f'\t.string "Return to GENESIS CITY?$"\n\n'
            )
        else:
            intro = (
                f'EasternAurelia_Hall_Text_{key}Warp:\n'
                f'\t.string "Opening the teleport net to {city}.$"\n\n'
                f'EasternAurelia_Hall_Text_{key}Intro:\n'
                f'\t.string "GUIDE: {city} is open beyond this\\n"\n'
                f'\t.string "desk--{leader}\'s {typ} GYM awaits.\\p"\n'
                f'\t.string "Travel to {city} now?$"\n\n'
                f'EasternAurelia_Hall_Text_{key}Done:\n'
                f'\t.string "GUIDE: You hold the {badge}.\\n"\n'
                f'\t.string "Return to {city}?$"\n\n'
            )
        texts.append(intro)

    # Keep legend/clerk texts from LegendEarly onward, but rewrite clerk welcome/directory/desks
    legend_idx = text.find("EasternAurelia_Hall_Text_LegendEarly:")
    if legend_idx < 0:
        raise SystemExit("missing LegendEarly text")
    tail = text[legend_idx:]

    # Rewrite clerk + desk texts in tail
    clerk_welcome = (
        "EasternAurelia_Hall_Text_ClerkWelcome:\n"
        '\t.string "Eastern AURELIA HALL clerk.\\n"\n'
        '\t.string "Eight live cities, one hall.$"\n'
    )
    tail = re.sub(
        r"EasternAurelia_Hall_Text_ClerkWelcome:\n(?:\t\.string \"[^\"]*\"\n)+?",
        lambda _m: clerk_welcome,
        tail,
        count=1,
    )
    clerk_dir = (
        "EasternAurelia_Hall_Text_ClerkDirectory:\n"
        '\t.string "All eight eastern cities are live maps.\\n"\n'
        '\t.string "Desk guides and plaques warp you in.\\p"\n'
        '\t.string "Back row: MIRAGE · VERDANTIS ·\\n"\n'
        '\t.string "OBSIDIAN · ASTRAL.\\p"\n'
        '\t.string "Front row: TIDYMOON · EON ·\\n"\n'
        '\t.string "GENESIS CITY · SUMMIT EAST.\\p"\n'
        '\t.string "Researcher: Legend Sanctum.\\n"\n'
        '\t.string "WORLD TOURNAMENT lobby via Frontier.$"\n'
    )
    tail = re.sub(
        r"EasternAurelia_Hall_Text_ClerkDirectory:\n(?:\t\.string \"[^\"]*\"\n)+?",
        lambda _m: clerk_dir,
        tail,
        count=1,
    )

    desk_text_map = {
        "Verdantis": (
            'EasternAurelia_Hall_Text_DeskVerdantis:\n'
            '\t.string "VERDANTIS CITY -- Badge 10 (live map)\\n"\n'
            '\t.string "LEADER CELIA · BUG · Jungle Badge\\p"\n'
            '\t.string "Warp to VERDANTIS CITY?$"\n'
        ),
        "Obsidian": (
            'EasternAurelia_Hall_Text_DeskObsidian:\n'
            '\t.string "OBSIDIAN CITY -- Badge 11 (live map)\\n"\n'
            '\t.string "LEADER NOCTIS · DARK · Obsidian Badge\\p"\n'
            '\t.string "Warp to OBSIDIAN CITY?$"\n'
        ),
        "Astral": (
            'EasternAurelia_Hall_Text_DeskAstral:\n'
            '\t.string "ASTRAL CITY -- Badge 12 (live map)\\n"\n'
            '\t.string "LEADER DRAKE · DRAGON · Astral / Tera\\p"\n'
            '\t.string "Warp to ASTRAL CITY?$"\n'
        ),
        "Tidymoon": (
            'EasternAurelia_Hall_Text_DeskTidymoon:\n'
            '\t.string "TIDYMOON CITY -- Badge 13 (live map)\\n"\n'
            '\t.string "LEADER LUNA · FAIRY · Moon Badge\\p"\n'
            '\t.string "Warp to TIDYMOON CITY?$"\n'
        ),
        "Eon": (
            'EasternAurelia_Hall_Text_DeskEon:\n'
            '\t.string "EON CITY -- Badge 14 (live map)\\n"\n'
            '\t.string "LEADER MORRIGAN · GHOST · Eon Badge\\p"\n'
            '\t.string "Warp to EON CITY?$"\n'
        ),
        "Genesis": (
            'EasternAurelia_Hall_Text_DeskGenesis:\n'
            '\t.string "GENESIS CITY -- Badge 15 (live map)\\n"\n'
            '\t.string "COLLEAGUE · MIXED · Genesis Badge\\p"\n'
            '\t.string "Warp to GENESIS CITY?$"\n'
        ),
        "Summit": (
            'EasternAurelia_Hall_Text_DeskSummit:\n'
            '\t.string "AURELIA SUMMIT (east) -- Badge 16 (live map)\\n"\n'
            '\t.string "MENTOR · MIXED · Ascension Badge\\p"\n'
            '\t.string "Warp to AURELIA SUMMIT?$"\n'
        ),
    }
    for desk, block in desk_text_map.items():
        tail2, n = re.subn(
            rf"EasternAurelia_Hall_Text_Desk{desk}:\n(?:\t\.string \"[^\"]*\"\n)+?",
            lambda _m, r=block: r,
            tail,
            count=1,
        )
        if n != 1:
            raise SystemExit(f"Failed desk text {desk} in tail (n={n})")
        tail = tail2

    out = (
        head
        + "\n".join(leader_blocks)
        + "\n"
        + mid_scripts
        + desk_mirage
        + "\n".join(desk_blocks)
        + "\n"
        + hall_dir
        + "".join(texts)
        + tail
    )
    path.write_text(out, encoding="utf-8")


def create_wt_lobby() -> None:
    folder = ROOT / "data/maps/WorldTournament_Lobby"
    mj = {
        "id": "MAP_WORLD_TOURNAMENT_LOBBY",
        "name": "WorldTournament_Lobby",
        "layout": "LAYOUT_WORLD_TOURNAMENT_LOBBY",
        "music": "MUS_B_TOWER",
        "region": "REGION_HOENN",
        "region_map_section": "MAPSEC_WORLD_TOURNAMENT",
        "requires_flash": False,
        "weather": "WEATHER_NONE",
        "map_type": "MAP_TYPE_INDOOR",
        "allow_cycling": False,
        "allow_escaping": False,
        "allow_running": False,
        "show_map_name": True,
        "battle_scene": "MAP_BATTLE_SCENE_NORMAL",
        "connections": None,
        "object_events": [
            {
                "local_id": "LOCALID_WT_ATTENDANT",
                "graphics_id": "OBJ_EVENT_GFX_TEALA",
                "x": 12,
                "y": 5,
                "elevation": 3,
                "movement_type": "MOVEMENT_TYPE_FACE_DOWN",
                "movement_range_x": 0,
                "movement_range_y": 0,
                "trainer_type": "TRAINER_TYPE_NONE",
                "trainer_sight_or_berry_tree_id": "0",
                "script": "WorldTournament_Lobby_EventScript_Attendant",
                "flag": "0",
            },
            {
                "graphics_id": "OBJ_EVENT_GFX_MAN_3",
                "x": 6,
                "y": 6,
                "elevation": 3,
                "movement_type": "MOVEMENT_TYPE_WANDER_AROUND",
                "movement_range_x": 1,
                "movement_range_y": 1,
                "trainer_type": "TRAINER_TYPE_NONE",
                "trainer_sight_or_berry_tree_id": "0",
                "script": "WorldTournament_Lobby_EventScript_Fan",
                "flag": "0",
            },
            {
                "graphics_id": "OBJ_EVENT_GFX_WOMAN_5",
                "x": 18,
                "y": 6,
                "elevation": 3,
                "movement_type": "MOVEMENT_TYPE_FACE_LEFT",
                "movement_range_x": 0,
                "movement_range_y": 0,
                "trainer_type": "TRAINER_TYPE_NONE",
                "trainer_sight_or_berry_tree_id": "0",
                "script": "WorldTournament_Lobby_EventScript_Rules",
                "flag": "0",
            },
        ],
        "warp_events": [
            {
                "x": 12,
                "y": 9,
                "elevation": 3,
                "dest_map": "MAP_BATTLE_FRONTIER_OUTSIDE_EAST",
                "dest_warp_id": "0",
            },
            {
                "x": 13,
                "y": 9,
                "elevation": 3,
                "dest_map": "MAP_BATTLE_FRONTIER_OUTSIDE_EAST",
                "dest_warp_id": "0",
            },
        ],
        "coord_events": [],
        "bg_events": [
            {
                "type": "sign",
                "x": 11,
                "y": 1,
                "elevation": 0,
                "player_facing_dir": "BG_EVENT_PLAYER_FACING_ANY",
                "script": "WorldTournament_Lobby_EventScript_Banner",
            }
        ],
    }
    write(folder / "map.json", json.dumps(mj, indent=2) + "\n")
    # Reuse Tower lobby WT scripts via duplicated attendant flow
    sc = r"""WorldTournament_Lobby_MapScripts::
	.byte 0

WorldTournament_Lobby_EventScript_Attendant::
	lock
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, WorldTournament_Lobby_EventScript_NotChamp
	goto_if_set FLAG_GENESIS_WT_CLEARED, WorldTournament_Lobby_EventScript_Rematch
	msgbox WorldTournament_Lobby_Text_Offer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, WorldTournament_Lobby_EventScript_Decline
	setflag FLAG_GENESIS_WT_INTRO
	msgbox WorldTournament_Lobby_Text_Round1, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GENESIS_MENTOR, WorldTournament_Lobby_Text_RoundLose
	msgbox WorldTournament_Lobby_Text_Round2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, WorldTournament_Lobby_Text_RoundLose
	msgbox WorldTournament_Lobby_Text_Semis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLACE, WorldTournament_Lobby_Text_RoundLose
	msgbox WorldTournament_Lobby_Text_Final, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GENESIS_WT_CHAMP, WorldTournament_Lobby_Text_Defeat
	setflag FLAG_GENESIS_WT_CLEARED
	msgbox WorldTournament_Lobby_Text_BP, MSGBOX_DEFAULT
	msgbox WorldTournament_Lobby_Text_After, MSGBOX_DEFAULT
	release
	end

WorldTournament_Lobby_EventScript_Rematch::
	msgbox WorldTournament_Lobby_Text_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, WorldTournament_Lobby_EventScript_Decline
	msgbox WorldTournament_Lobby_Text_Final, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GENESIS_WT_CHAMP, WorldTournament_Lobby_Text_Defeat
	msgbox WorldTournament_Lobby_Text_BP, MSGBOX_DEFAULT
	release
	end

WorldTournament_Lobby_EventScript_NotChamp::
	msgbox WorldTournament_Lobby_Text_NotChamp, MSGBOX_DEFAULT
	release
	end

WorldTournament_Lobby_EventScript_Decline::
	msgbox WorldTournament_Lobby_Text_Decline, MSGBOX_DEFAULT
	release
	end

WorldTournament_Lobby_EventScript_Fan::
	msgbox WorldTournament_Lobby_Text_Fan, MSGBOX_NPC
	end

WorldTournament_Lobby_EventScript_Rules::
	msgbox WorldTournament_Lobby_Text_Rules, MSGBOX_NPC
	end

WorldTournament_Lobby_EventScript_Banner::
	msgbox WorldTournament_Lobby_Text_Banner, MSGBOX_SIGN
	end

WorldTournament_Lobby_Text_Offer:
	.string "WORLD TOURNAMENT attendant.\\n"
	.string "Four-round bracket for Battle Points.\\p"
	.string "Enter the WORLD TOURNAMENT?$"

WorldTournament_Lobby_Text_Round1:
	.string "Round 1--MENTOR opens the bracket!$"

WorldTournament_Lobby_Text_Round2:
	.string "Round 2--ASTRA steps forward!$"

WorldTournament_Lobby_Text_Semis:
	.string "Semifinal--a Frontier legend awaits!$"

WorldTournament_Lobby_Text_Final:
	.string "Final--VICTOR of the WORLD TOURNAMENT!$"

WorldTournament_Lobby_Text_RoundLose:
	.string "The bracket ends here… Try again!$"

WorldTournament_Lobby_Text_Defeat:
	.string "The WORLD TOURNAMENT crown is yours!$"

WorldTournament_Lobby_Text_After:
	.string "Return any time for rematches.\\n"
	.string "The lobby stays open post-Champion.$"

WorldTournament_Lobby_Text_Rematch:
	.string "Rematch VICTOR for Battle Points?$"

WorldTournament_Lobby_Text_BP:
	.string "Battle Points credited--check the\\n"
	.string "Exchange Service Corner outside.$"

WorldTournament_Lobby_Text_NotChamp:
	.string "The WORLD TOURNAMENT opens after you\\n"
	.string "become CHAMPION of Aurelia.$"

WorldTournament_Lobby_Text_Decline:
	.string "When you're ready, the bracket waits.$"

WorldTournament_Lobby_Text_Fan:
	.string "I came from the Battle Tower just for\\n"
	.string "this lobby. The energy is different!$"

WorldTournament_Lobby_Text_Rules:
	.string "Four rounds. No healing between.\\n"
	.string "Bring your best six.$"

WorldTournament_Lobby_Text_Banner:
	.string "WORLD TOURNAMENT LOBBY\\n"
	.string "Eastern Aurelia's postgame bracket$"
"""
    write(folder / "scripts.inc", sc)


def patch_tower_lobby_pointer() -> None:
    """Point Tower boy NPC at the dedicated WT facility (keep inline bracket as legacy)."""
    path = ROOT / "data/maps/BattleFrontier_BattleTowerLobby/scripts.inc"
    text = path.read_text(encoding="utf-8")
    if "MAP_WORLD_TOURNAMENT_LOBBY" in text:
        return
    old = (
        "BattleFrontier_BattleTowerLobby_EventScript_Boy::\n"
        "\tlock\n"
        "\tfaceplayer\n"
        "\tgoto_if_unset FLAG_SYS_GAME_CLEAR, BattleFrontier_BattleTowerLobby_EventScript_BoyNormal\n"
        "\tgoto_if_set FLAG_GENESIS_WT_CLEARED, BattleFrontier_BattleTowerLobby_EventScript_WorldTournamentRematch\n"
    )
    new = (
        "BattleFrontier_BattleTowerLobby_EventScript_Boy::\n"
        "\tlock\n"
        "\tfaceplayer\n"
        "\tgoto_if_unset FLAG_SYS_GAME_CLEAR, BattleFrontier_BattleTowerLobby_EventScript_BoyNormal\n"
        "\tmsgbox BattleFrontier_BattleTowerLobby_Text_WorldTournamentFacility, MSGBOX_YESNO\n"
        "\tgoto_if_eq VAR_RESULT, NO, BattleFrontier_BattleTowerLobby_EventScript_BoyNormal\n"
        "\tmsgbox BattleFrontier_BattleTowerLobby_Text_WorldTournamentFacilityWarp, MSGBOX_DEFAULT\n"
        "\twarpsilent MAP_WORLD_TOURNAMENT_LOBBY, 12, 7\n"
        "\twaitstate\n"
        "\trelease\n"
        "\tend\n\n"
        "@ Legacy inline bracket (unused while facility warp is live)\n"
        "BattleFrontier_BattleTowerLobby_EventScript_BoyLegacyWT::\n"
        "\tlock\n"
        "\tfaceplayer\n"
        "\tgoto_if_unset FLAG_SYS_GAME_CLEAR, BattleFrontier_BattleTowerLobby_EventScript_BoyNormal\n"
        "\tgoto_if_set FLAG_GENESIS_WT_CLEARED, BattleFrontier_BattleTowerLobby_EventScript_WorldTournamentRematch\n"
    )
    if old not in text:
        raise SystemExit("Could not find Tower Boy WT hook")
    text = text.replace(old, new, 1)
    if "WorldTournamentFacility:" not in text:
        text += (
            "\nBattleFrontier_BattleTowerLobby_Text_WorldTournamentFacility:\n"
            '\t.string "The WORLD TOURNAMENT has a dedicated\\n"\n'
            '\t.string "lobby on the Frontier now.\\p"\n'
            '\t.string "Warp to the WORLD TOURNAMENT lobby?$"\n\n'
            "BattleFrontier_BattleTowerLobby_Text_WorldTournamentFacilityWarp:\n"
            '\t.string "Right this way--good luck!$"\n'
        )
    path.write_text(text, encoding="utf-8")


def bump_save_version() -> None:
    path = ROOT / "include/config/genesis.h"
    text = path.read_text(encoding="utf-8")
    text2, n = re.subn(
        r"#define GENESIS_SAVE_VERSION\s+\d+.*",
        "#define GENESIS_SAVE_VERSION                6 // Eastern cities 10-16 + WT lobby + gym trainers",
        text,
        count=1,
    )
    if n != 1:
        raise SystemExit("Failed to bump GENESIS_SAVE_VERSION")
    path.write_text(text2, encoding="utf-8")


def write_city_maps() -> None:
    for c in CITIES:
        f = c["folder"]
        write(ROOT / f"data/maps/{f}/map.json", city_map_json(c))
        write(ROOT / f"data/maps/{f}/scripts.inc", city_scripts(c))
        write(ROOT / f"data/maps/{f}_Gym/map.json", gym_map_json(c))
        write(ROOT / f"data/maps/{f}_Gym/scripts.inc", gym_scripts(c))
        mj1, sc1 = center_1f(c)
        write(ROOT / f"data/maps/{f}_PokemonCenter_1F/map.json", mj1)
        write(ROOT / f"data/maps/{f}_PokemonCenter_1F/scripts.inc", sc1)
        mj2, sc2 = center_2f(c)
        write(ROOT / f"data/maps/{f}_PokemonCenter_2F/map.json", mj2)
        write(ROOT / f"data/maps/{f}_PokemonCenter_2F/scripts.inc", sc2)
        mjm, scm = mart(c)
        write(ROOT / f"data/maps/{f}_Mart/map.json", mjm)
        write(ROOT / f"data/maps/{f}_Mart/scripts.inc", scm)


def main() -> int:
    write_city_maps()
    create_wt_lobby()
    ensure_layouts_json()
    ensure_map_groups()
    ensure_event_scripts()
    ensure_mapsec()
    ensure_heals()
    ensure_localids()
    ensure_opponents_and_party()
    rewrite_hall_scripts()
    patch_tower_lobby_pointer()
    bump_save_version()
    rc = subprocess.call([sys.executable, str(ROOT / "tools/genesis/build_eastern_layouts.py")])
    if rc != 0:
        return rc
    print("Eastern cities + WT lobby scaffolded OK")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
