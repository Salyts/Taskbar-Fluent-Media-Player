# Changelog

## 1.7

### The big ones

- **Its own settings window.** Right-click the player and pick Settings. It's built in the Windows 11 style with Mica, sorted into pages, and changes show on the player while you make them. It comes in 15 languages and follows your Windows language by default.
- **Settings live in the mod now.** The first time 1.7 runs, it copies everything from Windhawk's settings page, so you don't lose anything. Save keeps your changes, and closing only warns you if something really differs from what's saved.
- **Move any part of the player.** Album art, track info, buttons and the visualizer can each be detached and placed somewhere else on the taskbar or tray, with their own background and monitor.
- **Progress bar.** It can sit under any part of the player or the whole thing, on its own line or drawn on top. Click or drag it to seek.
- **Vertical taskbars.** If yours is docked left or right, the text and album art turn to read along it and the buttons stack up.
- **Monitor buttons.** Pick a monitor by clicking its button, numbered like Windows. Click the selected one again to hide the player. Monitors that aren't connected stay gray and become available when you plug them in.

### Visualizer

- "Only listen to the app in the player", on by default, so a Discord call or a game won't move the bars (Windows 11). (#93, #85)
- New: it can fill the background behind the whole player.
- New: Line style, and a Micro version that fits next to the artist text. (#16)
- Pick which audio device it listens to, including recording devices. (#17, #50)
- Hide it when nothing is playing. (#14)
- Tune each of the 7 frequency bands.

### Player and layout

- Set the order of album art, text, buttons and visualizer. (#32)
- "Media player offset" moves the player without making the taskbar wider, which helps with floating Taskbar Styler themes. (#88)
- Reorder the media buttons and right-click menu items.
- Hide the whole player while paused, after a delay you choose. (#14)
- Hide the Windows Widgets button.

### Text

- Show the album name instead of the artist, or only when there's no cover. (#38)
- Custom text formats with `%title%`, `%artist%`, `%album%` and `%artist_or_album%`. (#38)
- Show the playback time (like 2:02/4:24) instead of the artist.
- Hide the text when nothing is playing.

### Clicks and apps

- Choose an app to open when you click the player with nothing playing. (#23)
- New click actions: minimize, open or minimize, and close the media app. (#53)
- "Only show these apps" mode, and the app filter moved out of Debug into Behaviour. (#64)

### Mini player

- Seek bar, with its own color. (#62)
- Background options: Acrylic, solid color, album colors gradient or blurred cover. (#48)
- Corner radius setting, and the bottom icon row can be turned off. (#84)

### Settings window extras

- Choose the window's background: Mica, Mica Alt, Acrylic or Acrylic Thin. Acrylic shows what's behind the window, so it works with live wallpapers that Mica can't see, and has its own transparency and blur sliders.
- The title bar can match the window, stay as Windows draws it, or take any color.
- The page fades at its top and bottom edges while you scroll.
- Any color can follow the album, including the window's own accent, which fades to the new color when the song changes.
- Report a bug from inside the window: it copies a report with your mod and Windows versions, plus recent errors and your settings if you tick them, and opens the mod's Discord so you can paste it in bug-reports. The mod sends nothing itself.
- Reset to Windhawk's settings, in Other.
- An Animations switch, which also follows Windows' own setting.

### Fixes

**Windows updates**
- Works again after the updates that changed the system tray and the September taskbar update. (#69, #78, #79, #83, #89, #91)
- If the button the player sits next to doesn't exist on your build, the player goes to the start of the tray instead of disappearing.
- The player no longer vanishes when Do Not Disturb is on.

**Startup and stability**
- If the player doesn't make it onto the taskbar at startup, the mod tries again. (#67, #68, #73, #82)
- Media keys keep working after an Explorer restart. (#52)
- The player corrects itself if it ends up on the wrong side of its tray button.
- Security report: fixes for callback handling, the shell32 and windhawk.exe lookups, image handling and unloading. (#71)
- Turning the mod off or updating it waits for everything it started, so Explorer no longer crashes or hangs then, or when signing out.
- Moving the player to another spot no longer leaves a gap or an extra tray column behind.
- Scrolling text stops using CPU when the title and artist fit.

**Which app it follows**
- The player stays on the app that's playing instead of a paused one. (#22)
- It no longer flashes another app when tracks change. (#34)
- Ignored apps stay out of session switching, and the ignore list also matches the browser's exe. (#66, #70, #77)

**Album art and colors**
- Covers up to 24 MB show up. (#81)
- Old art no longer stays when a browser track has none. (#33)
- The Album color works on the progress bar, the visualizer and everything else, including with album art turned off.
- With no album art, dynamic visualizer colors go back to your normal color. (#58)
- Solid backgrounds survive switching between light and dark. (#57)

**Visualizer**
- Keeps reacting when you switch the player to another app, like Clipchamp, Firefox or Snipping Tool.
- Much lower GPU use when nothing is playing. (#41)

**Monitors**
- Text scrolling and the visualizer keep working after the player moves to another monitor.

**Input and placement**
- Pause works reliably in Zen browser. (#26)
- Right and middle double-click actions fire again.
- "Hide when no media" no longer keeps taking up space. (#14)
- Fixed the gap with "Right of Widgets", and the player going under the icons with Taskbar Styler "Borderless". (#74)
- Minimize and close only ever act on the media app's own window, never one from a similarly named app.
- "Open Windhawk" finds Windhawk wherever it is, portable installs included.

### Not in this version

- Showing the player on several monitors at the same time is still planned. (#15, #90)

### Thanks

- Net-zen for the StackPanel tray patch (#87).
- Everyone who reported bugs and tested the alphas on the Windhawk Discord.
