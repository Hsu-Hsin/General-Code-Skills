#include <cmath>
#include <iostream>
#include <string>

/*
 * Arithmetic priority
 * (1) '()'
 * (2) '+' '-' '*' '/'
 */

int variable[26] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13,
                    14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};

bool isVariable(char ch) { return ('A' <= ch && ch <= 'Z'); }
bool isDigit(char ch) { return ('0' <= ch && ch <= '9'); }
bool isArithmeticOperation(char ch) {
    return (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/');
}
bool isLeftParenthese(char ch) { return (ch == '('); }
bool isRightParenthese(char ch) { return (ch == ')'); }
int getValue(char ch) {
    if (isVariable(ch)) return variable[ch - 'A'];
    if (isDigit(ch)) return ch - '0';
    return -1;
}

int arithmetic(int lhs, char operation, int rhs) {
    switch (operation) {
        case '+':
            return lhs + rhs;
        case '-':
            return lhs - rhs;
        case '*':
            return lhs * rhs;
        case '/':
            // The result of division is rounded upwards.
            return (int)ceil((double)lhs / (double)rhs);

        default:
            break;
    }
    return 0;
}

int calculate(const std::string& str) {
    // str is a substr that can be calculated
    int lhs = 0, rhs = 0;
    int op_pos = 0;

    if (isLeftParenthese(str[0])) {
        int cnt = 0;
        int end_of_substr = 0;
        for (; end_of_substr < str.size(); ++end_of_substr) {
            if (isLeftParenthese(str[end_of_substr])) ++cnt;
            if (isRightParenthese(str[end_of_substr])) --cnt;
            if (cnt == 0) break;
        }
        op_pos = end_of_substr + 1;
        lhs = calculate(str.substr(1, end_of_substr - 1));
    } else if (isVariable(str[0]) || isDigit(str[0])) {
        op_pos = 1;
        lhs = getValue(str[0]);
    } else {
    }

    int end = op_pos + 1;
    while (op_pos < str.size()) {
        if (op_pos >= str.size()) {
            return lhs;
        }

        if (isLeftParenthese(str[end])) {
            int cnt = 0;
            int end_of_substr = end;
            for (; end_of_substr < str.size(); ++end_of_substr) {
                if (isLeftParenthese(str[end_of_substr])) ++cnt;
                if (isRightParenthese(str[end_of_substr])) --cnt;
                if (cnt == 0) break;
            }
            rhs = calculate(str.substr(end + 1, end_of_substr - end - 1));
            end = end_of_substr;
        } else if (isVariable(str[end]) || isDigit(str[end])) {
            rhs = getValue(str[end]);
        } else {
        }
        lhs = arithmetic(lhs, str[op_pos], rhs);
        op_pos = end + 1;
        end = op_pos + 1;
    }

    return lhs;
}

int main() {
    std::string str = "(2*3+(5+5)*((1)+8)+8-8)*(5+8+(S/1))";
    std::cout << calculate(str) << std::endl;
    return 0;
}
