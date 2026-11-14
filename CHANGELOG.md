# Changelog

## 1.7.1 (in progress)

### New

- **Drag to place.** Settings, Layout page: a sketch of the taskbar on each monitor with the player and its parts on it. Drag one to a spot and it moves there right away, on any monitor. Drop a part on "In the player" to put it back inside the player, or on "Hidden" to hide it.
- **Weather when nothing plays.** Turn on "Show Widgets when nothing plays" under Native Widgets: the player hides when nothing is playing and the Windows Widgets button (with the weather) comes back in its place. Detached parts stay where they are. While music plays, the player is back and Widgets is hidden.
- **Weather part.** Turn on "Show weather" (Settings, Weather page): the icon, temperature and condition from the Windows Widgets button as a part of its own, placed anywhere like the other parts, on any monitor, with its own background. Click it to open Widgets. It reads what the Widgets button shows, so Widgets has to be on in Windows; "Hide native Widgets button" can keep the original out of sight. It stays up when nothing plays.
- **Scroll to skip.** New mouse wheel action "Skip 5 seconds back or forward" for the player and the album art, and the wheel over the mini player's seek bar does the same (#121, #123).
- **Album art shows.** New option under Album Art: the cover, the icon of the app that plays, or always the stand-in icon (#113, #120).
- **Mini player.** Mica and Mica Alt looks for the menu background (#112), and an option to fold the cover area away when a song has no cover (#122).
- **Weather keeps working with Windows' button hidden.** "Hide the weather widget" now hides the button without stopping its weather updates while the weather part is on, so the part has something to show. With Widgets turned off in Windows, the Weather page says so and has a Turn on button.
- **Weather only when nothing plays.** New option for the weather part: it hides while music plays and comes back when it stops, taking turns with the player.
- **Weather has its own page** in the settings window (right under Visualizer), and the visualizer's power options sit in a Performance card.
- **Windows Buttons page.** The old Native Widgets page, reorganized: one list of Windows buttons to hide (Start, Search, Task View and the weather widget), then the weather widget's own options. The Start, Search and Task View switches are new. They come back when the switch or the mod is turned off.
- **The left corner is a real spot.** With Widgets turned off in Windows (or a button hidden), parts set next to that button now go to the start of the taskbar side by side, each taking its own room. Before, they landed on top of each other. The Layout page shows the corner as a place to drop parts.

### Lighter on CPU, GPU and battery

- **Visualizer frame rate.** New option: 60, 30 or 15 fps. Lower rates redraw the bars less often.
- **Visualizer on battery.** New option: keep running, pause while Windows' battery saver is on (the default), or pause whenever on battery. Paused, the bars rest and the mod stops listening to the audio.
- With the screen off, the visualizer, the scrolling text and the progress updates stop, and start again when it comes back.
- "Hide in fullscreen" now reacts within half a second of a game going fullscreen or leaving it. Before, it waited for the next change in the music, so the visualizer kept running under the game.
- Scrolling text no longer ticks 60 times a second while it holds still at an end, or while the player is hidden.
- The visualizer's audio thread sleeps while there is no sound instead of waking 50 times a second.
- While paused, the progress bar asks for the position every 3 seconds instead of every second.

### Fixes

- The progress bar no longer disappears when it is set under a part that is hidden; it spans the player instead (#117).
- New option "A double-click doesn't run the single click too" (Behavior). A left double-click also no longer runs the single click twice (#115).
- A seek the app refuses no longer moves the progress bar as if it had worked (#116).
- "Open media app" brings the app up when it sits in the tray (Spotify, AIMP) (#114).
- "Hide native Widgets button" works again, and the mod only hooks the Widgets button while that setting is on.
- "Hide when no media" hides the player 2.5 seconds after the media goes away. Before, it never hid while an app kept its session open.
- With the player off on every monitor, detached parts still update.
- Mini player: clicking a session in the list switches to the right one after the list changes. It opens on the monitor you clicked on, and the seek bar doesn't stay stuck after closing mid-drag.
- Scrolling the volume moves it once per notch instead of twice.
- Album colors and the blurred background decode a smaller copy of the cover, so track changes take less work.
- A vertical taskbar on another monitor no longer changes how the main player is laid out.
- Two quick session changes can't attach the player to the same session twice.
- The app icon refresh after switching sessions finishes properly.

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
- Uses fewer threads and wakes up less often in the background: the progress bar, app volume scrolling and the monitor and tray checks.

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
