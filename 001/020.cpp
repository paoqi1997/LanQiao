/* 基础练习 - 数的读法 */

#include <iostream>
#include <string>

using namespace std;

/* 第一部分为亿位到十亿位 */

/* 第二部分为万位到千万位 */

/* 第三部分为个位到千位 */

void print(char);

void func(string);

bool zero(string);

static string box[] =
    {"shi", "bai", "qian", "wan", "yi"};

int main()
{
    string s; cin >> s;

    size_t i = 0, len = s.size();

    while (len > 0)
    {
          /* 第一部分 */
        if (len > 8)
        {
            if (len == 10)
            {
                if (s[i + 1] == '0')
                {
                    cout << box[0] << ' ' << box[4] << ' ';
                }
                else
                {
                    cout << box[0] << ' '; print(s[i + 1]); cout << box[4] << ' ';
                }
                i += 2; len -= 2;
            }
            else if (len == 9)
            {
                print(s[i]); cout << box[4] << ' ';

                i += 1; len -= 1;
            }
        } /* 第二部分 */
        else if (len > 4 && len <= 8)
        {
            string s2 = s.substr(i, len - 4);

              /* 第二部分全为零 */
            if (zero(s2))
            {
                string s3 = s.substr(s.size() - 4);

                /* 第三部分全为零 */
                if (zero(s3))
                    break;
                /* 第三部分不全为零 */
                else
                {
                    print('0');

                    while (s[i] == '0') { ++i; --len; }
                }
            } /* 第二部分不全为零 */
            else
            {
                if (s[i] == '0') print('0');

                while (s[i] == '0') { ++i; --len; }

                string s2_rest = s.substr(i, len - 4);

                /* 处理第二部分中的剩余位 */
                func(s2_rest); cout << box[3] << ' ';

                /* 跳转到第三部分 */
                i += s2_rest.size(); len -= s2_rest.size();

                /* 第三部分全为零 */
                if (zero(s.substr(i)))
                    break;
                /* 第三部分不全为零 */
                else
                {
                    if (s[i] == '0') print('0');

                    while (s[i] == '0') { ++i; --len; }
                }
            }
        } /* 第三部分 */
        else if (len > 0 && len <= 4)
        {
            string s3 = s.substr(i); func(s3); break;
        }
    } cout << endl;

    return 0;
}

void print(char c)
{
    string con[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

    cout << con[c - '0'] << ' ';
}

void func(string s)
{
    bool flag = false;

    size_t i = 0, len = s.size();

    while (len > 0)
    {
          /* 千位 */
        if (len == 4)
        {
            print(s[i]); cout << box[2] << ' ';

            i += 1; len -= 1;
        } /* 百位 */
        else if (len == 3)
        {
              /* 百位为零 */
            if (s[i] == '0')
            {
                  /* 十位为零 */
                if (s[i + 1] == '0')
                {
                    /* 个位为零 */
                    if (s[i + 2] == '0')
                        break;
                    /* 个位不为零 */
                    else
                    {
                        print('0');

                        i += 2; len -= 2;
                    }
                } /* 十位不为零 */
                else
                {
                    print('0');

                    i += 1; len -= 1; flag = true;
                }
            } /* 百位不为零 */
            else
            {
                print(s[i]); cout << box[1] << ' ';

                  /* 十位为零 */
                if (s[i + 1] == '0')
                {
                    /* 个位为零 */
                    if (s[i + 2] == '0')
                        break;
                    /* 个位不为零 */
                    else
                    {
                        print('0');

                        i += 2; len -= 2;
                    }
                } /* 十位不为零 */
                else
                {
                    i += 1; len -= 1; flag = true;
                }
            }
        } /* 十位 */
        else if (len == 2)
        {
              /* 为一 */
            if (s[i] == '1')
            {
                  /* 输出一十 */
                if (flag)
                {
                    print('1'); cout << box[0] << ' ';
                } /* 输出十 */
                else
                    cout << box[0] << ' ';
            } /* 不为一 */
            else
            {
                print(s[i]); cout << box[0] << ' ';
            }
            i += 1; len -= 1;
        } /* 个位 */
        else if (len == 1)
        {
            if (s[i] != '0') print(s[i]); break;
        }
    }
}

bool zero(string s)
{
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] != '0') return false;
    } return true;
}
