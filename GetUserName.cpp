#include <string>
#include <stdexcept>  
#include <windows.h> 

std::string GetUserName() {
    const int buffer_size = 256;
    char buffer[buffer_size];
    DWORD bufferSize = buffer_size;
    if (GetUserNameA(buffer, &bufferSize) == FALSE) {
        throw std::runtime_error("Error getting username.");
    }
    return std::string(buffer);
}
