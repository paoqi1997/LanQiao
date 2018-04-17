/* 基础练习 - 十六进制转八进制 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string hex_to_bin(string);
string bin_to_oct(string);

int main()
{
    int n;

    cin >> n;

    vector<string> vec;

    for (int i = 0; i < n; ++i)
    {
        string s; cin >> s;

        vec.push_back(bin_to_oct(hex_to_bin(s)));
    }

    for (int i = 0; i < n; ++i)
        cout << vec[i] << endl;

    return 0;
}

string hex_to_bin(string s)
{
    string ss;

    for (int i = 0; s[i] != '\0'; ++i)
    {
        switch (s[i])
        {
        case '0':
            ss += "0000"; break;
        case '1':
            ss += "0001"; break;
        case '2':
            ss += "0010"; break;
        case '3':
            ss += "0011"; break;
        case '4':
            ss += "0100"; break;
        case '5':
            ss += "0101"; break;
        case '6':
            ss += "0110"; break;
        case '7':
            ss += "0111"; break;
        case '8':
            ss += "1000"; break;
        case '9':
            ss += "1001"; break;
        case 'A':
            ss += "1010"; break;
        case 'B':
            ss += "1011"; break;
        case 'C':
            ss += "1100"; break;
        case 'D':
            ss += "1101"; break;
        case 'E':
            ss += "1110"; break;
        case 'F':
            ss += "1111"; break;
        default:
            break;
        }
    } return ss;
}

string bin_to_oct(string s)
{
    size_t i = 0;

    string ss;

    if (s.size() % 3 == 1)
    {
        if (s[i] == '1') ss += "1"; i += 1;
    }
    else if (s.size() % 3 == 2)
    {
        if (s[i] == '0')
        {
            if (s[i + 1] == '1')
                ss += "1";
        }
        else if (s[i] == '1')
        {
            if (s[i + 1] == '0')
                ss += "2";
            else if (s[i + 1] == '1')
                ss += "3";
        } i += 2;
    }

    for ( ; i <= s.size(); i += 3)
    {
        if (s[i] == '0')
        {
            if (s[i + 1] == '0')
            {
                if (s[i + 2] == '0')
                    ss += "0";
                else if (s[i + 2] == '1')
                    ss += "1";
            }
            else if (s[i + 1] == '1')
            {
                if (s[i + 2] == '0')
                    ss += "2";
                else if (s[i + 2] == '1')
                    ss += "3";
            }
        }
        else if (s[i] == '1')
        {
            if (s[i + 1] == '0')
            {
                if (s[i + 2] == '0')
                    ss += "4";
                else if (s[i + 2] == '1')
                    ss += "5";
            }
            else if (s[i + 1] == '1')
            {
                if (s[i + 2] == '0')
                    ss += "6";
                else if (s[i + 2] == '1')
                    ss += "7";
            }
        }
    } return ss;
}
