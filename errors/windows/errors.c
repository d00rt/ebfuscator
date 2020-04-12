#include <windows.h>
#include <psapi.h>
#include <stdio.h>
#include <tlhelp32.h>
#include <unistd.h>

#include "errors.h"

void
generate_error_1(void)
{
    //ERROR_INVALID_FUNCTION
    SetLastError(1);
//    HANDLE hFile;
//
//    hFile = CreateFile(
//                "\\\\.\\NetBT",
//                GENERIC_READ | GENERIC_WRITE, 0, NULL,
//                OPEN_EXISTING, 0, NULL
//    );
//
    //CHECK_ERROR_CODE(1);
//
//    if (hFile != INVALID_HANDLE_VALUE)
//    {
//        CloseHandle(hFile);
//        return;
//    }
}

void
generate_error_2(void)
{
    //ERROR_FILE_NOT_FOUND
    CreateFile(
        "ERROR_SHELLCODE_WINDOWS_BY_D00RT",
        GENERIC_READ | GENERIC_WRITE, 0, NULL,
        OPEN_EXISTING, 0, NULL
    );
}

void
generate_error_3(void)
{
    //ERROR_PATH_NOT_FOUND
    CreateFile(
        "C:\\ERROR\\SHELLCODE\\WINDOWS\\BY\\D00RT",
        GENERIC_READ | GENERIC_WRITE, 0, NULL,
        OPEN_EXISTING, 0, NULL
    );
}

void
generate_error_5(void)
{
    //ERROR_ACCESS_DENIED
    CreateFile(
        "C:\\Windows\\System32\\user32.dll",
        GENERIC_READ | GENERIC_WRITE, 0, NULL,
        OPEN_EXISTING, 0, NULL
    );
}

void
generate_error_6(void)
{
    //ERROR_INVALID_HANDLE
    DWORD lpNumberOfBytesWritten;
    WriteFile((HANDLE)0xFFFFFFFF, NULL, 0, &lpNumberOfBytesWritten, NULL);
}

void
generate_error_18(void)
{
    //ERROR_NO_MORE_FILES
    WIN32_FIND_DATA ffd;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    LPSTR szPath, szFPath;
    szPath = _getcwd(NULL, MAX_PATH - 1);

    size_t path_len = strlen(szPath);
    szFPath = calloc(path_len + 2 + 1, 1);

    memcpy(szFPath, szPath, path_len);
    memcpy(szFPath + path_len, TEXT("\\*"), 2);
    szFPath[path_len + 2] = 0;

    hFind = FindFirstFileA((LPCSTR)szFPath, &ffd);
    do
    {
    }
    while (FindNextFileA(hFind, &ffd) != 0);
    free(szFPath);
}

void
generate_error_24(void)
{
    //ERROR_BAD_LENGTH
    HANDLE hSnap;
    PROCESSENTRY32 pe;

    hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    Process32First(hSnap, &pe);
    //CHECK_ERROR_CODE(24);
}

void
generate_error_32(void)
{
    //ERROR_TOO_MANY_OPEN_FILES
    CreateFile(
        "C:\\Windows\\System32\\rundll32.exe",
        GENERIC_READ, 0, NULL,
        OPEN_EXISTING, 0, NULL
    );
    CreateFile(
        "C:\\Windows\\System32\\rundll32.exe",
        GENERIC_READ, 0, NULL,
        OPEN_EXISTING, 0, NULL
    );
}

void
generate_error_126(void)
{
    LoadLibrary("C:\\D00RT.DLL");
}
