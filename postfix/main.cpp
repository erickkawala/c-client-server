#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int evaluate_postfix(const string & exp)
{
    istringstream ss(exp);

    string token;
    int left, right;
    stack<int> s;

    while (ss >> token)
    {
        switch(token[0])
        {
        case '+':
            right = s.top();
            s.pop();
            left = s.top();
            s.pop();
            s.push(left + right);
            break;

        case '-':
            right = s.top();
            s.pop();
            left = s.top();
            s.pop();
            s.push(left - right);
            break;

        case '*':
            right = s.top();
            s.pop();
            left = s.top();
            s.pop();
            s.push(left * right);
            break;

        case '/':
            right = s.top();
            s.pop();
            left = s.top();
            s.pop();
            s.push(left / right);
            break;

        case '%':
            right = s.top();
            s.pop();
            left = s.top();
            s.pop();
            s.push(left % right);
            break;


        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            s.push(stoi(token));
            break;


        }
    }

    return s.top();

}

int main(int argc, char *argv[])
{
    string exp;

    cout << "Enter a postfix expression: ";
    getline(cin, exp);
    cout << "Value = " << evaluate_postfix(exp) << endl;
    return 0;
}

