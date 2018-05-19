/**
 * 基础练习 矩形面积交
 */

#include <iostream>
#include <cstdio>

using namespace std;

inline double min(double x, double y)
{
    return x < y ? x : y;
}

inline double max(double x, double y)
{
    return x > y ? x : y;
}

int main()
{
    /* 第一个矩形 */
    double x1, y1, x2, y2;

    /* 第二个矩形 */
    double x3, y3, x4, y4;

    /* 相交矩形的边界 */
    double m1, m2, n1, n2;

    cin >> x1 >> y1 >> x2 >> y2;

    cin >> x3 >> y3 >> x4 >> y4;

    /* 相交矩形的左边界 */
    m1 = max(min(x1, x2), min(x3, x4));

    /* 相交矩形的右边界 */
    m2 = min(max(x1, x2), max(x3, x4));

    /* 相交矩形的下边界 */
    n1 = max(min(y1, y2), min(y3, y4));

    /* 相交矩形的上边界 */
    n2 = min(max(y1, y2), max(y3, y4));

    if (m2 > m1 && n2 > n1)
        printf("%.2f\n", (m2 - m1) * (n2 - n1));
    else
        printf("0.00\n");

    return 0;
}
