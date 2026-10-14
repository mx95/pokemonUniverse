# Genesis playtest checklist

Run against `pokemonGenesis.gba` in mGBA (or equivalent). Mark items as you go.

## Intro / early

- [ ] New Game: Corviknight taxi intro (no truck text)
- [ ] Corviknight flies up and vanishes before Mom opens the door
- [ ] Verdant / Lumen / Route 1 branding on signs and map name popup
- [ ] Birch Lab grants DexNav (search + detector)

## Boutique / outfits (Lilycove Dept Store 5F)

- [ ] Buy Red Scarf look — OW clothes/trim turn red-gold immediately
- [ ] Buy Blue Scarf look (Badge 6+) — OW turns blue-ice
- [ ] Buy Forest look — OW turns verdant green
- [ ] Buy Eclipse look — OW turns dark/purple
- [ ] After Champion: buy Pink Champion look — OW turns pink-gold
- [ ] Wear menu cycles Default / Red / Blue / Champion / Forest / Eclipse and refreshes OW

## Early Aurelia vibe

- [ ] Verdant / Lumen / Port Azure use distinct outdoor tile colors (not identical greens)
- [ ] Port Azure: cloudy sky + fisher/sailor flavor lines
- [ ] Route 102 cloudy; Route 103 shade
- [ ] Genesis City outdoor theme is Ever Grande (not Petalburg)

## Eastern Aurelia (post-Champion)

- [ ] Reception Gate greeter → Eastern Hall
- [ ] Hall clerk INFO → jukebox plays a town theme, then Chaos toggle
- [ ] Fly map shows Mirage→Terracotta cluster east of Frontier
- [ ] Fly to Mirage / Verdantis / Terracotta lands at heal coords
- [ ] Each city: distinct weather (drought/rain/shade/fog/snow/sandstorm…)
- [ ] Flavor NPCs talk; transit attendant returns to Hall
- [ ] Gym rematch YES after badge (no second badge gift)
- [ ] Quest board lists badges 9–18 individually

## Legends / Form

- [ ] Legend Sanctum: Aethernox / Solara / Genesis use **new** battle fronts (not stock Giratina/Reshiram/Arceus silhouettes)
- [ ] Back sprites are flipped custom art (palette matches front)
- [ ] Party icons + OW followers match custom legend art (not stock Giratina/Reshiram/Arceus)
- [ ] Rematch after first clear (no second held-item gift)
- [ ] All three → Genesis Form unlock message; SPECIES_GENESIS switch-in overlay

## Smoke (automated)

```bash
make -j$(nproc)
make genesis-check
```
