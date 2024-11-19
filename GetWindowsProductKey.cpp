#include <string>
#include <stdexcept>
#include <windows.h>

std::string GetWindowsProductKey() {
    HKEY keyHandle;
    BYTE rgValue[1024];
    char fnlRes[1024];
    DWORD size1;
    DWORD Type;

    if (RegOpenKeyExW(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion", 0, KEY_QUERY_VALUE | KEY_WOW64_64KEY, &keyHandle) == ERROR_SUCCESS) {
        size1 = sizeof(rgValue);

        if (RegQueryValueExW(keyHandle, L"DigitalProductId", NULL, &Type, rgValue, &size1) == ERROR_SUCCESS) {
            RegCloseKey(keyHandle);

            const char* chars = "BCDFGHJKMPQRTVWXY2346789";
            int keyLength = 29;
            std::string productKey;

            for (int n = 0; n < keyLength; n++) {
                int current = 0;
                for (int m = 14; m >= 0; m--) {
                    current = current * 256 + rgValue[m + 52];
                    rgValue[m + 52] = current / 24;
                    current %= 24;
                }
                productKey += chars[current];
                if ((n + 1) % 5 == 0 && n != 29) {
                    productKey += '-';
                }
            }

            snprintf(fnlRes, sizeof(fnlRes), "%s", productKey.c_str());
            return fnlRes;
        }
        else {
            RegCloseKey(keyHandle);
            return "Couldn't retrieve product key.";
        }
    }
    else {
        return "Couldn't access system information!";
    }
}
