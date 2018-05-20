/**
 * 基础练习 Huffuman树
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

    int sum = 0, add = 0;

    /*  2  3  5  8  9
     *  5  5  8  9
     *  8  9 10
     * 10 17
     * 27
     */

    while (n > 1)
    {
        sort(m, m + n);

        add = m[0] + m[1];

        sum += add; m[1] = add;

        for (int i = 0; i < n - 1; ++i)
            m[i] = m[i + 1];

        n -= 1;
    }

    cout << sum << endl;

    return 0;
}
