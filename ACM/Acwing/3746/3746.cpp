/*
 * @Author: NEFU AB-IN
 * @Date: 2022-06-21 17:36:06
 * @FilePath: \ACM\Acwing\3746\3746.cpp
 * @LastEditTime: 2022-06-21 17:36:35
 */
#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>

using namespace std;

const int N = 110;

int n, m;
int g[N][N];
unordered_map<string, int> id;

int main()
{
    cin >> m >> n;
    for (int i = 0; i < n; i++)
    {
        string name;
        cin >> name;
        id[name] = i;
    }

    string name[N];
    while (m--)
    {
        for (int i = 0; i < n; i++)
            cin >> name[i];
        for (int i = 0; i < n; i++)
        {
            int j = i + 1;
            while (j < n && name[j] > name[j - 1])
                j++;
            while (j < n)
            {
                int a = id[name[i]], b = id[name[j]];
                g[a][b] = 1;
                j++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (i == j)
                cout << 'B';
            else if (!g[i][j] && !g[j][i])
                cout << '?';
            else if (!g[i][j])
                cout << 1;
            else
                cout << 0;
        cout << endl;
    }

    return 0;
}