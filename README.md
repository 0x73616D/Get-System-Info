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

## Compilation and Usage

1. Clone this repository:
    ```bash
    git clone https://github.com/0x73616D/Get-System-Info.git
    ```

2. Navigate into the project directory:
    ```bash
    cd windows-system-info
    ```

3. Compile the C++ files using your preferred compiler (e.g., MSVC or MinGW).

    For MSVC, you can use the following command:
    ```bash
    cl /EHsc your_file.cpp
    ```

4. Run the compiled executable to get system information.

    Example:
    ```bash
    ./your_program.exe
    ```

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
