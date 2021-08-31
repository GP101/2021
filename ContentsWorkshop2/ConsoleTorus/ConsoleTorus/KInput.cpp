#include "KInput.h"
#include <conio.h>

KInput::KInput()
{
}

KInput::~KInput()
{
}

void KInput::GetKeys()
{
    if (_kbhit()) {
        int ch = _getch();
        if (ch == 224 || ch == 0) {
            ch = _getch();
            m_keys[ch + 128] = 1;
        }
        else
        {
            m_keys[ch] = 1;
        }
    }
}

void KInput::Update()
{
    InitKeys();
    GetKeys();
}