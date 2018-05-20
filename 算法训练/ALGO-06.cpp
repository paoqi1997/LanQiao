/**
 * 算法训练 安慰奶牛
 */

#include <iostream>
#include <algorithm>

#define NMAX 100000
#define IMAX 999999

using namespace std;

struct Edge
{
    int ps;             /* 此端牧场 */
    int pe;             /* 彼端牧场 */
    int value;          /* 道路长度 */
};

static  int    c[NMAX]; /* 第i个牧场和奶牛交谈的时间 */

static  int   fa[NMAX]; /* 第i个牧场和第fa[i]个牧场已建立连接 */

static Edge edge[NMAX]; /* 边集 */

bool comp(Edge x, Edge y)
{
    return x.value < y.value;
}

int find(int x)
{
    if (fa[x] == x)
        return x;
    else
        return (fa[x] = find(fa[x]));
}

int main()
{
    int n, p;

    cin >> n >> p;

    int s, e, l;

    int sum = 0, mt = IMAX;

    for (int i = 1; i <= n; ++i)
    {
        cin >> c[i];

        mt = min(mt, c[i]); /* 晚上回来还要和出发牧场的奶牛交谈一次 */

        fa[i] = i;
    }

    for (int i = 1; i <= p; ++i)
    {
        cin >> s >> e >> l;

        edge[i].ps = s; edge[i].pe = e;

        edge[i].value = l * 2 + c[s] + c[e]; /* 走完双向道路l的时间 + 在牧场s花费的时间 + 在牧场e花费的时间 */
    }

    sort(edge + 1, edge + p + 1, comp);      /* 预先处理花费时间少的道路 */

    for (int i = 1; i <= p; ++i)
    {
        int fx = find(edge[i].ps); /* 若牧场ps已纳入体系则跳转至下一个牧场 */

        int fy = find(edge[i].pe); /* 若牧场pe已纳入体系则跳转至下一个牧场 */

        if (fx != fy)
        {
            sum += edge[i].value; fa[fx] = fy;
        }
    }

    cout << sum + mt << endl;

    return 0;
}
