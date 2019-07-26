#include <iostream>
#include <stack>


// input: a positive integer n
// output: the digits of n separated by spaces
// eg:  314159 -> 3 1 4 1 5 9

using namespace std;

typedef std::size_t digit;

int main(int argc, char *argv[])
{

    stack<digit> s;
    std::size_t n;
    cout << "Enter n: ";
    cin >> n;


    while (n > 0)
    {
        s.push(n%10);
        n /= 10;
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;
    return 0;

}

