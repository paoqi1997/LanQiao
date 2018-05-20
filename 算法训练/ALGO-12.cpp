/**
 * 算法训练 幂方分解
 */

#include <iostream>

using namespace std;

void power(int);

int main()
{
    int n;

    cin >> n;

    power(n);

    cout << endl;

    return 0;
}

void power(int n)
{
    bool flag = false;

    /* 假设二进制下的n有16位 */
    for (int i = 15; i >= 0; --i)
    {
        int c = (n >> i) & 1; /* 从高位到低位 */

        if (c)
        {
            if (flag)
                cout << "+";  /* 需要输出加号 */

            if (i == 1)
                cout << "2";
            else if (i == 0)
                cout << "2(0)";
            else
            {
                cout << "2("; power(i); cout << ")";
            }

            if (!flag)
                flag = true;  /* 准备输出加号 */
        }
    }
}
