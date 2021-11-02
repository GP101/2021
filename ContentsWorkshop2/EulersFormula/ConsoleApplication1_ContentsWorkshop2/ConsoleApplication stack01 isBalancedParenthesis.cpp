#include <list>
#include <iostream>
#include <conio.h>
#include <stack>

int isBalancedParenthesis(char* expn)
{
    std::stack<int> stk;
    //StackInitialize(&stk);
    int i = 0;
    char ch;
    while ((ch = expn[i++]) != '\0')
    {
        switch (ch)
        {
        case '{':
        case '[':
        case '(':
            stk.push(ch);
            break;
        case '}':
        {
            char t = stk.top();
            stk.pop();
            if (t != '{')
                return 0;
        }
            break;
        case ']':
        {
            char t = stk.top();
            stk.pop();
            if (t != '[')
                return 0;
        }
            break;
        case ')':
        {
            char t = stk.top();
            stk.pop();
            if (t != '(')
                return 0;
        }
            break;
        }
    }
    return stk.empty();
}

int main()
{
    char expn[50] = "{()}";
    int value = isBalancedParenthesis(expn);
    printf("\n Given Expn: %s\n", expn);
    printf("\n Result after isParenthesisMatched: %d\n", value);
    return 0;
}
