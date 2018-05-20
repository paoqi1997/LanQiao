/**
 * 算法训练 摆动序列
 */

#include <iostream>

using namespace std;

/* 求阶乘 */
int fac(int i)
{
    if (i == 0 || i == 1)
        return 1;
    else
        return i * fac(i - 1);
}

/* 求组合数 */
int combine(int i, int k)
{
    long long s = 1;

    if (i > k / 2)
        i = k - i;

    for (int j = 0; j < i; ++j)
        s *= k - j;

    return s / fac(i);
}

int main()
{
    int k, sum = 0;

    cin >> k;                    /* 所有数字都不大于k */

    for (int i = 2; i <= k; ++i) /* i表示序列中数字的个数 */
        sum += combine(i, k);

    cout << sum * 2 << endl;     /* 对于C(i, k)来说，只有两种排列 */

    return 0;                    /* 只要第一个数字和第二个数字确定，排列也就确定 */
}
