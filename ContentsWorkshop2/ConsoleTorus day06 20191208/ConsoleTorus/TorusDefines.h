#pragma once
#include <string>
#include <windows.h>
#include <deque>
#include "KVector2.h"

extern const std::string g_torusText[4];

enum TORUS
{
    TORUS_RED = 0,
    TORUS_GREEN,
    TORUS_BLUE,
    TORUS_MAGENTA,
    TORUS_MAX
};

void gotoxy( int x, int y );
void SetColor( WORD fore, WORD back );
void ShowConsoleCursor( bool showFlag );
void DrawText( int x, int y, const std::string& text );
void DrawText(int x, int y, int numRows, const std::string& text);
void DrawDeque(std::deque<TORUS> g, int x, int y, int maxQueue);
