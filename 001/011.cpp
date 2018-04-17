/* 基础练习 - 十六进制转十进制 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    unsigned int n = 0;

    string s; cin >> s;

    for (size_t i = 0; s[i] != '\0'; ++i)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            int tm = 1;

            for (size_t j = 0; j < s.size() - i - 1; ++j)
                tm *= 16;

            n += (s[i] - '0') * tm;
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            int tm = 1;

            for (size_t j = 0; j < s.size() - i - 1; ++j)
                tm *= 16;

            n += (s[i] - 'A' + 10) * tm;
        }
    } cout << n << endl;

    return 0;
}
