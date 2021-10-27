#include <stdio.h>
#include <conio.h>
#include <ctype.h>

enum class EState
{
    OP1 = 1,
    OP2,
    RESULT
};

EState s = EState::OP1;
int op1 = 0;
int op2 = 0;
int res = 0;
int op = 0;

bool IsOperator(int ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int Evaluator(int op1, int op, int op2)
{
    int result = 0;
    if (op == '+')
        result = op1 + op2;
    else if (op == '-')
        result = op1 - op2;
    else if (op == '*')
        result = op1 * op2;
    else if (op == '/')
        result = op1 / op2;
    return result;
}

void main()
{
    int ch = 0;
    while (ch != 27) {
        ch = _getch();
        printf("[%i] %i, %c, %i, res=%i\r\n", s, op1, op, op2, res );
    }
}
