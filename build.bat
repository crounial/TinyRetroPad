@echo off
setlocal EnableDelayedExpansion

ml /nologo /c /coff /Cp /IC:\masm32\include trpad.asm
if errorlevel 1 exit /b 1

set "LINKEXE="
where link >nul 2>nul
if not errorlevel 1 (
  for /f "delims=" %%i in ('where link') do (
    if not defined LINKEXE set "LINKEXE=%%i"
  )
)

if not defined LINKEXE (
  set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"
  if exist "!VSWHERE!" (
    for /f "usebackq delims=" %%i in (`call "!VSWHERE!" -latest -find **\Host*\x86\link.exe`) do (
      if not defined LINKEXE set "LINKEXE=%%i"
    )
  )
)

if not defined LINKEXE (
  echo error: link.exe not found. Install MSVC or run from a Developer Command Prompt.
  del trpad.obj >nul 2>nul
  exit /b 1
)

set "KITLIB="
for /d %%v in ("C:\Program Files (x86)\Windows Kits\10\Lib\*") do (
  if exist "%%v\um\x86\kernel32.lib" set "KITLIB=%%v\um\x86"
)
if not defined KITLIB (
  echo error: Windows SDK um\x86 libraries not found.
  del trpad.obj >nul 2>nul
  exit /b 1
)

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
