#include <bits/stdc++.h>
using namespace std;
vector <vector<int> > a;
int main()
{
    ios::sync_with_stdio(false);
    int n;
    int i, j, t;
    i = j = t = 0;
    cin >> n;
    a.resize(n);
    for (vector <vector<int> >::iterator it = a.begin(); it != a.end(); ++it) //遍历
        (*it).resize(n);
    while (t < n * n)
    {
        t++;
        a[i][j] = t;
        if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1))//斜行0，2，4...
        {
            if (j != n - 1)
            {
                i--;
                j++;
            }
            else
                i++;
        }
        else if (((i % 2 == 0) && (j % 2 == 1)) || ((i % 2 == 1) && (j % 2 == 0)))//斜行1,3,5...
        {
            if (i != n - 1)
            {
                i += 1;
                j -= 1;
            }
            else
                j += 1;
        }
        if (i < 0)//防止出去
            i = 0;
        if (j < 0)
            j = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
            if (j != n - 1)
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}
