#pragma once
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <time.h>

extern const int g_width;
extern const int g_height;
extern HWND g_hwndConsole;
extern HANDLE g_hConsole;

void GotoXY(int x, int y);
void ShowCursor(bool visible);
void ScreenSize(int x, int y, int fontSizeX = 8, int fontSizeY = 8);
void PutCh(int x, int y, char ch);
void PutText(int x, int y, const char* text);
void ClearBuffer();
void DrawBuffer();
void ScanLine(int x0, int y0, int x1, int y1, char ch);
