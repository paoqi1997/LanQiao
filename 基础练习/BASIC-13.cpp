/**
 * 基础练习 数列排序
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int m[n];

    for (int i = 0; i < n; ++i)
        cin >> m[i];

    sort(m, m + n);

    for (int i = 0; i < n; ++i)
        cout << m[i] << ' ';
    cout << endl;

    return 0;
}
