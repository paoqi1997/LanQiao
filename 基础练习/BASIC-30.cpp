/**
 * 基础练习 阶乘计算
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;

    cin >> n;

    vector<int> vec;

    if (n == 1)
        cout << '1' << endl;
    else
    {
        /* 创建个位 */
        vec.push_back(1);

        for (int i = 2; i <= n; ++i)
        {
            int c = 0; /* 存储进位 */

            for (size_t j = 0; j < vec.size(); ++j)
            {
                int t = vec[j] * i + c;

                vec[j] = t % 10; c = t / 10;
            }

            while (c)  /* 仍需要进位 */
            {
                vec.push_back(c % 10); c /= 10;
            }
        }

        /* 从最高位打印到个位 */
        for (size_t i = 0; i < vec.size(); ++i)
            cout << vec[vec.size() - i - 1];
        cout << endl;
    }

    return 0;
}
