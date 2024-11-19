//
// idk if this works fine!!!
//

#include <string>
#include <windows.h>
#include <winternl.h>

typedef NTSTATUS(WINAPI* RtlGetVersionPtr)(PRTL_OSVERSIONINFOW);

std::string GetWindowsVersion() {
    RTL_OSVERSIONINFOW versionInfo;
    versionInfo.dwOSVersionInfoSize = sizeof(RTL_OSVERSIONINFOW);

    RtlGetVersionPtr RtlGetVersion = (RtlGetVersionPtr)GetProcAddress(GetModuleHandleA("ntdll.dll"), "RtlGetVersion");

    if (RtlGetVersion) {
        LONG result = RtlGetVersion(&versionInfo);
        if (result == 0) {
            std::string windowsVersion;
            if (versionInfo.dwMajorVersion == 10 && versionInfo.dwBuildNumber >= 22000) {
                windowsVersion = "Windows 11";
            }
            else {
                windowsVersion = "Windows " + std::to_string(versionInfo.dwMajorVersion);
            }

            HKEY hKey;
            std::string edition;
            if (RegOpenKeyExA(HKEY_LOCAL_MACHINE,
                "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion",
                0,
                KEY_READ,
                &hKey) == ERROR_SUCCESS) {
                char editionId[256];
                DWORD editionIdSize = sizeof(editionId);

                if (RegQueryValueExA(hKey, "EditionID", NULL, NULL, reinterpret_cast<LPBYTE>(editionId), &editionIdSize) == ERROR_SUCCESS) {
                    edition = editionId;
                }
                else {
                    edition = "Unknown Edition";
                }
                RegCloseKey(hKey);
            }
            else {
                edition = "Unknown Edition";
            }

            return windowsVersion + " - " + edition;
        }
    }
    return "Failed to get version.";
}
