# Sending an update to the Windhawk market

Windhawk only accepts an update from the account in the mod's `@github`, so this has to come from **Salyts**. The pull request must change just one file.

1. Update your fork, `Salyts/windhawk-mods`, from `ramensoftware/windhawk-mods`.
2. Copy `taskbar-fluent-media-player.wh.cpp` over `mods/taskbar-fluent-media-player.wh.cpp`.
3. Commit it with the commit message below, then open a pull request. Keep the pull request template and paste the changelog items below between its changelog markers.
4. Fix anything the automatic checks flag: any warning fails them. Then answer the AI review on the pull request, and comment `/ready-for-reviewer` once it's addressed.

## Commit message

```
Taskbar Fluent Media Player v1.7.0

Its own settings window, moving parts of the player, a seekable progress bar, monitor buttons and vertical taskbars.
```

## Pull request text

```markdown
## Changelog

<!-- changelog:start -->

* Its own settings window: right-click the player and pick Settings. Changes show live, and it comes in 15 languages with Mica and Acrylic backgrounds. Your settings carry over.
* Album art, track info, buttons and the visualizer can each be moved elsewhere on the taskbar or tray, with their own background and monitor.
* Progress bar you can click or drag to seek.
* Monitor buttons: pick a monitor, click it again to hide the player. Monitors that aren't connected stay gray.
* Vertical taskbars are supported.
* Visualizer: only moves with the app in the player (Windows 11), Line and Micro styles, can fill the background behind the player, choose its audio device, tune each band.
* Works again after the Windows updates that changed the system tray and taskbar.
* Fixes for the player not appearing at startup, media keys after an Explorer restart, session switching, album colors and more. Full list: https://github.com/Salyts/Taskbar-Fluent-Media-Player/blob/main/CHANGELOG.md

<!-- changelog:end -->
```

## Worth telling the reviewers

- The mod contacts no server. "Report a bug" copies a report to the clipboard and opens the mod's Discord invite in the browser.
- Settings saved in the settings window live in mod storage (`Wh_SetStringValue`), in a printable format that portable Windhawk keeps intact. Edits on Windhawk's Settings tab still come in, including ones made while the mod was off.
