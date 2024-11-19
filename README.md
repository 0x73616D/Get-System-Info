# Windows System Info Utility

This repository contains a set of C++ functions for retrieving various system information on a Windows machine. The functions provided can be used to get details about the user's environment, including system hardware, software, and configuration.

## Features

- **GetUserName**: Retrieves the current logged-in user's username.
- **GetComputerName**: Retrieves the name of the computer.
- **GetWindowsProductKey**: Retrieves the Windows product key from the system registry.
- **GetMACAddress**: Retrieves the MAC address of the machine's network adapter.
- **GetUUIDAddress**: Retrieves the unique system UUID.
- **GetCPU**: Retrieves CPU details like manufacturer, model, and clock speed.
- **GetGPUName**: Retrieves the name of the system's graphics card.
- **GetTotalSystemRAM**: Retrieves the total system RAM.
- **GetWindowsVersion**: Retrieves the version and edition of the installed Windows operating system.

## Requirements

- Windows OS (the code is designed for Windows 7 and later)
- A C++ compiler that supports C++11 or later

## Usage

To use this project, simply take the code for the function you wish to use and ensure that you include the necessary libraries and headers.

For example:

1. Choose the function you want to use (e.g., `GetCPU()`) and copy the code.
2. Create a new C++ file and paste the function code into your project.
3. Include the required headers and libraries as indicated within the function code (e.g., `<iostream>`, `<windows.h>`, etc.).
4. Compile your C++ code with your preferred compiler (e.g., MSVC or MinGW).
5. Run the compiled executable to retrieve the system information.

## Example Usage

Here is an example of how you might use the functions:

```cpp
#include "SystemInfo.h"

int main() {
    std::cout << "User Name: " << GetUserName() << std::endl;
    std::cout << "Computer Name: " << GetComputerName() << std::endl;
    std::cout << "Windows Version: " << GetWindowsVersion() << std::endl;
    std::cout << "Total RAM: " << GetTotalSystemRAM() << std::endl;
    return 0;
}
