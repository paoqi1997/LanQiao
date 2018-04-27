/* 基础练习 - 高精度加法 */

#include <iostream>
#include <string>

using namespace std;

static int m1[100], m2[100], m3[200];

int main()
{
    string s1, s2;

    cin >> s1 >> s2;

    for (size_t i = 0; i < s1.size(); ++i)
        m1[i] = s1[s1.size() - i - 1] - '0';

    for (size_t i = 0; i < s2.size(); ++i)
        m2[i] = s2[s2.size() - i - 1] - '0';

    size_t len = max(s1.size(), s2.size());

    for (size_t i = 0; i < len; ++i)
        m3[i] = m1[i] + m2[i];

    for (size_t i = 0; i < len; ++i)
    {
        if (m3[i] >= 10)    /* 一般位进行进位 */
        {
            m3[i + 1] += m3[i] / 10;

            m3[i] %= 10;
        }
    }

    if (m3[len] > 0) ++len; /* 最高位进行进位 */

    for (size_t i = 0; i < len; ++i)
        cout << m3[len - i - 1];
    cout << endl;

    return 0;
}
