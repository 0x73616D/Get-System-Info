# Windows System Info Utility

This repository provides a collection of C++ functions for retrieving various system information on a Windows machine. These functions allow you to access details about the user's environment, including system hardware, software, and configuration.

## Features

- **GetUserName**: Retrieves the current logged-in user's username.
- **GetComputerName**: Retrieves the name of the computer.
- **GetWindowsProductKey**: Retrieves the Windows product key from the system registry.
- **GetMACAddress**: Retrieves the MAC address of the machine's network adapter.
- **GetUUIDAddress**: Retrieves the unique system UUID.
- **GetCPU**: Retrieves details about the CPU, such as manufacturer, model, and clock speed.
- **GetGPUName**: Retrieves the name of the system's graphics card.
- **GetTotalSystemRAM**: Retrieves the total system RAM.
- **GetWindowsVersion**: Retrieves the version and edition of the installed Windows operating system.

## Requirements

- **Operating System**: Windows 7 or later.
- **Compiler**: A C++ compiler supporting C++11 or later (e.g., MSVC, MinGW).

## Usage

To use this project, select the desired function from the repository and ensure the necessary libraries and headers are included in your C++ project.

### Steps to Use:

1. **Select a Function**: Choose the function you want to use (e.g., `GetCPU()`).
2. **Create a New File**: Create a new C++ file in your project and paste the function code into it.
3. **Include Headers**: Ensure you include the necessary libraries and headers as required by the function (e.g., `<iostream>`, `<windows.h>`, etc.).
4. **Compile Your Code**: Compile your C++ code using your preferred compiler (e.g., MSVC or MinGW).
5. **Run the Executable**: Execute the compiled program to retrieve the system information.

## Example Usage

Here’s an example of how to use the functions in your program:

```cpp
#include "SystemInfo.h"

int main() {
    std::cout << "User Name: " << GetUserName() << std::endl;
    std::cout << "Computer Name: " << GetComputerName() << std::endl;
    std::cout << "Windows Version: " << GetWindowsVersion() << std::endl;
    std::cout << "Total RAM: " << GetTotalSystemRAM() << std::endl;
    return 0;
}
```

### Expected Output

Assuming the system is configured as follows:

- **User Name**: JohnDoe
- **Computer Name**: DESKTOP-ABC1234
- **Windows Version**: Windows 10 Pro
- **Total RAM**: 16 GB

The output of the program would look something like this:

```bash
User Name: JohnDoe
Computer Name: DESKTOP-ABC1234
Windows Version: Windows 10 Pro - 20H2
Total RAM: 16 GB
```

## Disclaimer
These code snippets are provided for educational and research purposes only. The creator of these snippets does not condone or support any illegal or malicious activity, and will not be held responsible for any such actions taken by others who may use this code. By downloading or using these snippets, you acknowledge that you are solely responsible for any consequences that may result from the use of this code.
