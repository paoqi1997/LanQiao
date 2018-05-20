/**
 * 历届试题 核桃的数量
 */

#include <iostream>

using namespace std;

/* 最大公约数 */
int gcd(int a, int b)
{
    int t = a % b;

    while (t)
    {
        a = b; b = t; t = a % b;
    }

    return b;
}

/* 最小公倍数 */
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    cout << lcm(lcm(a, b), c) << endl;

    return 0;
}
