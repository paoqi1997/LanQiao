/**
 * 基础练习 杨辉三角形
 */

#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int m[n][n];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (j == 0 || j == i)
                m[i][j] = 1;
            else
                m[i][j] = m[i - 1][j - 1] + m[i - 1][j];

            cout << m[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
