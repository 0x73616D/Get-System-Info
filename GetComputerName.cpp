#include <string>
#include <stdexcept>
#include <windows.h>

std::string GetComputerName() {
    const int buffer_size = MAX_COMPUTERNAME_LENGTH + 1;
    char buffer[buffer_size];
    DWORD lpnSize = buffer_size;
    if (GetComputerNameA(buffer, &lpnSize) == FALSE) {
        throw std::runtime_error("Error getting computer name.");
    }
    std::string computerName = buffer;
    char domainBuffer[256];
    DWORD domainSize = sizeof(domainBuffer);
    if (GetComputerNameExA(ComputerNameDnsFullyQualified, domainBuffer, &domainSize)) {
        return std::string(domainBuffer);
    }
    return computerName;
}
