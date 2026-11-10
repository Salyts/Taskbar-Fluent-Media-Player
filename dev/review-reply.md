Pushed the rest of the optional list as well:

- **Session lock:** `SwitchMediaSession` copies the manager and the current session under `g_sessionMtx`, then calls `GetSessions()` and `IsIgnoredMediaApp` outside it.
- **Reference cycles:** these now use `sender` or `winrt::make_weak`:
  - the art fade (`Completed`, `ImageOpened`, `ImageFailed`)
  - the player's `PointerExited`
  - `MakeControlButton` and `RunWhenButtonReady`
  - the mini player's reveal (`doReveal`, `SizeChanged`, `fallbackTimer`, which is now also unregistered) and closing fallback timer
  - the startup retry timer
  - the session pill, the sidebar album art and the scrolling text clip
  - in the settings window: `ColorPickerState` (weak element refs), the color segments, the expand button and the paired number boxes
- **Threads:**
  - The timeline is refreshed inline on the timer thread, which now has its own MTA apartment, instead of a new thread every second.
  - App volume wheel steps add up in a counter, and one worker at a time applies them.
- **Polling:**
  - `CheckMonitorTopologyChanged` only runs its full window and monitor walk when a cheap fingerprint changes (monitor count, virtual screen, primary size, taskbar rect), with a full pass every 10 s.
  - `KeepTrayPlacement` checks every 3 s for the first half minute after the player goes in or something moved, then every 15 s.
  - `RecoverMissingPlayer` no longer retries when the main player is off on purpose (monitor off, or a vertical taskbar with the sidebar off) and no detached part is wanted.

The functionality notes are planned for 1.7.1.
