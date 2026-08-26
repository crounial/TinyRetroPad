; Minimal Win32 constants and structs for TinyRetroPad
; Sufficient types/constants for trpad.asm with Visual Studio ml.exe

NULL                    equ 0
FALSE                   equ 0
TRUE                    equ 1
INVALID_HANDLE_VALUE    equ -1
CW_USEDEFAULT           equ 80000000h

; basic types (HWND etc. are synonyms for DWORD)
HWND        TYPEDEF DWORD
HINSTANCE   TYPEDEF DWORD
HDC         TYPEDEF DWORD
HMENU       TYPEDEF DWORD
HANDLE      TYPEDEF DWORD
HGLOBAL     TYPEDEF DWORD
UINT        TYPEDEF DWORD
WPARAM      TYPEDEF DWORD
LPARAM      TYPEDEF DWORD
BOOL        TYPEDEF DWORD
LPSTR       TYPEDEF DWORD
LPCSTR      TYPEDEF DWORD
COLORREF    TYPEDEF DWORD

; ---- window messages ----
WM_CREATE               equ 0001h
WM_DESTROY              equ 0002h
WM_SIZE                 equ 0005h
WM_PAINT                equ 000Fh
WM_CLOSE                equ 0010h
WM_QUIT                 equ 0012h
WM_KEYDOWN              equ 0100h
WM_INITDIALOG           equ 0110h
WM_COMMAND              equ 0111h
WM_SYSCOMMAND           equ 0112h
WM_TIMER                equ 0113h
WM_RBUTTONUP            equ 0205h
WM_CUT                  equ 0300h
WM_COPY                 equ 0301h
WM_PASTE                equ 0302h
WM_CLEAR                equ 0303h
WM_UNDO                 equ 0304h
WM_GETTEXT              equ 000Dh
WM_GETTEXTLENGTH        equ 000Eh
WM_NOTIFY               equ 004Eh
WM_USER                 equ 0400h

; ---- window styles ----
WS_OVERLAPPED           equ 00000000h
WS_POPUP                equ 80000000h
WS_CHILD                equ 40000000h
WS_VISIBLE              equ 10000000h
WS_CAPTION              equ 00C00000h
WS_BORDER               equ 00800000h
WS_DLGFRAME             equ 00400000h
WS_VSCROLL              equ 00200000h
WS_SYSMENU              equ 00080000h
WS_TABSTOP              equ 00010000h
WS_MINIMIZEBOX          equ 00020000h
WS_MAXIMIZEBOX          equ 00010000h
WS_THICKFRAME           equ 00040000h
WS_OVERLAPPEDWINDOW     equ WS_OVERLAPPED or WS_CAPTION or WS_SYSMENU or WS_THICKFRAME or WS_MINIMIZEBOX or WS_MAXIMIZEBOX

WS_EX_STATICEDGE        equ 00020000h

; edit styles
ES_LEFT                 equ 0000h
ES_MULTILINE            equ 0004h
ES_AUTOVSCROLL          equ 0040h
ES_NUMBER               equ 2000h

; button / dialog styles
BS_DEFPUSHBUTTON        equ 0001h
DS_MODALFRAME           equ 0080h

; show window
SW_HIDE                 equ 0
SW_SHOW                 equ 5
SW_SHOWNORMAL           equ 1

; SetWindowPos
SWP_NOZORDER            equ 0004h

; menus
MF_STRING               equ 0000h
MF_GRAYED               equ 0001h
MF_CHECKED              equ 0008h
MF_POPUP                equ 0010h
MF_SEPARATOR            equ 0800h
MF_BYCOMMAND            equ 0000h

; message box
MB_OK                   equ 00000000h
MB_YESNOCANCEL          equ 00000003h
MB_ICONQUESTION         equ 00000020h
MB_ICONINFORMATION      equ 00000040h
IDOK                    equ 1
IDCANCEL                equ 2
IDNO                    equ 7

; file I/O
GENERIC_READ            equ 80000000h
GENERIC_WRITE           equ 40000000h
FILE_SHARE_READ         equ 00000001h
CREATE_ALWAYS           equ 2
OPEN_EXISTING           equ 3
FILE_ATTRIBUTE_NORMAL   equ 00000080h
GMEM_FIXED              equ 0000h

; open file name flags
OFN_FILEMUSTEXIST       equ 00001000h
OFN_PATHMUSTEXIST       equ 00000800h
OFN_HIDEREADONLY        equ 00000004h
OFN_OVERWRITEPROMPT     equ 00000002h

; find/replace
FR_DOWN                 equ 00000001h
FR_MATCHCASE            equ 00000004h
FR_REPLACE              equ 00000010h
FR_REPLACEALL           equ 00000020h
FR_DIALOGTERM           equ 00000040h

; choose font
CF_SCREENFONTS          equ 00000001h
CF_EFFECTS              equ 00000100h
LF_FACESIZE             equ 32

; print dialog
PD_RETURNDC             equ 00000100h
PD_NOPAGENUMS           equ 00000008h
PD_NOSELECTION          equ 00000004h

; device caps
HORZRES                 equ 8
VERTRES                 equ 10
LOGPIXELSX              equ 88
LOGPIXELSY              equ 90

; virtual keys
VK_SHIFT                equ 10h
VK_CONTROL              equ 11h
VK_F3                   equ 72h
VK_F5                   equ 74h

; date/time
DATE_SHORTDATE          equ 00000001h
LOCALE_USER_DEFAULT     equ 0400h

; rich edit messages commonly used (edit-compatible ones)
EM_REPLACESEL           equ 00C2h
EM_LINEINDEX            equ 00BBh
EM_SCROLLCARET          equ 00B7h
EM_SETSEL               equ 00B1h
EM_EXGETSEL             equ WM_USER+52
EM_EXSETSEL             equ WM_USER+55
EM_EXLINEFROMCHAR       equ WM_USER+54
EM_FINDTEXTEXA          equ WM_USER+79
EN_CHANGE               equ 0300h
EN_SELCHANGE            equ 0702h
EN_MSGFILTER            equ 0700h
ENM_SELCHANGE           equ 00080000h
ENM_MOUSEEVENTS         equ 00020000h

; charformat masks/effects used by font dialog
CFM_SIZE                equ 80000000h
CFM_BOLD                equ 00000001h
CFM_ITALIC              equ 00000002h
CFE_BOLD                equ 00000001h
CFE_ITALIC              equ 00000002h

; ---- structures ----
POINT STRUCT
  x     DWORD ?
  y     DWORD ?
POINT ENDS

RECT STRUCT
  left      DWORD ?
  top       DWORD ?
  right     DWORD ?
  bottom    DWORD ?
RECT ENDS

MSG STRUCT
  hwnd      DWORD ?
  message   DWORD ?
  wParam    DWORD ?
  lParam    DWORD ?
  time      DWORD ?
  pt        POINT <>
MSG ENDS

WNDCLASS STRUCT
  style         DWORD ?
  lpfnWndProc   DWORD ?
  cbClsExtra    DWORD ?
  cbWndExtra    DWORD ?
  hInstance     DWORD ?
  hIcon         DWORD ?
  hCursor       DWORD ?
  hbrBackground DWORD ?
  lpszMenuName  DWORD ?
  lpszClassName DWORD ?
WNDCLASS ENDS

SYSTEMTIME STRUCT
  wYear         WORD ?
  wMonth        WORD ?
  wDayOfWeek    WORD ?
  wDay          WORD ?
  wHour         WORD ?
  wMinute       WORD ?
  wSecond       WORD ?
  wMilliseconds WORD ?
SYSTEMTIME ENDS

OPENFILENAMEA STRUCT
  lStructSize       DWORD ?
  hwndOwner         DWORD ?
  hInstance         DWORD ?
  lpstrFilter       DWORD ?
  lpstrCustomFilter DWORD ?
  nMaxCustFilter    DWORD ?
  nFilterIndex      DWORD ?
  lpstrFile         DWORD ?
  nMaxFile          DWORD ?
  lpstrFileTitle    DWORD ?
  nMaxFileTitle     DWORD ?
  lpstrInitialDir   DWORD ?
  lpstrTitle        DWORD ?
  Flags             DWORD ?
  nFileOffset       WORD ?
  nFileExtension    WORD ?
  lpstrDefExt       DWORD ?
  lCustData         DWORD ?
  lpfnHook          DWORD ?
  lpTemplateName    DWORD ?
OPENFILENAMEA ENDS

FINDREPLACEA STRUCT
  lStructSize       DWORD ?
  hwndOwner         DWORD ?
  hInstance         DWORD ?
  Flags             DWORD ?
  lpstrFindWhat     DWORD ?
  lpstrReplaceWith  DWORD ?
  wFindWhatLen      WORD ?
  wReplaceWithLen   WORD ?
  lCustData         DWORD ?
  lpfnHook          DWORD ?
  lpTemplateName    DWORD ?
FINDREPLACEA ENDS

CHARRANGE STRUCT
  cpMin     DWORD ?
  cpMax     DWORD ?
CHARRANGE ENDS

FINDTEXTEXA STRUCT
  chrg          CHARRANGE <>
  lpstrText     DWORD ?
  chrgText      CHARRANGE <>
FINDTEXTEXA ENDS

LOGFONTW STRUCT
  lfHeight          DWORD ?
  lfWidth           DWORD ?
  lfEscapement      DWORD ?
  lfOrientation     DWORD ?
  lfWeight          DWORD ?
  lfItalic          BYTE ?
  lfUnderline       BYTE ?
  lfStrikeOut       BYTE ?
  lfCharSet         BYTE ?
  lfOutPrecision    BYTE ?
  lfClipPrecision   BYTE ?
  lfQuality         BYTE ?
  lfPitchAndFamily  BYTE ?
  lfFaceName        WORD LF_FACESIZE dup(?)
LOGFONTW ENDS

CHOOSEFONTW STRUCT
  lStructSize       DWORD ?
  hwndOwner         DWORD ?
  hDC               DWORD ?
  lpLogFont         DWORD ?
  iPointSize        DWORD ?
  Flags             DWORD ?
  rgbColors         DWORD ?
  lCustData         DWORD ?
  lpfnHook          DWORD ?
  lpTemplateName    DWORD ?
  hInstance         DWORD ?
  lpszStyle         DWORD ?
  nFontType         WORD ?
  ___MISSING_ALIGNMENT__ WORD ?
  nSizeMin          DWORD ?
  nSizeMax          DWORD ?
CHOOSEFONTW ENDS

; CHARFORMATW is 92 bytes (matches RichFont data layout in trpad.asm)
CHARFORMATW STRUCT
  cbSize            DWORD ?
  dwMask            DWORD ?
  dwEffects         DWORD ?
  yHeight           DWORD ?
  yOffset           DWORD ?
  crTextColor       DWORD ?
  bCharSet          BYTE ?
  bPitchAndFamily   BYTE ?
  szFaceName        WORD LF_FACESIZE dup(?)
  _wPad2            WORD ?
CHARFORMATW ENDS

PRINTDLGA STRUCT
  lStructSize         DWORD ?
  hwndOwner           DWORD ?
  hDevMode            DWORD ?
  hDevNames           DWORD ?
  hDC                 DWORD ?
  Flags               DWORD ?
  nFromPage           WORD ?
  nToPage             WORD ?
  nMinPage            WORD ?
  nMaxPage            WORD ?
  nCopies             WORD ?
  hInstance           DWORD ?
  lCustData           DWORD ?
  lpfnPrintHook       DWORD ?
  lpfnSetupHook       DWORD ?
  lpPrintTemplateName DWORD ?
  lpSetupTemplateName DWORD ?
  hPrintTemplate      DWORD ?
  hSetupTemplate      DWORD ?
PRINTDLGA ENDS

DOCINFOA STRUCT
  cbSize        DWORD ?
  lpszDocName   DWORD ?
  lpszOutput    DWORD ?
  lpszDatatype  DWORD ?
  fwType        DWORD ?
DOCINFOA ENDS

FORMATRANGE STRUCT
  hdc           DWORD ?
  hdcTarget     DWORD ?
  rc            RECT <>
  rcPage        RECT <>
  chrg          CHARRANGE <>
FORMATRANGE ENDS

PAGESETUPDLGA STRUCT
  lStructSize             DWORD ?
  hwndOwner               DWORD ?
  hDevMode                DWORD ?
  hDevNames               DWORD ?
  Flags                   DWORD ?
  ptPaperSize             POINT <>
  rtMinMargin             RECT <>
  rtMargin                RECT <>
  hInstance               DWORD ?
  lCustData               DWORD ?
  lpfnPageSetupHook       DWORD ?
  lpfnPagePaintHook       DWORD ?
  lpPageSetupTemplateName DWORD ?
  hPageSetupTemplate      DWORD ?
PAGESETUPDLGA ENDS

PAINTSTRUCT STRUCT
  hdc           DWORD ?
  fErase        DWORD ?
  rcPaint       RECT <>
  fRestore      DWORD ?
  fIncUpdate    DWORD ?
  rgbReserved   BYTE 32 dup(?)
PAINTSTRUCT ENDS
