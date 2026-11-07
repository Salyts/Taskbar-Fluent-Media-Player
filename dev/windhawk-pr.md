# Sending an update to the Windhawk market

Windhawk only accepts an update from the account in the mod's `@github`, so this has to come from **Salyts**. The pull request must change just one file.

1. Update your fork, `Salyts/windhawk-mods`, from `ramensoftware/windhawk-mods`.
2. Copy `taskbar-fluent-media-player.wh.cpp` over `mods/taskbar-fluent-media-player.wh.cpp`.
3. Commit it with the commit message below, then open a pull request. Keep the pull request template and paste the changelog items below between its changelog markers.
4. Fix anything the automatic checks flag. It will ask for a manual look at the `WH_EDITING` lines: they keep the Composition headers out of Windhawk's editor, which ran out of memory on them.

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

- The bug report button sends what the user reports to a Discord webhook, including their PC name and Windows user name. The form says so, and nothing is sent unless they press it.
- `-lwinhttp` is for that report, and `-lwevtapi` reads Explorer crashes from the Windows log for it.
