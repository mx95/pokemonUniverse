#!/usr/bin/env python3
"""Generate data/scripts/genesis_town_mons.inc — non-legendary / pseudo-tier town quests."""
from pathlib import Path

# Totem-style town quests: NEVER starter lines (gym specialists may use starters).
# Prefer type-fitting pseudos / high-BST specialists.
# Early badges (1-5): mid-stage / pre-evolutions scaled to story timing.
QUESTS = [
    (0, "Lumen", "SPECIES_TANGELA", 18, "ITEM_MIRACLE_SEED",
     "LUMEN vines tangled around a wild TANGELA--\\nthe Vine Pokémon that drinks dew.\\p"
     "Grow it well and it may become TANGROWTH.\\nWill you face its coils?",
     "Challenge the grove's TANGELA?",
     "The vines go slack…",
     "Invite TANGELA to your party?",
     "TANGELA's vines loosen--friendship.",
     "LUMEN's grove still smells of sap."),
    (1, "Ironridge", "SPECIES_HAKAMO_O", 22, "ITEM_NONE",
     "Ironridge caves temper more than ore.\\nA HAKAMO-O--Scaly Pokémon--trains\\p"
     "there, shedding for stronger armor.\\nOne day it may become KOMMO-O.",
     "Spar with HAKAMO-O?",
     "The clanging ceases…",
     "Travel with HAKAMO-O?",
     "HAKAMO-O bows--scales still humming.",
     "Cave walls still ring at dawn."),
    (2, "PortAzure", "SPECIES_SEADRA", 28, "ITEM_MYSTIC_WATER",
     "Port Azure reefs hide a proud SEADRA--\\nthe Dragon Pokémon of the currents.\\p"
     "Trade it a DREAM SCALE someday and it\\nmay become KINGDRA of the deep.",
     "Face SEADRA on the pier?",
     "The tide goes glass-smooth…",
     "Ask SEADRA to sail with you?",
     "SEADRA spirals beside you, calm.",
     "Harbor waters stay kinder now."),
    (4, "Frostveil", "SPECIES_ARCTIBAX", 34, "ITEM_NEVER_MELT_ICE",
     "Frostveil's paradox springs hid a nest.\\nARCTIBAX--Ice Fighter Pokémon--guards\\p"
     "the cold vault. Keep training it and\\nit may become BAXCALIBUR.",
     "Challenge ARCTIBAX?",
     "Frost settles on the stone…",
     "Partner with ARCTIBAX?",
     "ARCTIBAX sheaths its icy crest.",
     "The vault ice stays unbroken."),
    (5, "Solaris", "SPECIES_HOUNDOOM", 38, "ITEM_CHARCOAL",
     "Solaris sun-ridges raised a HOUNDOOM\\nwhose howls scorch the night air.\\p"
     "The Dark Pokémon of flame--no starter\\nstock, only volcanic hunting packs.",
     "Face HOUNDOOM's heat?",
     "Embers cool on the rock…",
     "Hunt with HOUNDOOM?",
     "HOUNDOOM pads into your shadow.",
     "Ridge ash still marks its path."),
    (6, "Stormbreak", "SPECIES_SALAMENCE", 48, "ITEM_NONE",
     "Stormbreak cliffs hatch dreamers.\\nSALAMENCE--Dragon Pokémon--finally\\p"
     "earned its wings here. Wind and fang\\nrival any gale legend.",
     "Race SALAMENCE in the sky?",
     "Wingtips fold at last…",
     "Fly with SALAMENCE?",
     "SALAMENCE opens a wing for you.",
     "Clifftop nests stay watched."),
    (7, "Titania", "SPECIES_ARCHALUDON", 50, "ITEM_METAL_COAT",
     "Titania's bridgeworks woke an ARCHALUDON--\\nAlloy Pokémon of living steel.\\p"
     "It braces the city like a walking\\nfortress. Pseudo-tier bulk, pure STEEL.",
     "Test ARCHALUDON's girders?",
     "Metal stress-lines ease…",
     "Command ARCHALUDON?",
     "ARCHALUDON locks in beside you.",
     "Bridge cables hum softer now."),
    (8, "Mirage", "SPECIES_GARDEVOIR", 55, "ITEM_TWISTED_SPOON",
     "Mirage psychics bond with GARDEVOIR--\\nthe Embrace Pokémon that protects\\p"
     "trainers with its life. Illusion and\\nempathy are its battlefield.",
     "Duel MIRAGE's GARDEVOIR?",
     "The mind-fog lifts…",
     "Bond with GARDEVOIR?",
     "GARDEVOIR's aura steadies yours.",
     "Mirage minds sleep easier."),
    (9, "Verdantis", "SPECIES_VOLCARONA", 56, "ITEM_SILVER_POWDER",
     "Verdantis bug labs reared a VOLCARONA\\nfrom a LARVESTA cocoon--Sun Pokémon\\p"
     "whose scales once warmed continents.\\nBug power at near-pseudo strength.",
     "Face VOLCARONA's heat?",
     "Solar dust drifts down…",
     "Raise VOLCARONA yourself?",
     "VOLCARONA's wings shield you.",
     "Lab lamps glow amber since then."),
    (10, "Obsidian", "SPECIES_HYDREIGON", 58, "ITEM_NONE",
     "Obsidian vents raised a brutal HYDREIGON--\\nBrutal Pokémon, three heads of DARK.\\p"
     "A classic pseudo-legend that learned\\nto hunt in volcanic night.",
     "Stare down HYDREIGON?",
     "All three heads lower…",
     "Claim HYDREIGON as an ally?",
     "HYDREIGON's rage focuses for you.",
     "Vent shadows feel less hungry."),
    (11, "Astral", "SPECIES_DRAGONITE", 60, "ITEM_DRAGON_FANG",
     "Astral scopes track a DRAGONITE ferrying\\nstorm-lost ships--the Dragon Pokémon\\p"
     "every trainer names as the first\\npseudo-legend of the skies.",
     "Challenge DRAGONITE?",
     "Gale and wingbeat still…",
     "Journey with DRAGONITE?",
     "DRAGONITE rumbles warmly.",
     "Astral logs keep its flight path."),
    (12, "Tidymoon", "SPECIES_TOGEKISS", 62, "ITEM_NONE",
     "Tidymoon tides bless kind hearts.\\nTOGEKISS--Jubilee Pokémon--appears\\p"
     "where peace is kept. Fairy grace\\nwithout needing a mythical seal.",
     "Dance against TOGEKISS?",
     "Moonlit feathers settle…",
     "Travel with TOGEKISS?",
     "TOGEKISS circles you once, joyful.",
     "Tide shrines stay flowered."),
    (13, "Eon", "SPECIES_DRAGAPULT", 63, "ITEM_NONE",
     "Eon City's bells hid a DRAGAPULT nest--\\nStealth Pokémon that launches DREEPY\\p"
     "like living missiles. Ghost-dragon\\npseudo power in the belfry dark.",
     "Intercept DRAGAPULT?",
     "The belfry goes still…",
     "Crew up with DRAGAPULT?",
     "DRAGAPULT stows its DREEPY for you.",
     "Bells toll cleaner at dusk."),
    (14, "GenesisCity", "SPECIES_SLAKING", 64, "ITEM_NONE",
     "Genesis City's training yards host a\\nSLAKING--Lazy Pokémon with monstrous\\p"
     "NORMAL power that outclasses most\\nlegends… when it bothers to move.",
     "Rouse SLAKING to battle?",
     "It yawns… then yields.",
     "Can you keep SLAKING motivated?",
     "SLAKING shuffles into your care.",
     "Yard trainers still tip-toe past it."),
    (15, "Summit", "SPECIES_TYRANITAR", 65, "ITEM_HARD_STONE",
     "The Summit's fault line woke a TYRANITAR--\\nArmor Pokémon, ROCK and DARK pseudo.\\p"
     "Sandstorms answer its roar. Mentor\\ncalls it the mountain's true trial.",
     "Stand against TYRANITAR?",
     "The sandstorm breaks…",
     "Command TYRANITAR?",
     "TYRANITAR's armor accepts you.",
     "Summit stone still bears its claw."),
    (16, "Venom", "SPECIES_GENGAR", 66, "ITEM_POISON_BARB",
     "Venom Hollow's mist hides a GENGAR--\\nShadow Pokémon steeped in toxins.\\p"
     "Not a mythic binder, just a cunning\\nPOISON trickster of the vapor vents.",
     "Outwit GENGAR?",
     "The grin fades into mist…",
     "Let GENGAR haunt your shadow?",
     "GENGAR chuckles--deal struck.",
     "Hollow vapors feel less biting."),
    (17, "Terracotta", "SPECIES_GARCHOMP", 70, "ITEM_SOFT_SAND",
     "Terracotta Mesa's dunes birthed a\\nGARCHOMP--Mach Pokémon, land shark\\p"
     "and GROUND-type pseudo-legend. Soil\\nremembers every stride it takes.",
     "Race GARCHOMP across the mesa?",
     "Dust settles in its wake…",
     "Hunt alongside GARCHOMP?",
     "GARCHOMP fins the air--accepted.",
     "Mesa crops root deeper since then."),
]


def main() -> None:
    out: list[str] = []
    out.append("@ GENESIS: Per-gym-town lore Pokémon (non-legendary / pseudo-tier)\n\n")
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
