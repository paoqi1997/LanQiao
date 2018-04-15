/* 基础练习 - 查找整数 */

#include <iostream>

using namespace std;

int main()
{
    int n, t;

    cin >> n;

    int m[n];

    for (int i = 0; i < n; ++i)
        cin >> m[i];

    cin >> t;

    for (int i = 0; i < n; ++i)
    {
        if (m[i] == t)
        {
            cout << i + 1 << endl; return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}
