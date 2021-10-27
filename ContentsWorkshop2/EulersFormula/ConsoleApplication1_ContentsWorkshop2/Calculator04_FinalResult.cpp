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
        if (s == EState::OP1) {
            if (isdigit(ch)) {
                int number = ch - '0'; // "convert ch to number";
                op1 = op1 * 10 + number;
            }
            else if (IsOperator(ch)) {
                op = ch;
                op2 = 0;
                s = EState::OP2; // state transition
            }
            else if (ch == '=')
            {
                res = op1;
                s = EState::RESULT;
            }
        }
        else if (s == EState::OP2) {
            if (isdigit(ch)) {
                int number = ch - '0';
                op2 = op2 * 10 + number;
            }
            else if (IsOperator(ch)) {
                op1 = Evaluator(op1, op, op2);
                op = ch;
                op2 = 0;
            }
            else if (ch == '=') {
                res = Evaluator(op1, op, op2);
                s = EState::RESULT;
            }
        }
        else if (s == EState::RESULT) {
            if (isdigit(ch)) {
                op1 = 0;
                s = EState::OP1;
            }
            else if (IsOperator(ch)) {
                op = ch;
                op1 = res;
                op2 = 0;
                s = EState::OP2;
            }
        }
        printf("[%i] %i, %c, %i, res=%i\r\n", s, op1, op, op2, res );
    }
}
