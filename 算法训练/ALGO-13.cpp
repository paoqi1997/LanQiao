/**
 * 算法训练 拦截导弹
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int n, dmax = -1;

    vector<int> dp, vec;

    /* 获取导弹依次飞来的高度 */
    do
    {
        cin >> n;

        vec.push_back(n);
    }
    while (getchar() != '\n');

    /* 初始化 */
    for (size_t i = 0; i < vec.size(); ++i)
        dp.push_back(1);

    /* dp[i]表示飞行高度高于第i + 1枚导弹的其他导弹的数量 */
    for (size_t i = 1; i < vec.size(); ++i)
    {
        /* 接上一条，除此之外还要算上第i + 1枚导弹 */
        for (size_t j = 0; j < i; ++j)
        {
            if (vec[j] >= vec[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (dp[i] > dmax) dmax = dp[i];
    }

    cout << dmax << endl;

    int sys = 0;

    vector< vector<int> > svec;

    /* 初始化 */
    for (size_t i = 0; i < vec.size(); ++i)
        svec.push_back(vector<int>());

    for (size_t i = 0; i < vec.size(); ++i)
    {
        int cnt = 0, smax = 66666;

        for (int j = 1; j <= sys; ++j)
        {
            /* 第j个系统成功拦截vec[i] */
            if (svec[j].back() >= vec[i] && svec[j].back() < smax)
            {
                cnt = j; smax = svec[j].back();
            }
        }

          /* 第sys个系统负责拦截vec[i] */
        if (cnt == 0)
        {
            ++sys;

            svec[sys].push_back(vec[i]);
        } /* 第cnt个系统负责拦截vec[i] */
        else
            svec[cnt].push_back(vec[i]);
    }

    cout << sys << endl;

    return 0;
}
