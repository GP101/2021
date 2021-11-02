#include <vector>
#include <algorithm>
#include <locale>
#include <iostream>
#include <memory>
#include <stack>

int Evaluate(int token, int nFirst, int nSecond) {
    if (token == '+')
        return nFirst + nSecond;
    else if (token == '-')
        return nFirst - nSecond;
    else if (token == '*')
        return nFirst * nSecond;
    else if (token == '/')
        return nFirst / nSecond;

    return 0;
}

int main() {
    std::string         input = "512+4*+3-";
    std::stack<int>     stack;
    int token = 0;
    bool bIsTokenLeft = true;
    int iNextToken = 0;
    int nErrorCode = 0;

    while (bIsTokenLeft == true) {
        if (iNextToken >= input.length()) {
            nErrorCode = 0;
            bIsTokenLeft = false;
            break;
        }
        token = (char)input[iNextToken];
        iNextToken += 1;

        if (isdigit(token)) {
            const int iTokenValue = token - '0';
            stack.push(iTokenValue);
        }
        else {
            const int iSize = stack.size();
            if (iSize < 2) { // insufficient number of arguments
                nErrorCode = -1;
                break;
            }

            int nFirst = 0;
            int nSecond = 0;
            nSecond = stack.top();
            stack.pop();
            nFirst = stack.top();
            stack.pop();

            // evaluate and push the result
            const int nResult = Evaluate(token, nFirst, nSecond);
            stack.push(nResult);
        }
    }
    // if there is only one left, it is an answer
    if (stack.size() >= 1) {
        std::cout << stack.top() << std::endl;
    }
}
