#include "MyUtil.h"
#include "Scene.h"
#include <cwchar>

Scene g_scene;

//void PrintDisc(int left, int top, int width)
//{
//	char buffer[80];
//	int index = 0;
//	for (int i = 0; i < width; ++i)
//	{
//		buffer[index] = '=';
//		buffer[index+width+1] = '=';
//		index += 1;
//	}
//	buffer[width] = '|';
//	buffer[width * 2 + 1] = 0; // EOS
//	PutText(left, top, buffer);
//}
//
//void PrintTower(int left, int top, int numDisc)
//{
//	for (int i = 1; i < numDisc; ++i)
//		PrintDisc(left - i, top + i, i);
//}

int main(void)
{
    g_hwndConsole = GetConsoleWindow();
    g_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ScreenSize(g_width, g_height, 8, 16);
    ShowCursor(false);

    int ch = 0;
    clock_t prevClock = clock();
    clock_t currClock = prevClock;
	g_scene.Start();

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
		g_scene.Draw(elapsedTime);
		//PrintTower(60, 40, 11); // test tower drawing
        Sleep(10);
        DrawBuffer();
    }
}
