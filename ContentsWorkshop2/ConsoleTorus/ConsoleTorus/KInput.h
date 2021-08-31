#pragma once
#include <memory.h>

class KInput
{
public:
    enum ExtendedKeys
    {
        KEY_UP = 72,
        KEY_LEFT = 75,
        KEY_RIGHT = 77,
        KEY_DOWN = 80
    };
    enum VirtualKeys
    {
        VKEY_UP = 128+72,
        VKEY_LEFT = 128+75,
        VKEY_RIGHT = 128+77,
        VKEY_DOWN = 128+80
    };
private:
    int     m_keys[256];
public:
    static KInput& GetInstance()
    {
        static KInput i;
        return i;
    }

    KInput();
    ~KInput();
    void GetKeys();
    void InitKeys() {
        memset(m_keys, 0, sizeof(m_keys));
    }
    bool operator()(int ch)
    {
        return m_keys[ch] == 1;
    }
    void Update();
};

#define _KInput KInput::GetInstance()