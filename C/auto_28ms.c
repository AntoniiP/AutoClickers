#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdbool.h>

// Delay for the click interval (lower is more intensive with more CPS)
#define CLICK_DELAY_MS 28

int main() {
    printf("AutoClicker started. Press NumpadAdd to toggle clicking on/off.\n");

    bool clicking = false;

    while (true) {
        // Listen for NumpadAdd key to toggle clicking
        if (GetAsyncKeyState(VK_ADD) & 1) {
            clicking = !clicking;
            if (clicking) {
                printf("Clicking started.\n");
            } else {
                printf("Clicking stopped.\n");
            }
        }

        if (clicking) {
            INPUT input = {0};
            input.type = INPUT_MOUSE;
            input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
            SendInput(1, &input, sizeof(INPUT));

            ZeroMemory(&input, sizeof(INPUT));
            input.type = INPUT_MOUSE;
            input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
            SendInput(1, &input, sizeof(INPUT));

            Sleep(CLICK_DELAY_MS);
        } else {
            // Small delay to prevent high CPU usage when not clicking
            Sleep(10);
        }
    }

    return 0;
}
