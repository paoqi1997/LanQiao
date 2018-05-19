/**
 * 基础练习 时间转换
 */

#include <iostream>

using namespace std;

int main()
{
    int h, m, s;

    cin >> s;

    if (s >= 0)
    {
        if (s >= 3600)
        {
            h = s / 3600; s -= h * 3600;

            if (s >= 60)
            {
                m = s / 60; s -= m * 60;
            }
            else
                m = 0;
        }
        else
        {
            h = 0;

            if (s >= 60)
            {
                m = s / 60; s -= m * 60;
            }
            else
                m = 0;
        }
    } cout << h << ':' << m << ':' << s << endl;

    return 0;
}
