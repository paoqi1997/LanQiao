/* 基础练习 - 闰年判断 */

#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;

    if ((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0))
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}