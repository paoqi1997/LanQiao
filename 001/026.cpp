/* 基础练习 - 报时助手 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1[] = {"zero", "one", "two", "three", "four",
                   "five", "six", "seven", "eight", "nine",
                   "ten", "eleven", "twelve", "thirteen", "fourteen",
                   "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    string s2[] = {"twenty", "thirty", "forty", "fifty"};

    int h, m;

    cin >> h >> m;

    if (h >= 0 && h < 20)
        cout << s1[h] << ' ';
    else if (h == 20)
        cout << s2[0] << ' ';
    else
        cout << s2[0] << ' ' << s1[h % 20] << ' ';

    if (m == 0)
        cout << "o'clock" << endl;
    else if (m > 0 && m < 20)
        cout << s1[m] << endl;
    else if (m % 10 == 0)
        cout << s2[m / 10 - 2] << endl;
    else
        cout << s2[m / 10 - 2] << ' ' << s1[m % 10] << endl;

    return 0;
}
