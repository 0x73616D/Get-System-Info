#include <array>
#include <string>
#include <cstring>
#include <iostream>

std::string GetCPU()
{
    std::array<int, 4> integerBuffer = {};
    constexpr size_t sizeofIntegerBuffer = sizeof(int) * integerBuffer.size();

    std::array<char, 64> charBuffer = {};

    constexpr std::array<int, 3> functionIds = {
        // Manufacturer
        0x80000002,
        // Model
        0x80000003,
        // Clockspeed
        0x80000004
    };

    std::string cpu;

    for (int id : functionIds)
    {
        __cpuid(integerBuffer.data(), id);
        std::memcpy(charBuffer.data(), integerBuffer.data(), sizeofIntegerBuffer);
        cpu += std::string(charBuffer.data());
    }
    return cpu;
}
