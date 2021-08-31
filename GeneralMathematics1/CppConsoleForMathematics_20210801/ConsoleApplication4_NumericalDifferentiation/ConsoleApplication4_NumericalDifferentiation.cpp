#include "MyUtil.h"
#include "Scene.h"
#include <cwchar>

Scene g_scene;

int main(void)
{
    g_hwndConsole = GetConsoleWindow();
    g_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ScreenSize(g_width, g_height);
    ShowCursor(false);

    int ch = 0;
    clock_t prevClock = clock();
    clock_t currClock = prevClock;

    while (ch != 27)
    {
        if (_kbhit())
        {
            ch = _getch();
        }
        prevClock = currClock;
        currClock = clock();
        const double elapsedTime = ((double)currClock - (double)prevClock) / CLOCKS_PER_SEC;
        ClearBuffer();
        g_scene.Update(elapsedTime);
        Sleep(10);
        DrawBuffer();
    }
}
