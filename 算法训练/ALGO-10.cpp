/**
 * 算法训练 集合运算
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* 交集 */
void print_intersection(int[], int, int[], int);

/* 并集 */
void print_union(int[], int, int[], int);

/* 余集 */
void print_complement(int[], int, int[], int);

int main()
{
    int n, m;

    cin >> n;

    int s1[n];

    for (int i = 0; i < n; ++i)
        cin >> s1[i];

    cin >> m;

    int s2[m];

    for (int i = 0; i < m; ++i)
        cin >> s2[i];

    sort(s1, s1 + n);
    sort(s2, s2 + m);

    print_intersection(s1, n, s2, m);

    print_union(s1, n, s2, m);

    print_complement(s1, n, s2, m);

    return 0;
}

void print_intersection(int s1[], int n, int s2[], int m)
{
    vector<int> vec;

    for (int i = 0; i < n; ++i)
        vec.push_back(s1[i]);

    for (int i = 0; i < m; ++i)
    {
        if (find(vec.begin(), vec.end(), s2[i]) != vec.end())
        {
            cout << s2[i] << ' ';
        }
    } cout << endl;
}

void print_union(int s1[], int n, int s2[], int m)
{
    vector<int> vec;

    for (int i = 0; i < n; ++i)
        vec.push_back(s1[i]);

    for (int i = 0; i < m; ++i)
    {
        if (find(vec.begin(), vec.end(), s2[i]) == vec.end())
            vec.push_back(s2[i]);
    }

    sort(vec.begin(), vec.end());

    for (size_t i = 0; i < vec.size(); ++i)
        cout << vec[i] << ' ';
    cout << endl;
}

void print_complement(int s1[], int n, int s2[], int m)
{
    vector<int> vec;

    for (int i = 0; i < m; ++i)
        vec.push_back(s2[i]);

    for (int i = 0; i < n; ++i)
    {
        if (find(vec.begin(), vec.end(), s1[i]) == vec.end())
        {
            cout << s1[i] << ' ';
        }
    } cout << endl;
}
