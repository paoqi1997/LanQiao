/**
 * 基础练习 01字串
 */

#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i < 32; ++i)
        cout << (i % 32) / 16 << (i % 16) / 8 << (i % 8) / 4 << (i % 4) / 2 << i % 2 << endl;

    return 0;
}
