/**
 * 算法训练 最短路
 */

#include <iostream>

#define DMAX  20000
#define EMAX 200000
#define IMAX 999999

using namespace std;

struct Edge
{
    int from;           /* 出发节点 */
    int to;             /* 到达节点 */
    int value;          /* 边的长度 */
};

static  int dist[DMAX]; /* 一号节点到其他节点的最短距离 */

static Edge edge[EMAX]; /* 边集 */

bool bellman(int, int);

int main()
{
    int n, m;

    int from, to, value;

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        cin >> from >> to >> value;

        --from; --to; /* 节点从零开始计入 */

        edge[i].from = from;

        edge[i].to = to; edge[i].value = value;
    }

    bellman(n, m);

    /* 打印最短距离 */
    for (int i = 1; i < n; ++i)
        cout << dist[i] << endl;

    return 0;
}

bool bellman(int n, int m)
{
    /* 初始化 */
    for (int i = 0; i < DMAX; ++i)
    {
        if (i == 0)
            dist[i] = 0;
        else
            dist[i] = IMAX;
    }

    int i = 0;

    for ( ; ; )
    {
        bool flag = false;

        for (int j = 0; j < m; ++j)
        {
            Edge t = edge[j];

            if (dist[t.from] != IMAX && dist[t.to] > dist[t.from] + t.value)
            {
                dist[t.to] = dist[t.from] + t.value; flag = true;
            }
        }

        if (!flag)       /* 计算完毕 */
            return true;
        if (++i == n)    /* 存在负环 */
            return false;
    }
}
