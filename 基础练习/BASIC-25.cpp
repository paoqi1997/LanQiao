/**
 * 基础练习 回形取数
 */

#include <iostream>

using namespace std;

int main()
{
    int m, n;

    cin >> m >> n;

    int s[m][n];

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> s[i][j];
    }

    for (int i = 0; i < (m + 1) / 2 && i < (n + 1) / 2; ++i)
    {
        for (int j = i; j < m - i; ++j)     /* 左方 */
            cout << s[j][i] << ' ';

        for (int j = i + 1; j < n - i; ++j) /* 下方 */
            cout << s[m - i - 1][j] << ' ';

        if (i < n - i - 1) /* 边界检测 */
        {
            for (int j = m - i - 2; j >= i; --j)     /* 右方 */
                cout << s[j][n - i - 1] << ' ';
        }

        if (i < m - i - 1) /* 边界检测 */
        {
            for (int j = n - i - 2; j >= i + 1; --j) /* 上方 */
                cout << s[i][j] << ' ';
        }
    } cout << endl;

    return 0;
}
