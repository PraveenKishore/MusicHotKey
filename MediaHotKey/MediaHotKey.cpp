#include<iostream>
#include<Windows.h>

using namespace std;

void simulateKey(int keycode) {
	KEYBDINPUT kbi;
	kbi.wVk = keycode;
	kbi.dwFlags = 0;  // See docs for flags (mm keys may need Extended key flag)
	kbi.wScan = 0;
	kbi.time = 0;
	kbi.dwExtraInfo = (ULONG_PTR) GetMessageExtraInfo();

	INPUT input;
	input.type = INPUT_KEYBOARD;
	input.ki   = kbi;

	SendInput(1, &input, sizeof(INPUT));
	Sleep(350);
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPTSTR lpCmdLine, int cmdShow) {
	while(1) {
		if(GetAsyncKeyState(VK_RCONTROL)) {
			if(GetAsyncKeyState(VK_RIGHT)) {	// Control + Right Arrow for Next track
				cout << "Right" << endl;
				simulateKey(VK_MEDIA_NEXT_TRACK);
			} else if(GetAsyncKeyState(VK_LEFT)) {	// Control + Left Arrow for Previous track
				cout << "Left" << endl;
				simulateKey(VK_MEDIA_PREV_TRACK);
			} else if(GetAsyncKeyState(VK_UP)) {	// Control + Up Arrow to Play/Pause track
				cout << "Play/Pause" << endl;
				simulateKey(VK_MEDIA_PLAY_PAUSE);
			}
		}
		Sleep(250);
	}
}