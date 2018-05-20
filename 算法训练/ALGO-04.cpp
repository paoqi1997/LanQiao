/**
 * 算法训练 结点选择
 */

#include <iostream>
#include <vector>

using namespace std;

void dfs(int, int);

static int dp[100001][2];         /* dp[i][0]表示不选择第i个节点时的最大权值，dp[i][1]表示选择第i个节点时的最大权值 */

static vector< vector<int> > vec; /* 表示边集 */

int main()
{
    int n, from, to;

    cin >> n;

    for (int i = 1; i <= n; ++i)     /* 将所有节点的权值置为0 */
        cin >> dp[i][1];

    vec.resize(n + 1);

    for (int i = 1; i <= n - 1; ++i) /* 构造边集 */
    {
        cin >> from >> to;

        vec[from].push_back(to); vec[to].push_back(from);
    }

    dfs(0, 1);                               /* 从一号节点开始向下动态规划 */

    cout << max(dp[1][0], dp[1][1]) << endl; /* 从几号节点开始向下动态规划就找几号的状态 */

    return 0;
}

void dfs(int preNode, int currNode)
{
    for (size_t i = 0; i < vec[currNode].size(); ++i)
    {
        int tNode = vec[currNode][i]; /* 节点tNode为节点currNode所连接的下一个节点 */

        if (tNode != preNode)         /* 因为边是双向的，所以要防止重复访问 */
        {
            dfs(currNode, tNode);     /* 继续向下搜索 */

            /* 若不选择节点currNode，则节点tNode可选可不选 */
            dp[currNode][0] += max(dp[tNode][0], dp[tNode][1]);

            /* 若选择节点currNode，则节点tNode不可选 */
            dp[currNode][1] += dp[tNode][0];
        }
    }
}
