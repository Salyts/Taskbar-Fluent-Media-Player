Thanks, both points from m417z and the two remaining review items are fixed in the latest push.

**@m417z**
- **windhawk.exe:** the guessed paths are gone. It's now found from the path of the `windhawk.dll` loaded in Explorer (`<Windhawk>\Engine\<version>\<arch>\windhawk.dll`, walking up to the folder that has `windhawk.exe`), so portable Windhawk works too. `%ProgramFiles%\Windhawk\windhawk.exe` is the fallback.
- **Taskbar.View.dll:** if it isn't loaded at `Wh_ModInit`, the mod hooks `LoadLibraryExW` in kernelbase.dll and hooks the module's symbols once it loads (then `Wh_ApplyHookOperations`). `Wh_ModAfterInit` also checks once, for a load between the check and the hook going live.

**Review items**
1. **`Show()` after unload:** `g_unloading` is checked inside `s_launchMtx` now.
2. **Windhawk's page showing older values:** the README's "Good to know" section and the `settingsView` description now say that values saved in the settings window aren't shown on the Settings tab, and that a setting changed and saved there still applies. Keeping both stores is the maintainer's call. Happy to change it if you'd rather the Settings tab be the only source.

**Optional items done**
- The class brush is no longer deleted after `UnregisterClassW`. It's only deleted if registration failed.
- `AwaitOrCancel` uses `wait_for(50 ms)` instead of polling.
- Every `ShellExecuteW` is now `ShellExecuteExW` with `SEE_MASK_FLAG_NO_UI | SEE_MASK_NOASYNC`.
- `g_timerUpdateEvent` stays open across timer restarts and is closed in `Wh_ModUninit` after the last `WaitForTrackedWorkers`.
- `InitAudioDeviceEnumerator` creates the enumerator under a mutex.
- `ShowSuccessNotification` shows its box on a tracked worker. Unload closes it if it's open.

The rest of the optional list and the functionality notes are planned for 1.7.1.

**The old webhook** was deleted in Discord before the last push, so the token in the history no longer works.

**The settings-window comment** ("can restart Explorer on open") was left over from early development, when the window was first being built. Testers have used it through the 1.7 alphas without that happening.
