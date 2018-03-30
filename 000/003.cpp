/* 入门训练 - 圆的面积 */

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    double r;

    double pi = atan(1.0) * 4;

    cin >> r;

    printf("%.7f\n", pi * r * r);

    return 0;
}
