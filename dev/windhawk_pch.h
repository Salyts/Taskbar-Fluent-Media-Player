// Precompiled header for developing the Taskbar Fluent Media Player mod in
// Windhawk's editor. Windhawk looks for this file (windhawk_pch.h) in its
// editor workspace folder, precompiles it once, and reuses the result on
// every "Compile Mod" until this file changes - so the ~60 Windows / WinRT /
// STL headers below are parsed once instead of on every compile.
//
// It only affects compiles from the editor on this PC. The mod source is
// unchanged and the published mod is built without it.
//
// The headers are listed in exactly the order the mod includes them, after
// windhawk_api.h (which Windhawk force-includes first in a normal build), so
// the mod sees the same macros and declarations either way. If the mod's
// #include list changes, update this file to match.
//
// Caveat: the precompiled result has the mod's ID and @version baked in, and
// Windhawk only rebuilds it when THIS file is newer than it. So after bumping
// the mod's @version, or switching the editor to a different mod, the compile
// fails with "definition of macro 'WH_MOD_VERSION' (or WH_MOD_ID) differs
// between the AST file ... and the command line". Fix: re-save this file (any
// edit, even adding and removing a space) and compile again - or delete the
// windhawk_t_*.pch files next to it.
//
// Installed at C:\ProgramData\Windhawk\EditorWorkspace\windhawk_pch.h (the
// folder holding the editor's mod.wh.cpp). A reference copy lives in the repo
// as dev/windhawk_pch.h.

#include <windhawk_api.h>

#undef GetCurrentTime

#include <unknwn.h>
#include <winrt/base.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.UI.Xaml.Hosting.h>
#include <winrt/Windows.UI.Core.h>
#include <winrt/Windows.UI.Text.h>
#include <winrt/Windows.UI.Input.h>
#include <winrt/Windows.UI.Xaml.h>
#include <winrt/Windows.UI.Xaml.Controls.Primitives.h>
#include <winrt/Windows.UI.Xaml.Controls.h>
#include <winrt/Windows.UI.Xaml.Media.h>
#include <winrt/Windows.UI.Xaml.Media.Imaging.h>
#include <winrt/Windows.UI.Xaml.Shapes.h>
#include <winrt/Windows.UI.Xaml.Media.Animation.h>
#include <winrt/Windows.UI.Xaml.Markup.h>
#include <winrt/Windows.UI.Xaml.Interop.h>
#include <winrt/Windows.UI.Xaml.Input.h>
#include <winrt/Windows.UI.Xaml.Automation.h>
#include <winrt/Windows.UI.ViewManagement.h>
#include <winrt/Windows.Media.Control.h>
#include <winrt/Windows.Storage.Streams.h>
#include <winrt/Windows.Graphics.Imaging.h>
#include <robuffer.h>
#include <shcore.h>

#include <windows.h>
#include <shellapi.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <shobjidl.h>
#include <commoncontrols.h>
#include <wincodec.h>
#include <propsys.h>
#include <dwmapi.h>
#include <sddl.h>
#include <windows.ui.xaml.hosting.desktopwindowxamlsource.h>
#include <windhawk_utils.h>
#include <audiopolicy.h>
#include <mmdeviceapi.h>
#include <endpointvolume.h>
#include <audioclient.h>

#include <propkey.h>

#include <objidl.h>
#include <gdiplus.h>

#include <atomic>
#include <functional>
#include <memory>
#include <utility>
#include <mutex>
#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <thread>
#include <cmath>
#include <chrono>
