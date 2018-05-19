/**
 * 基础练习 数列特征
 */

#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int m[n];

    for (int i = 0; i < n; ++i)
        cin >> m[i];

    int min = m[0], max = m[0], sum = 0;

    for (int i = 0; i < n; ++i)
    {
        sum += m[i];

        if (min > m[i]) min = m[i];

        if (max < m[i]) max = m[i];
    }

    cout << max << endl << min << endl << sum << endl;

    return 0;
}
