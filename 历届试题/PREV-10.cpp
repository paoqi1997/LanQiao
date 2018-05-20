/**
 * 历届试题 幸运数
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int m, n;

    cin >> m >> n;

    vector<int> vec;

    for (int i = 0; i < n; ++i)
        vec.push_back(i + 1);

    /*     l为幸运数
     *   sum为幸运数的数目
     *  left为搜寻范围的左区间
     * right为搜寻范围的右区间
     */

    int l = 1, sum = 0, left = 0, right = n;

    while (l < n)
    {
        /* 标记不合规定的数字 */
        for (int i = left; i < right; ++i)
        {
            if (l == 1) {
                if ((i + 1) % 2 == 0) vec[i] = -1;
            } else {
                if ((i + 1) % l == 0) vec[i] = -1;
            }
        }

        /* 删去不合规定的数字 */
        for (int i = left; i < right; ++i)
        {
            if (vec[i] == -1)
            {
                vec.erase(vec.begin() + i); --right;
            }
        }

        l = vec[++left]; /* 获取下一个幸运数 */
    }

    /* 统计幸运数的数目 */
    for (int i = 0; i < right; ++i)
    {
        if (vec[i] > m && vec[i] < n) ++sum;
    }

    cout << sum << endl;

    return 0;
}
