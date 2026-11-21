# Sending an update to the Windhawk market

Windhawk only accepts an update from the account in the mod's `@github`, so this has to come from **Salyts**. The pull request must change just one file.

1. Update your fork, `Salyts/windhawk-mods`, from `ramensoftware/windhawk-mods`.
2. Copy `taskbar-fluent-media-player.wh.cpp` over `mods/taskbar-fluent-media-player.wh.cpp`.
3. Commit it with the commit message below, then open a pull request. Keep the pull request template and paste the changelog items below between its changelog markers.
4. Fix anything the automatic checks flag: any warning fails them. Then answer the AI review on the pull request, and comment `/ready-for-reviewer` once it's addressed.

## Commit message

```
Taskbar Fluent Media Player v1.7.1

Weather part, hiding Windows' own taskbar buttons, smooth song changes, real Mica/Acrylic/Glass backgrounds and lighter on power.
```

## Pull request text

```markdown
## Changelog

<!-- changelog:start -->

* Weather: the weather from Windows' Widgets button as a part of its own, anywhere on the taskbar. It can show only when nothing plays, or take the player's place.
* Hide Windows' own buttons: Start, Search, Task View, Widgets and tray items, and the year on the clock. The Layout page shows them and lets you place parts around them.
* Smooth song changes: the text fades and the player glides to its new width instead of jumping.
* Backgrounds: Mica, Mica Alt and Glass blur what's behind them, with a blur amount; Acrylic has separate tint and strength. Hover keeps the material.
* New looks: album art that spins like a record, a glow while playing, morphing album art, a compact mini player with its own visualizer, a seek bar that can be a visualizer.
* Progress bar: its own background color, hide when idle, show or grow on hover, or sit in the text as its own line.
* Lighter on power: visualizer frame rate, pause on battery saver, nothing animates with the screen off.
* Fixes: stale song after quick skips, settings saved safely, visualizer with Wave Link/Voicemeeter, the Layout page's taskbar copy, the player's width with only the cover in it, GitHub #114 to #117 and more. Full list: https://github.com/Salyts/Taskbar-Fluent-Media-Player/blob/main/CHANGELOG.md

<!-- changelog:end -->
```

## Worth telling the reviewers

- The mod contacts no server. "Report a bug" copies a report to the clipboard and opens the mod's Discord invite in the browser.
- Settings saved in the settings window live in mod storage (`Wh_SetStringValue`), in a printable format that portable Windhawk keeps intact. Edits on Windhawk's Settings tab still come in, including ones made while the mod was off.
