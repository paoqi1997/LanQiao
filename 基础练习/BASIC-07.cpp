/**
 * 基础练习 特殊的数字
 */

#include <iostream>

using namespace std;

int main()
{
    int x0, x1, x2;

    for (int i = 100; i <= 999; ++i)
    {
        x2 = i / 100;

        x1 = (i - (x2 * 100)) / 10;

        x0 = (i - (x2 * 100) - (x1 * 10));

        if ((x2 * x2 * x2 + x1 * x1 * x1 + x0 * x0 * x0) == i)
            cout << i << endl;
    }

    return 0;
}
