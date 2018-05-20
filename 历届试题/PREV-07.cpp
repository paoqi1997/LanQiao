/**
 * 历届试题 连号区间数
 */

#include <iostream>
#include <vector>

using namespace std;

static int cnt = 0;

int main()
{
    int n, t;

    cin >> n;

    vector<int> vec;

    for (int i = 0; i < n; ++i)
    {
        cin >> t;

        vec.push_back(t);
    }

    for (int i = 0; i < n; ++i)     /* 枚举左区间 */
    {
        int l = 66666, r = 0;

        for (int j = i; j < n; ++j) /* 枚举右区间 */
        {
            l = min(l, vec[j]);     /* 更新最小数 */

            r = max(r, vec[j]);     /* 更新最大数 */

            if (r - l == j - i)     /* 可构成连号区间 */
                ++cnt;
        }
    }

    cout << cnt << endl;

    return 0;
}
