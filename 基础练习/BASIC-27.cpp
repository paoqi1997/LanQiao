/**
 * 基础练习 2n皇后问题
 */

#include <iostream>

using namespace std;

void search(int, int, int, int[8][8]);

bool judge(int, int, int, int, int[8][8]);

static int cnt = 0;

static int black = 2, white = 3;

int main()
{
    int n;

    cin >> n;

    int board[8][8];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];
    }

    search(0, 0, n, board); cout << cnt << endl;

    return 0;
}

void search(int i, int flag, int n, int board[8][8])
{
    if (i >= n)
    {
          /* 黑皇后放置完毕 */
        if (flag == 0)
        {
            i = 0; flag = 1;
        } /* 白皇后放置完毕 */
        else
        {
            ++cnt; return;
        }
    }
      /* 正在放置黑皇后 */
    if (flag == 0)
    {
        for (int j = 0; j < n; ++j)
        {
            if (judge(i, j, black, n, board) && board[i][j] == 1)
            {
                board[i][j] = black;

                search(i + 1, flag, n, board);

                board[i][j] = 1;
            }
        }
    } /* 正在放置白皇后 */
    else
    {
        for (int j = 0; j < n; ++j)
        {
            if (judge(i, j, white, n, board) && board[i][j] == 1)
            {
                board[i][j] = white;

                search(i + 1, flag, n, board);

                board[i][j] = 1;
            }
        }
    }
}

bool judge(int i, int j, int color, int n, int board[8][8])
{
    int r, c;

    for (r = 0; r < n; ++r) /* 上方及下方 */
    {
        if (board[r][j] == color) return false;
    }

    for (c = 0; c < n; ++c) /* 左方及右方 */
    {
        if (board[i][c] == color) return false;
    }

    for (r = i - 1, c = j - 1; r >= 0 && c >= 0; --r, --c)
    {
        if (board[r][c] == color) return false; /* 左上方 */
    }

    for (r = i + 1, c = j + 1; r < n && c < n; ++r, ++c)
    {
        if (board[r][c] == color) return false; /* 右下方 */
    }

    for (r = i - 1, c = j + 1; r >= 0 && c < n; --r, ++c)
    {
        if (board[r][c] == color) return false; /* 右上方 */
    }

    for (r = i + 1, c = j - 1; r < n && c >= 0; ++r, --c)
    {
        if (board[r][c] == color) return false; /* 左下方 */
    }

    return true;
}
