/**
 * 算法训练 区间k大数查询
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int m[n];

    for (int i = 0; i < n; ++i)
        cin >> m[i];

    int t;

    cin >> t;

    int buf[t][3];

    vector<int> vec;

    for (int i = 0; i < t; ++i)
        cin >> buf[i][0] >> buf[i][1] >> buf[i][2];

    for (int i = 0; i < t; ++i)
    {
        /* 将范围内的数放入容器 */
        for (int j = buf[i][0] - 1; j < buf[i][1]; ++j)
            vec.push_back(m[j]);

        sort(vec.begin(), vec.end()); /* 排序 */

        /* 输出相应的数字 */
        cout << vec[vec.size() - buf[i][2]] << endl;

        vec.clear();                  /* 清空容器 */
    }

    return 0;
}
