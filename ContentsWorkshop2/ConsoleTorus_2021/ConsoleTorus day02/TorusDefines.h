#pragma once
#include <string>
#include <windows.h>
//{{ day02
#include <deque>
//}} day02

extern const std::string g_torusText[4];

enum TORUS
{
    TORUS_RED = 0,
    TORUS_GREEN,
    TORUS_BLUE,
    TORUS_MAGENTA
};

void gotoxy( int x, int y );
void DrawText( int x, int y, const std::string& text );
//{{ day02
void DrawDeque(std::deque<TORUS> g, int x, int y, int maxQueue);
//}} day02