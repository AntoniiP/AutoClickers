#include <iostream>
#include <windows.h>
#include <thread>
#include <atomic>

// Define a delay for the click interval
const int CLICK_DELAY_MS = 28;

std::atomic<bool> clicking(false);

void clickThread() {
    while (clicking) {
	INPUT input = {0};
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &input, sizeof(INPUT));

	ZeroMemory(&input, sizeof(INPUT));
	input.type = INPUT_MOUSE;
	input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &input, sizeof(INPUT));

	Sleep(CLICK_DELAY_MS);
    }
}

int main() {
    std::cout << "AutoClicker started. Press NumpadAdd to toggle clicking on/off." << std::endl;
    std::thread clicker;

    while (true) {
        // Listen for NumpadAdd key press to toggle clicking
        if (GetAsyncKeyState(VK_ADD) & 1) {
            clicking = !clicking;
            if (clicking) {
                std::cout << "Clicking started." << std::endl;
		clicker = std::thread(clickThread);
            } else {
                std::cout << "Clicking stopped." << std::endl;
            	if (clicker.joinable()) {
		    clicker.join();
		}
	    }
        }

        // Small delay to prevent high CPU usage
        Sleep(10);
    }
    
    if (clicker.joinable()) {
	clicker.join();
    }
    return 0;
}
