/*
 * @Author: NEFU AB_IN
 * @Date: 2021-09-10 17:38:09
 * @FilePath: \Vscode\ACM\NiuKe\2021.9.10\a.cpp
 * @LastEditTime: 2021-09-11 10:27:52
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

signed main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int v, l, n;
        scanf("%d%d%d", &v, &l, &n);
        if (v + l <= n)
        {
            for (int i = 1; i <= v; i++)
                printf("5");
            for (int i = 1; i <= l; i++)
                printf("1");
        }
        else
        {
            int l_s = l - max(n - v, 0);
            for (int i = 1; i <= min(v, n); ++i)
            {
                if (l_s >= 3)
                {
                    printf("8");
                    l_s -= 3;
                }
                else if (l_s == 2)
                {
                    printf("7");
                    l_s -= 2;
                }
                else if (l_s == 1)
                {
                    printf("6");
                    l_s -= 1;
                }
                else
                {
                    printf("5");
                }
            }
            for (int i = 1; i <= n - v; ++i)
            {
                if (l_s >= 2)
                {
                    printf("3");
                    l_s -= 2;
                }
                else if (l_s == 1)
                {
                    printf("2");
                    l_s -= 1;
                }
                else
                    printf("1");
            }
        }
        printf("\n");
    }
    return 0;
}