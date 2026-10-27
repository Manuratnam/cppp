
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s[100];
    double stack[100];
    int top = -1;

    cout << "Enter postfix expression: ";
    cin.getline(s, 100);

    for(int i = 0; s[i] != '\0'; i++)
    {
        if(s[i] == ' ')
        {
            continue;
        }

        if(s[i] >= '0' && s[i] <= '9')
        {
            double num = 0;

            while(s[i] >= '0' && s[i] <= '9')
            {
                num = num * 10 + (s[i] - '0');
                i++;
            }

            top++;
            stack[top] = num;
            i--;
        }
        else
        {
            double b = stack[top];
            top--;

            double a = stack[top];
            top--;

            double result;

            if(s[i] == '+')
            {
                result = a + b;
            }
            else if(s[i] == '-')
            {
                result = a - b;
            }
            else if(s[i] == '*')
            {
                result = a * b;
            }
            else if(s[i] == '/')
            {
                result = a / b;
            }

            top++;
            stack[top] = result;
        }
    }

    cout << "Result = " << stack[top];

    return 0;
}
