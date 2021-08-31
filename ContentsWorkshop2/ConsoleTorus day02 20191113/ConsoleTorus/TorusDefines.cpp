#include "TorusDefines.h"
#include <iostream>
//{{ day02
#include <deque>
//}} day02

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

//{{ day02
void DrawDeque(std::deque<TORUS> g, int x, int y, int maxQueue )
{
    int cx = x;
    int cy = y;
    std::deque<TORUS>::iterator it;
    int numEmpty = maxQueue - g.size();
    for (int i = 0; i < numEmpty; i++)
    {
        DrawText(cx, cy, "---");
        cy += 1;
    }
    for (it = g.begin(); it != g.end(); it++)
    {
        DrawText(cx, cy, g_torusText[*it]);
        cy += 1;
    }
}
//}} day02