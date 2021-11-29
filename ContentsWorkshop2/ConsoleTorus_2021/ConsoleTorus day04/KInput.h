#pragma once
#include <memory.h>

class KInput
{
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