/**
 * 基础练习 龟兔赛跑预测
 */

#include <iostream>

using namespace std;

int main()
{
    int v1, v2, t, s, l;

    cin >> v1 >> v2 >> t >> s >> l;

    int m1[l], m2[l];

    int rt = 0, wt = 0;

    do
    {
        if (wt == 0)
        {
            m1[wt] = v1; m2[wt] = v2;

            ++wt;
        }
        else
        {     /* 兔子在休息 */
            if (rt > 0)
            {
                m1[wt] = m1[wt - 1];

                m2[wt] = m2[wt - 1] + v2;

                ++wt; --rt;
            } /* 兔子在奔跑 */
            else
            {
                m1[wt] = m1[wt - 1] + v1;

                m2[wt] = m2[wt - 1] + v2;

                ++wt;
            }
        } /* 兔子判断自己是否需要休息 */
        if (rt == 0 && m1[wt - 1] - m2[wt - 1] >= t)
        {
            rt = s;
        }
    } while (m1[wt - 1] < l && m2[wt - 1] < l);

    /* 打印比赛结果 */
    if (m1[wt - 1] >= l && m2[wt - 1] < l)
    {
        cout << 'R' << endl << wt << endl;
    }
    else if (m1[wt - 1] < l && m2[wt - 1] >= l)
    {
        cout << 'T' << endl << wt << endl;
    }
    else if (m1[wt - 1] == l && m2[wt - 1] == l)
    {
        cout << 'D' << endl << wt << endl;
    }

    return 0;
}
