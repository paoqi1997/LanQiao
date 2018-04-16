/* 基础练习 - 十进制转十六进制 */

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char hex[16];

    int dec, i = 0;

    cin >> dec;

    while (dec)
    {
        int t = dec % 16;

        if (t <= 9)
            hex[i++] = '0' + t;
        else
            hex[i++] = 'A' + t - 10;

        dec /= 16;
    }

    hex[i] = '\0';

    if (hex[0] == '\0')
        cout << 0 << endl;
    else
        cout << strrev(hex) << endl;

    return 0;
}
