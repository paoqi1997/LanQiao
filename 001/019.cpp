/* 基础练习 - 完美的代价 */

#include <iostream>
#include <string>

using namespace std;

int getnum(string, char);

int main()
{
    char c; string s;

    int len, cnt = 0, buf[26] = {0};

    cin >> len >> s;

    /* 计算各个字母出现的次数 */
    for (size_t i = 0; i < s.size(); ++i)
    {
        ++buf[s[i] - 'a'];
    }

    /* 记录出现次数为奇数的字母 */
    for (size_t i = 0; i < 26; ++i)
    {
        if (buf[i] % 2 != 0)
        {
            ++cnt; c = 'a' + i;
        }
    }

    /* 不为回文串 */
    if (cnt > 1)
        cout << "Impossible" << endl;
    else
        cout << getnum(s, c) << endl;

    return 0;
}

int getnum(string s, char c)
{
    size_t i, j, k; int count = 0;

    /* 扫描范围由字符串两端向中间靠拢 */
    for (i = 0; i < s.size() / 2; ++i)
    {
        if (s[i] == c) /* 在左边发现多余的字符 */
        {
            for (j = i; j < s.size() - i - 1; ++j) /* 寻找与s[s.size() - i - 1]匹配的字符 */
            {
                if (s[j] == s[s.size() - i - 1])
                    break;
            }

            count += j - i;                        /* 确定交换次数 */

            for (k = j; k > i; --k)                /* 向左遍历，向右交换 */
                s[k] = s[k - 1];

            s[i] = s[s.size() - i - 1];            /* 传递s[s.size() - i - 1] */
        }
        else
        {
            for (j = s.size() - i - 1; j > i; --j) /* 寻找与s[i]匹配的字符 */
            {
                if (s[j] == s[i])
                    break;
            }

            count += (s.size() - i - 1) - j;       /* 确定交换次数 */

            for (k = j; k < s.size() - i - 1; ++k) /* 向右遍历，向左交换 */
                s[k] = s[k + 1];

            s[s.size() - i - 1] = s[i];            /* 传递s[i] */
        }
    } return count;
}
