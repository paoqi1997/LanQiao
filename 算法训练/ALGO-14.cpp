/**
 * 算法训练 回文数
 */

#include <iostream>
#include <string>

using namespace std;

/* 是否为回文数 */
bool is_palindrome(int[], int);

/* 准备进行下一次高精度计算 */
void set_value(int[], int, int[], int[]);

int main()
{
    int n, cnt, len;

    int a[30], b[30], c[30];

    string s;

    cin >> n >> s;

    cnt = 0, len = s.size();

    /* 初始化 */
    for (int i = 0; i < len; ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
            c[i] = s[i] - '0';
        else
            c[i] = s[i] - 'A' + 10;

        a[i] = b[len - i - 1] = c[i];
    }

    while (!is_palindrome(c, len) && cnt++ <= 30)
    {
        /* 置零 */
        for (int i = 0; i < 30; ++i)
            c[i] = 0;

        /* 高精度计算 */
        for (int i = 0; i < len; ++i)
        {
            c[i] += a[i] + b[i];

            c[i + 1] += c[i] / n;

            c[i] %= n;
        }

        if (c[len] != 0) ++len;

        set_value(c, len, a, b);
    }

    /* 输出结果 */
    if (cnt <= 30)
        cout << "STEP" << "=" << cnt << endl;
    else
        cout << "Impossible!" << endl;

    return 0;
}

bool is_palindrome(int m[], int len)
{
    for (int i = 0; i < len / 2; ++i)
    {
        if (m[i] != m[len - i - 1])
        {
            return false;
        }
    } return true;
}

void set_value(int c[], int len, int a[], int b[])
{
    for (int i = 0; i < len; ++i)
    {
        a[i] = b[len - i - 1] = c[i];
    }
}
