/**
 * 算法提高 冒泡法排序
 */

#include <iostream>

using namespace std;

int main()
{
    int m[10];

    for (int i = 0; i < 10; ++i)
        cin >> m[i];

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9 - i; ++j)
        {
            if (m[j] > m[j + 1]) swap(m[j], m[j + 1]);
        }
    }

    for (int i = 0; i < 10; ++i)
        cout << m[i] << ' ';
    cout << endl;

    return 0;
}
