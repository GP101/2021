#include "MyUtil.h"
#include <cwchar>

double F(double x)
{
    return x*x + 2;
}

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
        double x = -10;
        double y;
        double oldx = x;
        double oldy = F(x);
        while (x <= 10)
        {
            y = F(x);
            PutCh(x+100, (-y+60), '*');
            x += 1;
            oldx = x;
            oldy = y;
        }
        Sleep(10);
        DrawBuffer();
    }
}
