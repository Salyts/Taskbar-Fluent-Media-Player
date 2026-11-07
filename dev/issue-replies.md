# Replies for open GitHub issues

Paste-ready. "1.7" means the release we're about to put out.

## New since 2026-10-16 (not posted yet)

**#93** (visualizer reacts to every sound)
> Thanks for the report. 1.7 adds "Only listen to the app in the player", on by default: the bars only move with the app the player is showing, so a Discord call or a game won't move them anymore. It needs Windows 11; on older versions it still listens to everything.

**#98** (vertical taskbar)
> 1.7 supports left and right taskbars: the player stacks along the taskbar and the text and album art can turn with it (Layout settings). It isn't on Windhawk yet, but the 1.7 alpha is in the Windhawk Discord.

**#97** (TheGamer's explainer): nothing to reply, maybe pin it.

## New since 2026-10-03 (not posted yet)

**#91** (Tray - Left of Tray Icons stopped working after a Windows update)
> Thanks for the report. That update changed how the system tray is built, and 1.6 can't find its spot in the new layout. 1.7 handles it, including "Left of Tray Icons". If the button the player is meant to sit next to doesn't exist on your build, 1.7 puts the player at the start of the tray instead of not showing it. We'll post here when 1.7 is on Windhawk.

**#89** (it no work)
> The September Windows update (the one that lets you move the taskbar) broke 1.6. 1.7 fixes it. Until it's on Windhawk there's a test build in our Discord.

**#88** (floating Taskbar Styler themes, margin makes the taskbar wider)
> You're not missing anything: the margin adds space next to the player, so the taskbar grows. 1.7 adds "Media player offset (x y)", which moves the player without taking any room, so you can line it up with floating themes. "Taskbar - Left edge (Overlay)" plus an offset should get you the bottom-left spot whatever theme you use.

**#90** (show the player on every monitor at once)
> Thanks, and glad you like it! Showing the player on more than one taskbar at the same time is on our list. It won't make 1.7, but we'll keep this open for it.

**PR #87** (StackPanel system tray, from Net-zen)
> Thanks for this! 1.7 already handles the StackPanel tray. We also took two things from your patch: the column now comes from the tray's direct child instead of the nested button, and "right of" uses ColumnSpan. Closing since 1.7 covers it. You're in the changelog.

## Fixed in 1.7

**#69, #78, #79, #83** (stopped working after a Windows update)
> A Windows update changed how the system tray is built, which broke the mod. 1.7 handles the new layout. Once it's out on Windhawk, update and it should show up again. If it still doesn't, please turn on debug logging (Advanced > Debug logging > Mod logs) and paste the log here.

**#80** (only shows on the secondary monitor)
> 1.7 lets you pick the monitor for the player, and for each part of it separately. If it still picks the wrong screen after updating, let us know what you set "Monitor" to.

**#36, #62** (progress bar / seeking)
> 1.7 adds a progress bar to the player and a seek bar to the player menu. You can click or drag both to seek.

**#32** (flip text and buttons, art on the left)
> 1.7 lets you set the order of album art, text, buttons and visualizer yourself.

**#70, #77** (ignored apps still show up when switching sessions)
> Fixed in 1.7: switching sessions skips ignored apps now, and the switch button only counts sessions you can actually switch to. The visualizer listens to all system audio, so it can't leave one app out yet. That would need per-app audio capture, which is on the list.

**#81** (big album art from AIMP doesn't show)
> The mod skipped any album art file bigger than 4 MB (2 MB in the player menu). 1.7 raises that to 24 MB, so high-res covers should show up now.

**#58** (visualizer keeps the old album colors)
> Fixed in 1.7: when there's no album art, the dynamic color modes go back to your normal visualizer color.

**#73, #68, #67, #82** (player missing after boot or Explorer restart until the mod is toggled)
> 1.7 adds a retry: if the player didn't make it onto the taskbar at startup, the mod tries again a few seconds later instead of giving up. Please give it a try once it's out and let us know if you still need to toggle it.

**#71** (security report)
> Thanks for the detailed report. 1.7 only runs callbacks the mod sent itself, and each one only once. For the settings race, the ignore list was the one string read from another thread during a reload, and 1.7 reads it from its own locked copy now. We went with that instead of the full mutex from #72.

## Not something the mod can fix (the app doesn't tell Windows what's playing)

**#46** (VLC)
> VLC doesn't report what it's playing to Windows by itself. Install https://github.com/spmn/vlc-win10smtc and it works (it says Win10 but works on Win11 too).

**#29** (MusicBee)
> MusicBee needs the mb_MediaControl plugin to report what it's playing to Windows. With it installed the player picks it up.

**#56** (AIMP)
> Install AIMP's "Windows 10 Media Control" plugin from the AIMP site and the player will pick it up.

**#65** (MediaMonkey), **#10** (Windows Media Player Legacy)
> The player can only show apps that report their media to Windows (the same thing that makes the volume flyout show the song). These apps don't, so there's nothing for us to read. If the app gets a plugin or setting for "system media controls", it'll work.

**#54** (local files / Qobuz)
> Local files work as long as the app playing them reports to Windows. Media Player, Spotify and most browsers do. Qobuz doesn't, unfortunately.

**#40** (browser picture-in-picture)
> In picture-in-picture the browser stops reporting the media to Windows, so there's nothing for us to show. The visualizer still works because it listens to the audio itself.

**#35** (Netflix shows the placeholder)
> Netflix doesn't send any artwork to Windows, so there's nothing to show. You can turn on the app icon option to show the Netflix icon instead.
