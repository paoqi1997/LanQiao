/**
 * 入门训练 Fibonacci数列
 */

#include <iostream>

using namespace std;

int main()
{
    int n, f1 = 1, f2 = 1, f3;

    cin >> n;

    if (n == 1)
        cout << f1 << endl;
    else if (n == 2)
        cout << f2 << endl;
    else
    {
        for (int i = 3; i <= n; ++i)
        {
            f3 = (f1 + f2) % 10007;

            f1 = f2; f2 = f3;
        }
        cout << f3 << endl;
    }

    return 0;
}
