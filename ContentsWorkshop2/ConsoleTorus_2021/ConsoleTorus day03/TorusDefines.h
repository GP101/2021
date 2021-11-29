#pragma once
#include <string>
#include <windows.h>
#include <deque>
//{{ day03
#include "KVector2.h"
//}} day03

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
void DrawDeque(std::deque<TORUS> g, int x, int y, int maxQueue);
