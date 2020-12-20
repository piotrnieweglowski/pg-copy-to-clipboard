#include "clipboard.h"
#include "windows.h"

void SetClipboardText(const char* text)
{
    const size_t length = strlen(text) + 1;
    HGLOBAL hMemory =  GlobalAlloc(GMEM_MOVEABLE, length);
    memcpy(GlobalLock(hMemory), text, length);
    GlobalUnlock(hMemory);
    OpenClipboard(0);
    EmptyClipboard();
    SetClipboardData(CF_TEXT, hMemory);
    CloseClipboard();
}