Thanks for the review. All twelve items are addressed in the latest push:

**1. Bug report upload:** removed, and the webhook is deleted. "Report a bug" now builds the report locally (description, mod version, Windows build, and recent errors and settings if ticked), copies it to the clipboard and opens our Discord server's invite link in the browser, where people post it in the bug-reports forum. No PC or user name, no event log. `-lwinhttp`, `-lwevtapi`, `<winhttp.h>`, `<winevt.h>` and the thread that held a module reference are gone.

**2. Log file in %TEMP%:** gone. Those calls are `Wh_Log` now.

**3. Threads after Wh_ModUninit:** workers are `CreateThread` handles, and uninit waits on every one with no timeout. `SpawnTrackedWorker` refuses work once `g_unloading` is set. The media and timer threads are waited on with no timeout too (on the taskbar thread it keeps handling sent messages while it waits). If the visualizer's join worker is refused, it joins inline. Blocking WinRT calls in workers go through `AwaitOrCancel`, which calls `Cancel()` on unload. The GSMTC callbacks are counted while they run, and uninit waits for them.

**4. Handlers left on Explorer's XAML:**
- Removal finds a tracking group by the member's grid, not by the current position.
- The tray column cleanup uses the position the part was injected with, stored at injection after any fallback.
- Each group records its taskbar. Uninit revokes `LayoutUpdated` and restores the margin for any group left, on that taskbar's thread.
- These are now kept in globals and stopped or hidden in the UI-thread part of uninit:
  - the settings tip's timers and flyout
  - the startup retry timer
  - the mini player flyout's handlers (revoked) and its fallback timers
  - the art fade storyboards
- `RunAsync` work goes through a helper whose captured token is only released when the dispatcher drops the delegate, and uninit waits for those.
- `RetireTaskbarTimer` stops a timer on its own thread even when its window is gone, through another window of that thread. If the thread itself is gone, it leaks the timer instead of releasing it from the wrong thread.

**5. WM_GETICON:** back to `SendMessageTimeoutW` with `SMTO_ABORTIFHUNG | SMTO_BLOCK`, 100 ms.

**6. Global destructors:**
- Bare `[[clang::no_destroy]]` on every nullable global you listed and on the `xs::` statics.
- `[[clang::no_destroy]] std::optional` for `g_vizBars`, `g_vizBrushes`, `g_vizLineStops`, `g_hiddenWidgetsButtons` and `g_trackingGroups`.
- `g_captureRun` is a `shared_ptr`, so it takes the bare attribute, and `StopVizCaptureThread` always joins its thread.
- The settings window thread is a plain `HANDLE` now.
- The visualizer's elements are released in the UI-thread lambda, with `ClearVizLine()`.

**7. Settings window:**
- The thread is tracked through its handle under `s_launchMtx`.
- `Show()` returns early while unloading or while the thread is still starting, and never joins on the taskbar thread.
- Closing the window destroys it, so the thread ends and releases its own XAML.
- `CloseWindow()` answers any open message box No/Cancel, then posts `WM_CLOSE` to the window, or `WM_QUIT` to the thread when there is no window yet, and waits.
- `ThreadProc` also checks `g_unloading` while it starts, and the error boxes aren't shown during unload.
- The comment about restarting Explorer was left over from early development, and it's removed.

**8. AttachThreadInput:** replaced with the empty `SendInput` before `SetForegroundWindow`.

**9. Portable Windhawk:** the store is printable text now: `TFMP2;` followed by `key=value;` entries, with `\ ; = space "` and control characters escaped. It's tested round trip across chunk boundaries. A store that was already flattened is detected and copied in again from Windhawk's page, instead of being read as garbage.

**10. Two sources of truth:** the mod's store stays the source for now, with these fixed:
- Edits made on Windhawk's page while the mod was off are taken in at `Wh_ModInit`.
- A failed first copy is retried on the next page save, and the page is what's in effect meanwhile.
- A page save while the window is open only replaces the keys that changed, keeps the rest of the draft, and refreshes the window.

Still as before: re-saving an unchanged value on the page, and pasted exports with values equal to the snapshot. Telling those apart from untouched values needs a decision on which side wins. Happy to go whichever way the maintainer prefers.

**11. Title scroll timer:** the tick stops the timer when nothing needs scrolling, and `UpdateMarqueeLine` starts it again when a title or artist stops fitting.

**12. Architecture:** `@architecture x86-64` added.

From the optional list, these are done too:
- Unload waits for the workers before the media thread releases the session manager, and the media thread lets running session callbacks finish before it releases the manager and the session.
- `g_captureRun` is only stopped on the taskbar's thread, including from `StopTimerThread`.
- `RunFromWindowThread` returns whether the work ran. `CheckMonitorTopologyChanged` sets `g_applyingSettings` inside the callback, so the flag can't get stuck.
- `GetTaskbarXamlRoot` has its null checks back (`taskbarHostSharedPtr[0]`, the element pointer, and the `FrameHeight` pointer).
- Minimize and close need an exact app ID or exe match, and an empty app ID no longer matches anything. The loose matches are only used to bring a window up.
- The code fallbacks for position, placementMode, miniPlayerIconStyle and the colors match the YAML defaults.
- In the settings window, the icons and brushes are destroyed, `s_pageScroll` is reset in `WM_DESTROY`, `native2` is released before `uninit_apartment()`, and the `ERROR_CLASS_ALREADY_EXISTS` branch is gone.
- The Windows path comes from `GetWindowsDirectoryW`.
- Removed: `-lversion`, `g_playerButtonStateUpdater`, `needsReattach`, `RowKind::Position`, `SettingRow::ctrl` / `ctrl2` / `posRight` and `g_miniPlayerLastSeekTime`.
- The audio device setting mentions the microphone indicator.

The rest of the optional list (the remaining locking, thread counts, polling, reference cycles, and the functionality notes) is planned for 1.7.1.

Generated by AI. Model: Claude Opus 5.5
