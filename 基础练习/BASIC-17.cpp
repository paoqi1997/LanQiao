/**
 * 基础练习 矩阵乘法
 */

#include <iostream>

using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    int m1[n][n], m2[n][n], m3[n][n];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> m1[i][j];
    }

      /* 结果为单位矩阵 */
    if (m == 0)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (i == j)
                    m3[i][j] = 1;
                else
                    m3[i][j] = 0;
            }
        }
    } /* 结果为输入矩阵 */
    else if (m == 1)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                m3[i][j] = m1[i][j];
        }
    } /* 计算 */
    else
    {
        /* 置零 */
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                m2[i][j] = 0;
        }

        /* 准备进行第一次相乘 */
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
                m3[i][j] = m1[i][j];
        }

        while (m-- > 1)
        {
            /* 矩阵相乘 */
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    for (int k = 0; k < n; ++k)
                        m2[i][j] += m3[i][k] * m1[k][j];
                }
            }

            /* 传递暂存矩阵的值 */
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                    m3[i][j] = m2[i][j];
            }

            /* 再度置零 */
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                    m2[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << m3[i][j] << ' ';
        cout << endl;
    }

    return 0;
}
