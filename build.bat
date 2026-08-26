@echo off
setlocal EnableDelayedExpansion

set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"

set "MLEXE="
call :FindX86Tool ml.exe MLEXE
if not defined MLEXE (
  echo error: 32-bit ml.exe not found. Run from a Visual Studio Developer Command Prompt
  echo        ^(x86 or x64_x86^), or install the MSVC x86 build tools with MASM.
  exit /b 1
)

set "LINKEXE="
call :FindX86Tool link.exe LINKEXE
if not defined LINKEXE (
  echo error: 32-bit link.exe not found. Run from a Visual Studio Developer Command Prompt
  echo        ^(x86 or x64_x86^), or install the MSVC x86 build tools.
  exit /b 1
)

set "KITLIB="
for /d %%v in ("C:\Program Files (x86)\Windows Kits\10\Lib\*") do (
  if exist "%%v\um\x86\kernel32.lib" set "KITLIB=%%v\um\x86"
)
if not defined KITLIB (
  echo error: Windows SDK um\x86 libraries not found.
  exit /b 1
)

"!MLEXE!" /nologo /c /coff /Cp trpad.asm
if errorlevel 1 exit /b 1

"!LINKEXE!" /nologo /SUBSYSTEM:WINDOWS /NODEFAULTLIB /MACHINE:X86 /SAFESEH:NO ^
  /OUT:trpad.exe trpad.obj ^
  /LIBPATH:"!KITLIB!" ^
  kernel32.lib user32.lib shell32.lib comdlg32.lib gdi32.lib
if errorlevel 1 (
  del trpad.obj >nul 2>nul
  exit /b 1
)

del trpad.obj
exit /b 0

rem ---------------------------------------------------------------------------
rem Find 32-bit ml.exe / link.exe. Prefer a PATH hit from the Developer Command
rem Prompt, but skip MASM32's copies. Fall back to vswhere's Host*\x86 tools.
rem ---------------------------------------------------------------------------
:FindX86Tool
set "FOUND="
where %1 >nul 2>nul
if not errorlevel 1 (
  for /f "delims=" %%i in ('where %1') do (
    echo %%i | findstr /i /c:"\masm32\" >nul
    if errorlevel 1 if not defined FOUND set "FOUND=%%i"
  )
)
if not defined FOUND if exist "!VSWHERE!" (
  for /f "usebackq delims=" %%i in (`call "!VSWHERE!" -latest -find **\Host*\x86\%1`) do (
    if not defined FOUND set "FOUND=%%i"
  )
)
set "%2=!FOUND!"
goto :eof
