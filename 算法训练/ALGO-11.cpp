/**
 * 算法训练 瓷砖铺放
 */

#include <iostream>

using namespace std;

static int sum = 0;

void getsum(int, int);

int main()
{
    int n;

    cin >> n;

    getsum(0, n);

    cout << sum << endl;

    return 0;
}

void getsum(int l, int n)
{
    if (l == n)
    {
        ++sum; return;
    }
    if (l + 1 <= n)
    {
        getsum(l + 1, n);
    }
    if (l + 2 <= n)
    {
        getsum(l + 2, n);
    }
}
