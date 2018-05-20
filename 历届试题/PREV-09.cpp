/**
 * 历届试题 大臣的旅费
 */

#include <iostream>
#include <vector>

#define NMAX 10000
#define IMAX 99999

using namespace std;

struct Edge
{
    int from;  /* 出发节点 */
    int to;    /* 到达节点 */
    int value; /* 道路长度 */

    Edge(int f, int t, int v)
        : from(f), to(t), value(v) {}
};

static vector<Edge> edge[NMAX]; /* 边集 */

static int visit[NMAX];

static int point;

static int ans = -1, dist = -1; /* 总路费和总路程 */

void dfs(int, int, int);

int main()
{
    int n;

    cin >> n;

    int fr, to, value;

    /* 构造道路 */
    for (int i = 1; i <= n - 1; ++i)
    {
        cin >> fr >> to >> value;

        edge[fr].push_back(Edge(fr, to, value));

        edge[to].push_back(Edge(to, fr, value));
    }

    /* 首次出发 */
    dfs(1, 0, n);

    dist = -1;

    /* 重置 */
    for (int i = 0; i < NMAX; ++i)
        visit[i] = 0;

    /* 再度出发 */
    dfs(point, 0, n);

    ans = dist;                           /* 获取总路程 */

    ans = ans * 10 + ans * (ans + 1) / 2; /* 计算总路费 */

    cout << ans << endl;

    return 0;
}

void dfs(int currNode, int currDist, int n)
{
    if (currNode > n)    /* 超出城市数 */
        return;

    if (currDist > dist) /* 发现距离最长的道路 */
    {
        dist = currDist; point = currNode;
    }

    /* 标记为已访问 */
    visit[currNode] = 1;

    /* 大臣继续前进 */
    for (size_t i = 0; i < edge[currNode].size(); ++i)
    {
        int nextNode = edge[currNode][i].to;

        if (visit[nextNode] == 0)
        {
            dfs(nextNode, currDist + edge[currNode][i].value, n);
        }
    }
}
