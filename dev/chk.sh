#!/bin/sh
# chk.sh <src> syntax|full [outdir]  -- Windhawk's exact editor compile flags
SRC="$1"; MODE="$2"; OUT="${3:-${TEMP:-/tmp}/fmp-chk}"
LIB="C:/Program Files/Windhawk/Engine/1.7.3/64/windhawk.lib"
ID='-DWH_MOD_ID=L"local@taskbar-fluent-media-player"'
VER='-DWH_MOD_VERSION=L"1.7.0"'
OPTS=$(sed -n 's|^// @compilerOptions *||p' "$SRC" | head -1 | tr -d '\r')  # the mod's own link flags
DEFS="-DUNICODE -D_UNICODE -DWINVER=0x0A00 -D_WIN32_WINNT=0x0A00 -D_WIN32_IE=0x0A00 -DNTDDI_VERSION=0x0A000008 -D__USE_MINGW_ANSI_STDIO=0 -DWH_MOD"
cd "C:/Program Files/Windhawk/Compiler" || exit 1
s=$(date +%s.%N)
if [ "$MODE" = syntax ]; then
  ./bin/clang++.exe -std=c++23 -O2 -fsyntax-only -ferror-limit=0 $DEFS "$ID" "$VER" -x c++ - -include windhawk_api.h -target x86_64-w64-mingw32 < "$SRC" 2>&1
else
  mkdir -p "$OUT"; rm -f "$OUT/mod.dll"
  ./bin/clang++.exe -std=c++23 -O2 -shared $DEFS "$ID" "$VER" "$LIB" -x c++ - -include windhawk_api.h -target x86_64-w64-mingw32 -Wl,--export-all-symbols -o "$OUT/mod.dll" -x none $OPTS < "$SRC" 2>&1
  ls -la "$OUT/mod.dll"
fi
echo "rc done in $(awk "BEGIN{printf \"%.1f\", $(date +%s.%N) - $s}") s"
