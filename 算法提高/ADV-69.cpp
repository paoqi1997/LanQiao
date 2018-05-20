/**
 * 算法提高 质因数
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<int> vec;

    /* 收集质数 */
    for (int i = 2; i <= n; ++i)
    {
        int j = 2;

        for ( ; j <= i; ++j)
        {
            if (i % j == 0) break;
        }

        if (j == i) vec.push_back(i);
    }

    cout << n << '=';

    /* 收集目标整数的因数 */
    for (size_t i = 0; i < vec.size(); ++i)
    {
        while ((n % vec[i] == 0) && (n != vec[i]))
        {
            cout << vec[i] << '*'; n /= vec[i];
        }

        if (n == vec[i])
        {
            cout << vec[i] << endl; break;
        }
    }

    return 0;
}
