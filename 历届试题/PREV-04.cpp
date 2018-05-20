/**
 * 历届试题 剪格子
 */

#include <iostream>

using namespace std;

static int n, m, sum = 0;

static int a[10][10], fg[10][10];

static int dx[4] = {0, 1, 0, -1};

static int dy[4] = {1, 0, -1, 0};

int judge(int, int, int);

int dfs(int, int, int);

int main()
{
    cin >> m >> n;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j]; sum += a[i][j];
        }
    }

    /* 和为奇数不可分割 */
    if (sum % 2)
        cout << 0 << endl;
    /* 和为偶数可以分割 */
    else
    {
        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
                fg[i][j] = 0;
        }

        fg[1][1] = 1;

        /* 从左上角开始搜索 */
        cout << dfs(1, 1, a[1][1]) << endl;
    }

    return 0;
}

int judge(int x, int y, int num)
{
    /* 越界 */
    if (x < 1 || y < 1 || x > n || y > m)
        return 0;
    /* 已访问 */
    if (fg[x][y])
        return 0;
    /* 数字和超出一半 */
    if (num + a[x][y] > sum / 2)
        return 0;

    return 1;
}

int dfs(int x, int y, int num)
{
    /* 数字和等于一半 */
    if (num == sum / 2)
        return 1;

    for (int i = 0; i < 4; ++i)
    {
        /* 方向分别往右、往下、往左、往上 */
        int nx = x + dx[i], ny = y + dy[i];

        if (!judge(nx, ny, num))
            continue;

        fg[nx][ny] = 1;

        /* 继续搜索 */
        int ans = dfs(nx, ny, num + a[nx][ny]);

        if (ans)
            return ans + 1;

        fg[nx][ny] = 0;
    }

    return 0;
}
