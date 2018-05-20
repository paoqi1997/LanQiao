/**
 * 算法训练 最大最小公倍数
 */

#include <iostream>

using namespace std;

int main()
{
    long long n, t;

    cin >> n;

    /* n - 0 | n - 1 | n - 2 */

    /* n - 0 | n - 1 | n - 3 */

    /* n - 1 | n - 2 | n - 3 */

    if (n < 3)
        t = n;
    /* n为奇数 */
    else if (n % 2)
        t = n * (n - 1) * (n - 2);           /* 01 02 03 */
    /* n为偶数 */
    else
    {
        /* n不能被3整除 */
        if (n % 3)
            t = n * (n - 1) * (n - 3);       /* (01)  02  (03) (04) */
        /* n能被3整除 */
        else
            t = (n - 1) * (n - 2) * (n - 3); /* (03) (04) (05)  06  */
    }

    cout << t << endl;

    return 0;
}
