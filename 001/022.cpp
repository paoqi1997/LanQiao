/* 基础练习 - FJ的字符串 */

#include <iostream>

using namespace std;

void An(int);

static char s[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
    int n;

    cin >> n;

    An(n);

    cout << endl;

    return 0;
}

void An(int n)
{
    if (n == 1)
        cout << s[n - 1];
    else
    {
        An(n - 1);

        cout << s[n - 1];

        An(n - 1);
    }
}
