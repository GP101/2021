#include "TorusDefines.h"
#include <iostream>
#include <deque>

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

//{{ day04
void SetColor( WORD fore, WORD back )
{
    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

    WORD attribute;
    attribute = ( back & 0x0f ) << 4 | ( fore & 0x0f );
    SetConsoleTextAttribute( hConsole, attribute );

    /** predefined flags
        FOREGROUND_BLUE
        FOREGROUND_GREEN
        FOREGROUND_RED
        FOREGROUND_INTENSITY
        BACKGROUND_BLUE
        BACKGROUND_GREEN
        BACKGROUND_RED
        BACKGROUND_INTENSITY
        */
}

void ShowConsoleCursor( bool showFlag )
{
    HANDLE out = GetStdHandle( STD_OUTPUT_HANDLE );
    CONSOLE_CURSOR_INFO     cursorInfo;
    GetConsoleCursorInfo( out, &cursorInfo );
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo( out, &cursorInfo );
}
//}} day04

void DrawText(int x, int y, const std::string& text)
{
    gotoxy(x, y);
    std::cout << text.c_str();
}

//{{ day04
void DrawText(int x, int y, int numRows, const std::string& text)
{
    int tx = x;
    int ty = y;
    for (int i = 0; i < numRows; ++i) {
        DrawText(tx, ty, text);
        ty += 1;
    }
}
//}} day04

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
