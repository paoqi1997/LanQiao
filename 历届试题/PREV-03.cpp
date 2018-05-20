/**
 * 历届试题 带分数
 */

#include <iostream>

using namespace std;

static int cnt = 0;

/* 获取单个数值的位数 */
int check_one_digit(int);

/* 获取三个数值的总位数 */
int check_all_digit(int, int, int);

/* 获取九个数字的选取次数 */
void test(int, int[]);

/* 处理函数 */
void process(int, int);

int main()
{
    int n;

    cin >> n;

    for (int i = 1; i < n; ++i)
    {
        int x1 = i, x2 = n - i;

        process(x1, x2);
    }

    cout << cnt << endl;

    return 0;
}

int check_one_digit(int x)
{
    int num = 0;

    while (x != 0)
    {
        ++num; x /= 10;
    }

    return num;
}

int check_all_digit(int a, int b, int c)
{
    return check_one_digit(a) +
           check_one_digit(b) + check_one_digit(c);
}

void test(int x, int flag[])
{
    while (x != 0)
    {
        int y = x % 10;

        ++flag[y]; x /= 10;
    }
}

void process(int x, int y)
{
    int i, flag[10];

    int a = x, b = y, c = 1;

    for ( ; check_all_digit(a, b, c) < 10; b += y, c += 1)
    {
        for (i = 0; i < 10; ++i)
            flag[i] = 0;

        test(a, flag); test(b, flag); test(c, flag);

        for (i = 1; i < 10 && flag[0] == 0; ++i)
        {
            if (flag[i] != 1) break;
        }

        if (i == 10) ++cnt;
    }
}
