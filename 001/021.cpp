/* 基础练习 - Sine之舞 */

#include <iostream>

using namespace std;

void An(int);

void Sn(int);

int main()
{
    int n;

    cin >> n;

    Sn(n);

    return 0;
}

void An(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
            cout << "sin(" << i;
        else
        {
            if (i % 2 == 0)
                cout << '-';
            else
                cout << '+';

            cout << "sin(" << i;
        }
    }

    while (n-- >= 1) cout << ')';
}

void Sn(int n)
{
    int j = n;

    while (j-- > 1)
        cout << '(';

    for (int i = 1; i <= n; ++i)
    {
        if (i == 1)
            An(i);
        else
        {
            cout << '+' << n - i + 2 << ')';

            An(i);
        }
    } cout << '+' << 1 << endl;
}
