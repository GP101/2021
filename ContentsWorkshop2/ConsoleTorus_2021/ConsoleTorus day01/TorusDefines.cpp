#include "TorusDefines.h"
#include <iostream>

const std::string g_torusText[4] = {
    "RRR",
    "GGG",
    "BBB",
    "MMM",
};

void gotoxy( int x, int y )
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}

void DrawText( int x, int y, const std::string& text )
{
    gotoxy( x, y );
    std::cout << text.c_str();
}
