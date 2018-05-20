/**
 * 算法训练 K好数
 */

#include <iostream>

using namespace std;

static int cnt = 0;

static int mod = 1000000007;

int main()
{
    int k, l;

    cin >> k >> l; /* K进制下的L位数 */

    int m[l][k];   /* m[i][j]表示第i + 1位放置数字j时K好数的数目 */

    for (int i = 0; i < l; ++i)
    {
        for (int j = 0; j < k; ++j)           /* 置零 */
            m[i][j] = 0;
    }

    for (int i = 0; i < k; ++i)               /* 前置工作 */
        m[0][i] = 1;

    for (int i = 1; i < l; ++i)               /* 数位为第i + 1位 */
    {
        for (int j = 0; j < k; ++j)           /* 这一位可能的数字 */
        {
            for (int r = 0; r < k; ++r)       /* 上一位可能的数字 */
            {
                if (r != j - 1 && r != j + 1) /* 符合要求 */
                {
                    m[i][j] += m[i - 1][r];

                    m[i][j] %= mod;
                }
            }
        }
    }

    for (int i = 1; i < k; ++i)               /* 直接计算数位为第L位时K好数的数目 */
    {
        cnt += m[l - 1][i];

        cnt %= mod;
    }

    cout << cnt << endl;

    return 0;
}
