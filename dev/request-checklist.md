# Request checklist (GitHub issues and PRs closed 2026-10-03)

Everything people asked for, one line each. Mark `[x]` for works in 1.7 and
leave `[ ]` for not yet. The issue number is in brackets.

## Bugs

New since 2026-11-11 (fixed or added on the `1.7.1` branch; replies in `issue-replies.md`, not posted):

- [x] Progress bar hidden when its part (buttons, info) is hidden (#117) — the bar spans the player instead
- [x] Progress bar click/drag does nothing (#116) — the seek code works; their app likely refuses seeks, and a refused seek no longer moves the bar
- [x] Single click runs together with the double click (#115) — Behaviour: "A double-click doesn't run the single click too"; a left double-click no longer runs the single click twice
- [x] "Open media app" does nothing with the app in the tray (#114) — starts the app's exe again, which brings up Spotify, AIMP and other one-instance apps
- [ ] Player won't move left (#111) — no details; likely the left-align report from Discord, waiting on logs
- [x] Player stuck at the right of the tray with any taskbar position (#124) — on 26H2 (26300) the taskbar frame is the XAML root itself, so RootGrid was never found and every taskbar position fell back to the tray
- [ ] Smart App Control blocks the 1.7.0 DLL (#119) — Windhawk/Windows signing, not something the mod can change
- [ ] Riff app not recognized (#100) — needs a check that Riff shows in Windows' own media controls (Win + A)

New since the 2026-10-03 cleanup (replies drafted in `issue-replies.md`, not posted):

- [x] "Tray - Left of Tray Icons" stopped working after a Windows update (#91) — 1.7 handles the StackPanel tray; tray anchors now use the tray's direct child, and a missing anchor puts the player at the tray start instead of nowhere
- [x] Tray placement on the new StackPanel tray (PR #87) — covered, plus the direct-child/ColumnSpan fix from the PR
- [x] "It no work" after the September Windows update (#89) — 1.6 issue, fixed in 1.7
- [x] Floating Taskbar Styler themes: margins make the taskbar wider (#88) — Layout: "Media player offset (x y)" moves the player without taking room

Windows 26300.9711 (2026-10-18):

- [x] Player and every detached part gone with nothing fullscreen — Do Not Disturb makes Windows report "busy", which the fullscreen check (since 1.6) read as fullscreen. Busy now only counts when the window in front really covers its monitor
- [x] Mod not loading at all after the update — Windhawk's symbol download for the new taskbar.dll failed once and it cached the error; fixed on this PC by putting the PDB in Windhawk's cache (nothing in the mod to change, the hooked functions are identical)
- [x] Visualizer reacts to every sound, Discord included (#93, also #85) — Visualizer: "Only listen to the app in the player" (on by default, per-app capture on Windows 11)
- [x] Vertical taskbar support (#98) — already in 1.7 (sidebar mode)

Older:


- [x] Spotify not picked up, other apps are (#6) — you confirmed it works
- [ ] Taskbar freezes and Explorer restarts after enabling the mod, with pear-desktop playing; clock stops, tray tooltips gone (#20)
- [x] Player stays on a paused app while another one is playing (#22) — auto-switch + sticky pick
- [x] Pause only works half the time in Zen browser (#26) — explicit play/pause from 1.6.0 restored (1.7 had lost it)
- [x] Old album art stays when a browser track has no art (#33) — you confirmed it works
- [x] Player flashes another app for a moment when the playing app changes tracks (#34) — sticky last-playing app + 1.5 s grace
- [x] High GPU use while the visualizer is on and nothing plays (#41) — half-pixel bar steps + 100 ms frames after 1 s of silence
- [x] "Nothing happened": player never shows, log says HookTaskbarDllSymbols failed (#49) — you confirmed it works
- [x] Media keys stop working everywhere after an Explorer restart or reboot until the mod is toggled (#52) — you confirmed it works
- [x] Browser music/video not shown, only Telegram voice messages; player shows for a second and disappears when changing position (#55) — you confirmed it works
- [x] Light/dark switch: solid background turns transparent (light to dark) or dark (dark to light) (#57) — you confirmed it works
- [x] Ignoring firefox.exe doesn't hide Facebook reels in Firefox (#66) — ignore list also matches the window's exe
- [x] With Windows 11 Taskbar Styler "Borderless" the player goes under the icons (#74) — you confirmed it works
- [x] With Taskbar Styler "matter" or "squircle" themes Explorer bootloops (#74) — crash breaker + anchor checks (needs a retest with those themes)
- [x] Gap between player and Widgets when set to "Right of Widgets" (#74) — zero-width anchor fix
- [x] "Hide when no media" hides the player but it keeps taking space (#14) — you confirmed it works

## Visualizer

- [x] Hide the visualizer when nothing plays (dots stay visible) (#14) — Visualizer: "Hide the visualizer when nothing is playing"
- [x] Line style visualizer that matches the taskbar's line icons (#16) — Visualizer: "Style" = Line (one thin stroke; closed outline with the middle anchor)
- [x] Micro visualizer that fits next to the artist text (#16) — Visualizer: "Placement" = Micro, next to the artist text
- [x] Visualizer for a non-default audio device (#17) — Visualizer: "Audio device" (part of the device name; empty = default output)
- [x] Pick which playback/recording device the visualizer listens to (VB-Audio Matrix / DAW routing) (#50) — same setting; recording devices are captured directly, playback ones as loopback
- [ ] Smoother look / more resolution between frequencies (#51)
- [x] Throttle or pause rendering on silence (#41) — same fix as above

## Player and layout

- [ ] Player as its own separate capsule/dock instead of merging into the centered taskbar background (#8)
- [ ] New positions inside TaskbarFrame / SystemTrayFrame, left and right (#8)
- [ ] StartAllBack compatibility (#8, asked in a comment)
- [ ] Show the player on all taskbars / choose which taskbars (#15, #90) — 1.7 picks one monitor or none with buttons; several at once is the plan for the next version (see FUTURE.md)
- [ ] Align on the left of the taskbar without being an overlay (#74)
- [x] Hide the whole player while paused (media open but not playing), after a short delay (#14) — Behaviour: "Hide while paused after (seconds)" (was "Idle auto-hide timeout"; it now counts real seconds)

## Text

- [x] Show the album name instead of the artist (#38) — Info: "Second line shows" = Album name
- [x] Show the album name only when there's no album art (#38) — "Album name when there's no album art"
- [x] Custom text format with placeholders like %title%, %artist%, %album%, %artist_or_album% (#38) — Info: "Title format" and "Second line format" (empty = as before)
- [ ] Synced lyrics (LRCLIB) (#27, PR #21 with karaoke highlight)

## Clicks and actions

- [x] Scroll over the player buttons to seek (#123) — mouse wheel action "Skip 5 seconds back or forward"
- [x] Always show the app icon instead of album art (#113) — Album Art: "Album art shows" = The app's icon
- [x] Always show the stand-in icon instead of album art (#120) — Album Art: "Album art shows" = An icon
- [ ] Center the player buttons and spread them evenly (#118)
- [ ] Keyboard shortcut to open the mini player (#106)
- [x] Default app to launch when clicking the player with nothing playing (#23) — Behaviour: "App to open when nothing is playing"
- [ ] Run a script / send a keybind / open an app on click, per area (player, art, title, buttons, visualizer) (#25)
- [ ] Custom context menu items (#25)
- [x] "Close / minimize media app" click action (#53) — "Minimize media app" and "Open or minimize media app" actions
- [x] Close the media app (#53, comment) — "Close media app" click action (a separate button is still open)

## Mini player menu

- [x] Mica and Mica Alt menu background (#112) — Mini Player Menu: "Menu background" = Mica, Mica Alt (Mica's look; the menu can't have real Mica)
- [x] Hide the empty artwork placeholder (#122) — Mini Player Menu: "Hide the cover area without a cover"
- [x] Scroll over the seek bar to skip (#121) — the wheel over the mini player's seek bar skips 5 seconds
- [x] Acrylic / mica / gradient background options (#48) — Mini Player Menu: "Menu background" = Acrylic, Solid color, Album colors gradient, Blurred album cover (+ color and opacity). No separate Mica: the taskbar's XAML has no real Mica brush (the player's "Mica" is a tinted solid), so Solid color + opacity covers it
- [x] Remove the settings button and the lower part (#84) — "Hide icon tray"
- [x] Change the corner radius (#84) — Mini Player Menu: "Menu corner radius"
- [ ] Background styles like Notification Center Styler, or work with it (#84)

## Filtering

- [x] Whitelist mode: only show chosen apps (allowedProcesses + filter mode) (#64) — "Only show these apps" (empty = all)
- [x] Move the process filter out of Debug settings into Behaviour (#64) — settings window: Behaviour & Clicks > Which apps (keys unchanged)

## Other

- [ ] System messages / notifications shown like a macOS "island" (#47)
- [x] Album art diagnostics logging and decode fixes (patch in #63) — partial reads loop, skip reasons logged, WIC fallback for art XAML can't decode
- [x] Thread-safe settings reload (PR #72) — done differently: settings reload on the taskbar thread
- [ ] Multi-monitor: list of monitors, move off a fullscreen monitor, hide only on that monitor (PR #76)
- [x] Progress bar with click/drag seeking, seek bar in the mini player (PR #86) — in 1.7

## Security report (#71)

- [x] shell32 search path and the hardcoded ordinal 2573 — now calls SHQueryUserNotificationState by name
- [x] bare windhawk.exe fallback — only the known install folders, logged if not found
- [x] image stride overflow — guarded in both decoders
- [x] releasing XAML on the wrong thread at unload — references dropped without releasing when the taskbar thread is gone

## Found while checking: 1.6.0 features missing from 1.7

The published 1.6.0 on Windhawk has these and the 1.7 code doesn't. Worth adding back before 1.7 ships, or people lose them on update:

- [x] "Switch tracks (inverted)" mouse wheel action. Anyone who has it set gets no wheel action at all on 1.7. — restored
- [x] Visualizer contrast correction (`VizEnsureContrast`): album colors too close to the taskbar get brightened/darkened so the bars stay visible. — restored
- [x] The stale browser art check from 1.6.0 (#33; `IsBrowserAumid` / suspect art size). You said the browser case works now, so this may not be needed. — not needed, works
- [x] Right and middle double-click actions — they never fired in 1.7 (middle double-click wasn't even read); 1.6.0's detection restored
- [x] Stopping the visualizer's audio capture blocked the taskbar thread — the wait runs on a worker again (each capture run now has its own state)
