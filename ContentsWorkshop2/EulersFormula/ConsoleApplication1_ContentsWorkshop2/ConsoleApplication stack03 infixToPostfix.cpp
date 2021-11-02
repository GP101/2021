#include <stdio.h>
#include <ctype.h>
#include <stack>

int precedence(char x);

void infixToPostfix(char* expn, char* output)
{
    std::stack<char> stk;
    char ch, op;
    int i = 0;
    int index = 0;
    int digit = 0;
    while ((ch = expn[i++]) != '\0')
    {
        if (isdigit(ch))
        {
            output[index++] = ch;
            digit = 1;
        }
        else
        {
            if (digit)
            {
                output[index++] = ' ';
                digit = 0;
            }
            switch (ch)
            {
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
                while (!stk.empty() && precedence(ch) <= precedence(stk.top()))
                {
                    op = stk.top();
                    stk.pop();

                    output[index++] = op;
                    output[index++] = ' ';
                }
                stk.push(ch);
                break;
            case '^':
                while (!stk.empty() && precedence(ch) < precedence(stk.top()))
                {
                    op = stk.top();
                    stk.pop();

                    output[index++] = op;
                    output[index++] = ' ';
                }
                stk.push(ch);
                break;
            case '(':
                stk.push(ch);
                break;
            case ')':
                {
                    op = stk.top();
                    stk.pop();
                    while (!stk.empty() && op != '(')
                    {
                        output[index++] = op;
                        output[index++] = ' ';
                        op = stk.top();
                        stk.pop();
                    }
                }
                break;
            }
        }
    }
    while (!stk.empty())
    {
        op = stk.top();
        stk.pop();
        output[index++] = op;
        output[index++] = ' ';
    }
    output[index++] = '\0';
}

int precedence(char x)
{
    if (x == '(')
        return(0);
    if (x == '+' || x == '-')
        return(1);
    if (x == '*' || x == '/' || x == '%')
        return(2);
    if (x == '^')
        return(3);
    return(4);
}

int main()
{
    //char expn[50] = "10 + ((3)) * 5 / (16 - 4)";
    //char expn[50] = "3-4+5"; // 3 4 - 5 +
    char expn[50] = "3+4*2/(1-5)^2^3"; // 
    
    printf("\n Given Expn: %s\n", expn);
    char output[50];
    infixToPostfix(expn,output);
    printf("\n output: %s\n", output);

    //char expn2[50] = "(5*3)^(4-2)";
    //printf("\n Given Expn: %s\n", expn2);
    //infixToPostfix(expn2, output);
    //printf("\n output: %s\n", output);
    return 0;
}