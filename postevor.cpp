
#include <iostream>
using namespace std;

const int MAX = 100;

bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

double evalPostfix(const char* s) {
    double st[MAX];  // the stack
    int top = -1;
    int i = 0;

    while (s[i] != '\0') {
        char c = s[i];

        if (c == ' ') {
            i++;
            continue;
        }

        if (isDigit(c)) {
            double val = 0;

            while (isDigit(s[i])) {
                val = val * 10 + (s[i] - '0');
                i++;
            }

            if (top >= MAX - 1) {
                cout << "Stack overflow!" << endl;
                return NULL;
            }

            st[++top] = val;
        }
        else if (c == '+' || c == '-' ||
                 c == '*' || c == '/') {

            if (top < 1) {
                cout << "Too few operands!" << endl;
                return NULL;
            }

            double b = st[top--];  // right operand (popped first)
            double a = st[top--];  // left operand
            double r;

            switch (c) {
                case '+': r = a + b; break;
                case '-': r = a - b; break;
                case '*': r = a * b; break;

                case '/':
                    if (b == 0) {
                        cout << "Division by zero!" << endl;
                        return NULL;
                    }
                    r = a / b;
                    break;
            }

            st[++top] = r;
            i++;
        }
        else {
            cout << "Unknown character in expression!" << endl;
            return NULL;
        }
    }

    if (top != 0) {
        cout << "Incorrect expression!" << endl;
        return NULL;
    }

    return st[0];
}

int main() {
    char s[MAX];

    cout << "Enter postfix expression: ";
    cin.getline(s, MAX);

    cout << "Result: " << evalPostfix(s) << endl;

    return 0;
}
