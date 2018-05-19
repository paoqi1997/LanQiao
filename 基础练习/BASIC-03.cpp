/**
 * 基础练习 字母图形
 */

#include <iostream>

using namespace std;

int main()
{
    int n1, n2;

    char m[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    cin >> n1 >> n2;

    for (int i = 0; i < n1; ++i)
    {
        for (int j = 0; j < n2; ++j)
        {
            int k = (i - j >= 0) ? i - j : j - i;

            cout << m[k];
        }
        cout << endl;
    }

    return 0;
}
