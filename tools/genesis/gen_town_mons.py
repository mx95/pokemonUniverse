#!/usr/bin/env python3
"""Generate data/scripts/genesis_town_mons.inc"""
from pathlib import Path

QUESTS = [
    (0, "Lumen", "SPECIES_SHAYMIN_LAND", 30, "ITEM_LUM_BERRY",
     "They say a Gratitude Pokémon sleeps in\\nthe flower beds when LUMEN is kind.\\p"
     "SHAYMIN blooms where pure hearts gather.\\nWill you greet it?",
     "SHAYMIN's flowers stir… Challenge it?",
     "The petals settle…",
     "Offer a home to the Gratitude Pokémon?",
     "SHAYMIN trusts you now.",
     "SHAYMIN's meadow remembers your kindness."),
    (1, "Ironridge", "SPECIES_KELDEO", 28, "ITEM_NONE",
     "Ironridge forges more than steel--\\nit forges will.\\p"
     "A Colt Pokémon trains at the shore,\\nseeking the Secret Sword of resolve.",
     "Face KELDEO's trial?",
     "Its blade of water stills…",
     "Invite KELDEO to travel with you?",
     "KELDEO nods--your paths align.",
     "KELDEO still drills at dawn."),
    (2, "PortAzure", "SPECIES_MANAPHY", 35, "ITEM_MYSTIC_WATER",
     "Port Azure tides once cradled a Seafaring\\nPokémon--prince of the ocean.\\p"
     "MANAPHY washes ashore when trainers\\nprotect the bay.",
     "Answer MANAPHY's call?",
     "The sea grows calm…",
     "Take MANAPHY under your care?",
     "MANAPHY sparkles with joy.",
     "The bay still sings for MANAPHY."),
    (4, "Frostveil", "SPECIES_REGICE", 40, "ITEM_NEVER_MELT_ICE",
     "Frostveil's springs hide a paradox--\\nice sealed beneath heat.\\p"
     "REGICE, the Iceberg Pokémon, waits in\\na cold vault under the spa rocks.",
     "Wake REGICE?",
     "Ancient ice cracks… then stills.",
     "Bind REGICE to your team?",
     "REGICE's frost accepts you.",
     "The ice vault stays quiet."),
    (5, "Solaris", "SPECIES_ENTEI", 42, "ITEM_CHARCOAL",
     "Solaris worships the sun.\\nWhen volcanoes birthed legends,\\p"
     "ENTEI--Volcano Pokémon--raced the\\nridges, leaving ash-flowers in its wake.",
     "Race ENTEI's flame?",
     "The ridge cools…",
     "Walk beside ENTEI?",
     "ENTEI's roar becomes your beacon.",
     "Ash-flowers still mark its path."),
    (6, "Stormbreak", "SPECIES_TORNADUS", 48, "ITEM_NONE",
     "Stormbreak cliffs call the Gale Pokémon.\\nTORNADUS whips sea and sky into fury\\p"
     "when respect for the wind is forgotten.",
     "Stand against TORNADUS?",
     "The gale softens…",
     "Partner with TORNADUS?",
     "TORNADUS circles you once--accepted.",
     "Winds still bow at Stormbreak."),
    (7, "Titania", "SPECIES_JIRACHI", 50, "ITEM_STAR_PIECE",
     "Titania's steel mirrors catch falling\\nstars. Myths say JIRACHI--Wish Pokémon--\\p"
     "sleeps a thousand years, waking for a\\nweek of wishes in a meteor cradle.",
     "Wake JIRACHI's dream?",
     "Starlight fades gently…",
     "Will you grant JIRACHI a journey?",
     "JIRACHI's tags flutter--wish shared.",
     "The meteor cradle glimmers softly."),
    (8, "Mirage", "SPECIES_CRESSELIA", 55, "ITEM_NONE",
     "Mirage City bends light and dream.\\nCRESSELIA, the Lunar Pokémon, soothes\\p"
     "nightmares--its crescent veil steadies\\nminds lost in illusion.",
     "Call CRESSELIA?",
     "Moonlight settles…",
     "Travel with CRESSELIA?",
     "CRESSELIA's veil wraps your team.",
     "Dreams in Mirage stay gentle."),
    (9, "Verdantis", "SPECIES_GENESECT", 56, "ITEM_NONE",
     "Verdantis insect labs restored an ancient\\nUltra weapon--GENESECT, the Paleozoic\\p"
     "Pokémon, cannon and all. It seeks a\\ntrainer, not a cage.",
     "Challenge GENESECT?",
     "The cannon powers down…",
     "Free GENESECT as a partner?",
     "GENESECT's drive hums in sync.",
     "The lab monitors stay green."),
    (10, "Obsidian", "SPECIES_DARKRAI", 58, "ITEM_NONE",
     "Obsidian's vents birth bad dreams.\\nDARKRAI, the Pitch-Black Pokémon, was\\p"
     "blamed for every nightmare--yet it only\\nseeks a place without fear.",
     "Confront DARKRAI?",
     "The nightmares thin…",
     "Offer DARKRAI sanctuary?",
     "DARKRAI fades into your shadow--ally.",
     "Night in Obsidian grows quieter."),
    (11, "Astral", "SPECIES_LATIOS", 60, "ITEM_SOUL_DEW",
     "Astral's observatory tracks Eon Pokémon.\\nLATIOS shares compassion across distance,\\p"
     "guiding those who chart the sky with\\ncare, not conquest.",
     "Meet LATIOS in battle?",
     "The sky-blue aura dims…",
     "Fly with LATIOS?",
     "LATIOS opens a telepathic bond.",
     "Astral scopes still track your friend."),
    (12, "Tidymoon", "SPECIES_ENAMORUS", 62, "ITEM_NONE",
     "Tidymoon tides swell with Love-Hate\\nenergy. ENAMORUS arrives when hearts\\p"
     "and seasons turn--fairy force of spring\\noff the moonlit coast.",
     "Dance with ENAMORUS?",
     "Petals of foam settle…",
     "Journey with ENAMORUS?",
     "ENAMORUS smiles--spring follows you.",
     "Tide pools still glow at night."),
    (13, "Eon", "SPECIES_MARSHADOW", 63, "ITEM_NONE",
     "Eon City's bells hide a Gloomdweller.\\nMARSHADOW lives in shadows, copying the\\p"
     "moves of warriors it respects.",
     "Draw MARSHADOW out?",
     "The shadow stills…",
     "Let MARSHADOW walk in your shade?",
     "MARSHADOW bows--student of your style.",
     "Bells toll softer now."),
    (14, "GenesisCity", "SPECIES_MELOETTA", 64, "ITEM_NONE",
     "Genesis City is AURELIA's hub of arts\\nand prep. MELOETTA--Melody Pokémon--\\p"
     "answers when many voices train as one.",
     "Perform against MELOETTA?",
     "The song resolves…",
     "Invite MELOETTA on tour?",
     "MELOETTA's aria becomes your theme.",
     "Street musicians still hum its tune."),
    (15, "Summit", "SPECIES_REGIROCK", 65, "ITEM_HARD_STONE",
     "The eastern Summit keeps a Rock Peak\\ngolem. REGIROCK's body is pure stone\\p"
     "from every era--Mentor's trial beyond\\nthe stone badges.",
     "Strike REGIROCK?",
     "Pebbles cease falling…",
     "Command REGIROCK?",
     "REGIROCK's eyes glow acceptance.",
     "The peak stones remember you."),
    (16, "Venom", "SPECIES_PECHARUNT", 66, "ITEM_NONE",
     "Venom Hollow's mochi myths were true.\\nPECHARUNT binds with toxic hospitality--\\p"
     "yet it can learn trust instead of chains.",
     "Break PECHARUNT's binding bout?",
     "The sweet scent fades…",
     "Reform PECHARUNT as an ally?",
     "PECHARUNT offers a toxin-free pact.",
     "Hollow vapors smell cleaner."),
    (17, "Terracotta", "SPECIES_LANDORUS", 70, "ITEM_NONE",
     "Terracotta Mesa thrives when LANDORUS--\\nAbundance Pokémon--blesses the soil.\\p"
     "It tests those who would till ground\\nwithout greed.",
     "Earn LANDORUS's blessing?",
     "Dust settles into fertile quiet…",
     "Travel with LANDORUS?",
     "LANDORUS crowns your journey.",
     "Mesa crops grow taller since then."),
]


def main() -> None:
    out: list[str] = []
    out.append("@ GENESIS: Per-gym-town lore Pokémon (Metagross-style catch quests)\n\n")
    out.append("Genesis_EventScript_TownMon_Decline::\n")
    out.append("\tmsgbox Genesis_Text_TownMon_GenericDecline, MSGBOX_DEFAULT\n")
    out.append("\trelease\n\tend\n\n")
    out.append("Genesis_Text_TownMon_GenericDecline:\n")
    out.append('\t.string "Another time, then.$"\n\n')
    out.append("Genesis_Text_TownMon_CatchFail:\n")
    out.append('\t.string "It broke free… Try again when ready.$"\n\n')
    out.append("Genesis_Text_TownMon_CatchLater:\n")
    out.append('\t.string "It waits nearby. Return when prepared.$"\n\n')

    for idx, label, species, level, item, lore, challenge, defeat, catch_offer, caught, done in QUESTS:
        p = f"TownMon_{label}"
        out.append(f"Genesis_EventScript_{p}::\n")
        out.append("\tlock\n\tfaceplayer\n")
        out.append(f"\tsetvar VAR_0x8004, {idx}\n")
        out.append("\tcallnative Genesis_TownMonIsDone\n")
        out.append(f"\tgoto_if_eq VAR_RESULT, TRUE, Genesis_EventScript_{p}_Done\n")
        out.append(f"\tgoto_if_set FLAG_TEMP_A, Genesis_EventScript_{p}_OfferCatch\n")
        out.append(f"\tmsgbox Genesis_Text_{p}_Lore, MSGBOX_DEFAULT\n")
        out.append(f"\tmsgbox Genesis_Text_{p}_Challenge, MSGBOX_YESNO\n")
        out.append("\tgoto_if_eq VAR_RESULT, NO, Genesis_EventScript_TownMon_Decline\n")
        out.append("\tclosemessage\n")
        out.append(f"\tsetwildbattle {species}, {level}, {item}\n")
        out.append(
            f"\tcreatemon B_SIDE_OPPONENT, 0, {species}, {level}, "
            f"item={item}, shinyMode=SHINY_MODE_ALWAYS\n"
        )
        out.append("\tsettotemboost B_POSITION_OPPONENT_LEFT, 1, 0, 0, 1, 1\n")
        out.append("\tspecial BattleSetup_StartLegendaryBattle\n")
        out.append("\tspecialvar VAR_RESULT, GetBattleOutcome\n")
        out.append(f"\tgoto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_{p}_Caught\n")
        out.append(f"\tgoto_if_eq VAR_RESULT, B_OUTCOME_WON, Genesis_EventScript_{p}_Won\n")
        out.append("\tmsgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT\n")
        out.append("\trelease\n\tend\n\n")

        out.append(f"Genesis_EventScript_{p}_Won::\n")
        out.append("\tsetflag FLAG_TEMP_A\n")
        out.append(f"\tmsgbox Genesis_Text_{p}_Defeat, MSGBOX_DEFAULT\n")
        out.append(f"\tgoto Genesis_EventScript_{p}_OfferCatch\n\tend\n\n")

        out.append(f"Genesis_EventScript_{p}_OfferCatch::\n")
        out.append(f"\tmsgbox Genesis_Text_{p}_CatchOffer, MSGBOX_YESNO\n")
        out.append(f"\tgoto_if_eq VAR_RESULT, NO, Genesis_EventScript_{p}_CatchLater\n")
        out.append("\tclosemessage\n")
        out.append(f"\tsetwildbattle {species}, {level}, {item}\n")
        out.append(
            f"\tcreatemon B_SIDE_OPPONENT, 0, {species}, {level}, "
            f"item={item}, shinyMode=SHINY_MODE_ALWAYS, "
            f"hpEv=0, atkEv=0, defEv=0, speedEv=0, spAtkEv=0, spDefEv=0\n"
        )
        out.append("\tsettotemboost B_POSITION_OPPONENT_LEFT, 0, 0, 0, 0, 0\n")
        out.append("\tspecial BattleSetup_StartLegendaryBattle\n")
        out.append("\tspecialvar VAR_RESULT, GetBattleOutcome\n")
        out.append(f"\tgoto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, Genesis_EventScript_{p}_Caught\n")
        out.append("\tmsgbox Genesis_Text_TownMon_CatchFail, MSGBOX_DEFAULT\n")
        out.append("\trelease\n\tend\n\n")

        out.append(f"Genesis_EventScript_{p}_CatchLater::\n")
        out.append("\tmsgbox Genesis_Text_TownMon_CatchLater, MSGBOX_DEFAULT\n")
        out.append("\trelease\n\tend\n\n")

        out.append(f"Genesis_EventScript_{p}_Caught::\n")
        out.append(f"\tsetvar VAR_0x8004, {idx}\n")
        out.append("\tcallnative Genesis_TownMonSetDone\n")
        out.append("\tclearflag FLAG_TEMP_A\n")
        out.append(f"\tmsgbox Genesis_Text_{p}_Caught, MSGBOX_DEFAULT\n")
        out.append("\trelease\n\tend\n\n")

        out.append(f"Genesis_EventScript_{p}_Done::\n")
        out.append(f"\tmsgbox Genesis_Text_{p}_Done, MSGBOX_DEFAULT\n")
        out.append("\trelease\n\tend\n\n")

        out.append(f"Genesis_Text_{p}_Lore:\n\t.string \"{lore}$\"\n\n")
        out.append(f"Genesis_Text_{p}_Challenge:\n\t.string \"{challenge}$\"\n\n")
        out.append(f"Genesis_Text_{p}_Defeat:\n\t.string \"{defeat}$\"\n\n")
        out.append(f"Genesis_Text_{p}_CatchOffer:\n\t.string \"{catch_offer}$\"\n\n")
        out.append(f"Genesis_Text_{p}_Caught:\n\t.string \"{caught}$\"\n\n")
        out.append(f"Genesis_Text_{p}_Done:\n\t.string \"{done}$\"\n\n")

    path = Path("data/scripts/genesis_town_mons.inc")
    path.write_text("".join(out), encoding="utf-8", newline="\n")
    print(f"wrote {path} ({path.stat().st_size} bytes)")


if __name__ == "__main__":
    main()
