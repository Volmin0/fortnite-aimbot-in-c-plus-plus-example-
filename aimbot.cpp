#include <iostream>
#include <Windows.h>

int main() {
    HWND fortniteWindow = FindWindowA(NULL, "Fortnite"); // Adjust the window title if needed

    if (fortniteWindow) {
        DWORD processId;
        GetWindowThreadProcessId(fortniteWindow, &processId);
        HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processId);

        // Locate memory addresses for player and enemy positions, adjust accordingly
        uintptr_t playerBaseAddr = 0x12345678; // Example address for player base
        uintptr_t enemyBaseAddr = 0x87654321; // Example address for enemy base

        while (true) {
            // Read player and enemy positions from memory
            float playerX, playerY, enemyX, enemyY;
            ReadProcessMemory(hProcess, (LPVOID)(playerBaseAddr + 0x10), &playerX, sizeof(float), NULL);
            ReadProcessMemory(hProcess, (LPVOID)(playerBaseAddr + 0x14), &playerY, sizeof(float), NULL);
            ReadProcessMemory(hProcess, (LPVOID)(enemyBaseAddr + 0x10), &enemyX, sizeof(float), NULL);
            ReadProcessMemory(hProcess, (LPVOID)(enemyBaseAddr + 0x14), &enemyY, sizeof(float), NULL);

            // Implement your aimbot logic here, adjusting crosshair accordingly

            // Be cautious to avoid detection and ban mechanisms
            Sleep(10); // Adjust sleep time as needed
        }

        CloseHandle(hProcess);
    }

    return 0;
}
