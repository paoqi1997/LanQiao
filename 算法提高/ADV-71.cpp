/**
 * 算法提高 判断回文
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;

    cin >> s;

    bool flag = true;

    for (size_t i = 0; i < s.size() / 2; ++i)
    {
        if (s[i] != s[s.size() - i - 1])
        {
            flag = false; break;
        }
    }

    if (!flag)
        cout << "no!" << endl;
    else
        cout << "yes!" << endl;

    return 0;
}
