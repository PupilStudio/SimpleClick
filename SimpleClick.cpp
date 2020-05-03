#include <iostream>
#include <Windows.h>
using namespace std;

#define ull unsigned long long

void delay(ull ms) {
	ull end = GetTickCount() + ms;
	while (GetTickCount() < end) ;
}

int main() {
	while (true) {
		ull cnt;
		cout << "输入点击次数:";
		cin >> cnt;
	
		ull wait;
		cout << "1000毫秒=1秒\n输入(两次点击之间)等待时长(毫秒):";
		cin >> wait;
		cout << "10秒之后将开始点击!请把鼠标移动到要点击的地方" << endl; 
	
		for (int i = 0; i != 9; ++i) {
			Beep(440, 800);
			delay(200);
		}
		Beep(880, 1200);
	
		for (ull i = 0; i != cnt; ++i) {
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			if (!(i % 10))
				Beep(880, wait);
			else  
				delay(wait);
		}
		Beep(440, 1500);
		cout << "完事了~" << endl; 
	}
	return 0;
}
