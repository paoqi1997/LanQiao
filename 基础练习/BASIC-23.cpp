/**
 * 基础练习 芯片测试
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
        for (int j = 0; j < n; ++j)
            cin >> m[i][j];
    }

    for (int j = 0; j < n; ++j)
    {
        int cnt = 0;

        /* 1/2为实际概率的中间值 */
        for (int i = 0; i < n; ++i)
            cnt += m[i][j];

        /* 若大于1/2则为好芯片 */
        if (cnt > n / 2)
        {
            cout << j + 1 << ' ';
        }
    } cout << endl;

    return 0;
}
