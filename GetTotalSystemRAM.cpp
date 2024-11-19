#include <string>
#include <windows.h>

std::string GetTotalSystemRAM() {
    MEMORYSTATUSEX statex;
    statex.dwLength = sizeof(statex);
    if (GlobalMemoryStatusEx(&statex)) {
        unsigned long long totalRAM_GB = statex.ullTotalPhys / (1024 * 1024 * 1024);
        return std::to_string(totalRAM_GB) + " GB";
    }
    else {
        return "Error retrieving memory information.";
    }
}
