/**
 * 基础练习 回文数
 */

#include <iostream>

using namespace std;

int main()
{
    int x0, x1, x2, x3;

    for (int i = 1000; i <= 9999; ++i)
    {
        x3 = i / 1000;

        x2 = (i - (x3 * 1000)) / 100;

        x1 = (i - (x3 * 1000) - (x2 * 100)) / 10;

        x0 = (i - (x3 * 1000) - (x2 * 100) - (x1 * 10));

        if (x0 == x3 && x1 == x2)
            cout << i << endl;
    }

    return 0;
}
