//the following line is necessary for the GetConsoleWindow() function to work!
//it basically says that you are running this program on Windows 2000 or higher
#define _WIN32_WINNT 0x0500
//it is important that the above line be typed BEFORE <windows.h> is included
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

const int g_width = 200;
const int g_height = 60;
HWND g_hwndConsole = 0;
HANDLE g_hConsole = 0;

void gotoxy(int x, int y)
{
    _COORD pos{ (short)x,(short)y };
    SetConsoleCursorPosition(g_hConsole, pos);
}

void ShowCursor(bool visible)
{
    CONSOLE_CURSOR_INFO cursorInfo{ 1,visible };
    SetConsoleCursorInfo(g_hConsole, &cursorInfo);
}

void ScreenSize(int x, int y)
{
    COORD coord{ (short)x,(short)y };
    _SMALL_RECT Rect{ 0,0,(short)y - 1,(short)x - 1 };
    // Adjust buffer size:
    SetConsoleScreenBufferSize(g_hConsole, coord);
    // display as a maximized window
    ShowWindow(g_hwndConsole, SW_MAXIMIZE);
}

int main(void)
{
    g_hwndConsole = GetConsoleWindow();
    g_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ScreenSize(g_width, g_height);
    ShowCursor(false);
    for (int x = 0; x < g_width; ++x) {
        for (int y = 0; y < g_height; ++y) {
            gotoxy(x, y);
            printf(".");
        }
    }
    _getch();
}
