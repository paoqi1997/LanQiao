/**
 * 基础练习 分解质因数
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n1, n2;

    cin >> n1 >> n2;

    vector<int> vec;

    /* 收集质数 */
    for (int i = 2; i <= 10000; ++i)
    {
        int j = 2;

        for ( ; j <= i; ++j)
        {
            if (i % j == 0) break;
        }

        if (j == i) vec.push_back(i);
    }

    /* 收集目标整数的因数 */
    for ( ; n1 <= n2; ++n1)
    {
        int t = n1;

        cout << t << '=';

        for (size_t j = 0; j < vec.size(); ++j)
        {
            while ((t % vec[j] == 0) && (t != vec[j]))
            {
                cout << vec[j] << '*'; t /= vec[j];
            }

            if (t == vec[j])
            {
                cout << vec[j] << endl; break;
            }
        }
    }

    return 0;
}
