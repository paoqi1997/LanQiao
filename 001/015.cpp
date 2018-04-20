/* 基础练习 - 字符串对比 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int flag = 1;

    string s1, s2;

    cin >> s1 >> s2;

    if (s1.size() == s2.size())
    {
        for (size_t i = 0; i < s1.size(); ++i)
        {
            if (s1[i] == s2[i])
            {
                if (flag == 3)
                    continue;
                else
                    flag = 2;
            }
            else
            {
                if (s1[i] == s2[i] + 32 || s1[i] + 32 == s2[i])
                    flag = 3;
                else {
                    flag = 4; break;
                }
            }
        }
    } cout << flag << endl;

    return 0;
}
