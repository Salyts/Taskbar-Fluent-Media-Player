# Future-proofing Taskbar Fluent Media Player

Notes for Salyts and GR0UD on where the mod should go next. Started 2026-10-03,
updated for 1.7.
Nothing in here is urgent. The "Improve now" list at the bottom is the stuff
worth doing before the next release.

## What Windhawk 2.0 changes for us

Windhawk 2.0 is in alpha (alpha 6 as of Sept 21). Things in it that matter to this mod:

**New settings annotations (alpha 6)**
- `$showIf` / `$hideIf`: show a setting only when another one has a value. Our
  detached-container settings (position, monitor, the 11 background keys each)
  could stay hidden until "Detached" is on. That alone would make the Windhawk
  settings tab much shorter.
- `$min` / `$max`: the editor itself refuses out-of-range numbers. Our ranges
  already live in the `SETTINGS` table (`SInt(key, lo, hi, ...)`), so the YAML
  values should match those.
- `$format`: `colorRgb`, `colorArgb`, `fontFamily`, `hotkey`, `filePath`,
  `folderPath`. Careful with colors: we store `"R G B"` strings and the
  `"dark$light"` pair format (`0 0 0$255 255 255`), and a Windhawk color picker
  almost certainly writes a different format. Check what `colorRgb` stores before
  switching anything over, or existing settings would break.
- `$float`: real decimal settings.
- `$dynamicSelect`: options filled in at runtime. Possible uses: pick a monitor by
  name instead of number, or pick an app for "ignored processes".
- `hotkey`: global hotkeys for play/pause, next and previous would be a nice feature.

**Settings editor (alpha 2 and 3)**
- Default tracking and "revert to default", folding, compact mode, textual
  mode keeps comments. Backup and restore of mods and settings.
- CLI: `windhawk-cli mod settings set key=value ...` sets several settings at once.

**Development tools are optional now (alpha 1)**
- Normal users get precompiled mods and never compile. Compile time only
  matters to us.
- The VSCodium editor is replaced by a new lightweight UI. **Our
  `dev/windhawk_pch.h` trick depends on the old editor workspace folder**
  (`C:\ProgramData\Windhawk\EditorWorkspace`), so it may stop working on 2.0.
  Recheck it once we move to 2.0.

**Tool mods run in `windhawk-mod.exe` (alpha 4)**
- Not relevant to us directly (we live in explorer.exe), but good to know if we
  ever split something out into a helper process.

**Mod storage**
- Alpha 5 fixed the integrity label on mod storage files, so `Wh_SetStringValue` /
  `Wh_GetStringValue` storage is getting attention. That's the API our settings
  store uses.

## 1.7.1

**Idle mode: keep the player's spot when nothing plays.** Asked for on Discord:
the taskbar icons jump around when the player hides and comes back, and "always
show" leaves an empty player sitting there. A setting for what the player shows
with no media, keeping its size so nothing moves:
- the date and time, or a line of custom text
- the last song, dimmed, with a click to resume it
- nothing, just the reserved width

Everything local. A weather version came up too, but mods can't contact servers,
so that's out.

**From the Windhawk review's functionality notes** (promised on the PR):
- Widgets hiding: `RepeatButton_Width_Hook` queues the outer RepeatButton but
  `WidgetsButtonScopeState` compares the inner panel, so nothing gets hidden. Also
  only install those hooks when `hideNativeWidgetsButton` is on.
- `AttachToSession` checks, detaches and attaches under separate locks, so two
  session events at once can register the handlers twice. Do it all on the media thread.
- The icon-refresh check runs after `appIconBytes` was moved out, so its flag never clears.
- Mini player: session rows updated in place keep their old `capturedId` (wrong
  session on click); closing mid-drag leaves `g_miniPlayerSeekDragging` set; placement
  uses `g_taskbarWnd`'s monitor even when opened from a part on another monitor.
- With `monitor: -1`, detached parts never update (`RefreshPlayerContents` and
  `UpdateVisibility` exit early without `g_playerGrid`).
- `g_sidebarMode` is one global that each detached part's taskbar overwrites.
- "Hide when no media": the 2.5 s branch never runs.
- Carry 1.6.0's `vizPosition` (left/right) over to `vizOrder`.
- `ChangeSystemVolume` changes the volume twice per wheel step (also in 1.6.0).
- Album art is decoded at full size twice on the UI thread per track change; decode
  it scaled.

## Next

**The player on several monitors at once (#15, #90).** The main feature for the
version after 1.7.
1. Turn the player into something that can exist more than once: its elements,
   timers and mini player per monitor, each on its own taskbar's thread. Release
   that with no visible change and let it prove itself.
2. Let the monitor buttons select several monitors at once.
3. Share the audio capture and media info between the copies.

**Offer a report after a crash.** On start, check the Windows crash log for a new
Explorer crash and offer to open the bug report form with it filled in. Ask first,
at most once a day. Don't report automatically: most crash stacks don't show our
code, so the mod can't tell which crashes are ours.

**A real custom title bar.** "Match the window" lets Windows draw the title bar, but it uses its own Acrylic, without our tint or sliders, so it looks brighter than the window. Matching exactly means drawing the title bar ourselves: our own minimize, maximize and close buttons, dragging and resizing. The Windows 11 snap layouts flyout on maximize would need work too.

**Remove Windhawk's settings list.** The settings already live in the mod's storage.
The number defaults have to move into the code first (see "Improve now").

## Ideas from other mods (from the Oct 2026 update feed)

- **Desktop Audio Visualizer Plus** (NeiZ): album colors through OKLab k-means
  (better, more varied colors than plain averaging), a sliding-sum blur (fast box
  blur, same cost for any radius), lyrics from local `.lrc` files, and dropping to
  low frame rates while a fullscreen app runs. Our `ExtractAlbumPalette` and the
  album-art blur could both use the first two. Lyrics in the mini player would be
  a cool feature.
- **Start button always on the left** now supports vertical taskbars. Our anchor
  positions ("Left/Right of Start") and `IsStartButtonModActive` should be tested
  with it, especially in sidebar mode.
- **Independent taskbar per monitor**: test multi-monitor placement with it on.
- **Taskbar on top** and **Taskbar Top Window Guard**: test a top taskbar (the
  mini player's "near" placement and the progress bar above/below).
- **Instant Taskbar Thumbnail Previews** fixed "hook installation when the taskbar
  loads after the mod". That's the same family as our scroll-timer bug from
  disabling and re-enabling the mod. Worth re-testing late-load paths in general.

## Improve now

1. **Cache element lookups.** `FindMediaChild` walks the whole player tree (and
   every detached grid) element by element, and each step is a WinRT call. It
   runs about 46 times per refresh, and the scroll animation calls it on every
   16 ms tick, so a scrolling title means about 60 full tree walks a second.
   Cache name -> element after each build and clear the cache whenever a grid is
   rebuilt or removed.
2. **Stop copying the album art every refresh.** `TakePlayerSnapshot` copies the
   thumbnail bytes and `RefreshAlbumArt` compares them byte by byte against the
   cached copy. `thumbnailHash` already exists, so compare hashes and copy the
   bytes only when the art actually changed.
3. **Skip unchanged parts of a refresh.** Now that the refresh is split into parts,
   each part can remember what it last drew (text, button states, art hash) and
   skip itself when nothing changed. It has to stay correct for theme and setting
   changes, so those should force a full refresh.
4. **Put the number defaults in the `SETTINGS` table.** Right now the default for
   a number setting lives only in its settings window row and the YAML.
5. **Use the new YAML annotations** (`$showIf`, `$min`/`$max`) once we target
   Windhawk 2.0. Needs a decision on whether we still support 1.7.

## Compatibility checklist before a release

- Fresh Explorer start, and disable/re-enable the mod (late-load paths).
- Recompile while music plays and right after pressing Stop (unload paths).
- Horizontal and vertical taskbar, top taskbar.
- Two monitors, including the info container on monitor 2.
- With Start button always on the left, Taskbar Split, Independent taskbar per
  monitor.
- Light and dark theme, with a theme switch while the mod runs.
- Every window material, including Acrylic with Wallpaper Engine running, and scrolling on each.
- Line and bars behind the player: check the Windows crash log afterwards.
