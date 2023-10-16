#include <iostream>
#include <conio.h>
#include <windows.h>

int main() {
	while (1) {
		if (GetKeyState(VK_RSHIFT) & 0x8000) {
			std::cout << "Right Shift key pressed" << std::endl;
			return 1;
		}
		if (GetKeyState(VK_LCONTROL) & 0x8000) {
			std::cout << "Left Control key pressed" << std::endl;
			return 2;
		}
	}
}

