/*
 * @Author: Icey_dying
 * @Date: 2021-09-18 13:40:11
 * @LastEditors: Please set LastEditors
 * @LastEditTime: 2021-09-18 14:07:04
 * @FilePath: \Vscode\ACM\Hdu\2021.9.18\g.cpp
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 2e7 + 5;
const int MAXN = 1e7 + 5;
int n, cnt = 0, l, r, ans = 1, q, x;
int a[N];    //模拟队列
bool b[N];   //标记是否删去,true表示删去
int c[MAXN]; //记录数在a数组的位置
int main()
{
    l = 1e7;
    r = 1e7 + 1;
    q = l + 1;
    memset(b, false, sizeof(b));
    char ch;
    scanf("%d", &n);
    while (n--)
    {
        getchar();
        scanf("%c", &ch);
        switch (ch)
        {
        case 'L':
            a[l] = ans;
            c[ans] = l;
            l--;
            ans++;
            if (cnt % 2 == 0)
            {
                q--;
                while (b[q] == true)
                    q--;
            }
            cnt++;
            break;
        case 'R':
            a[r] = ans;
            c[ans] = r;
            r++;
            ans++;
            if (cnt % 2)
            {
                q++;
                while (b[q] == true)
                    q++;
            }
            cnt++;
            break;
        case 'G':
            scanf("%d ", &x);
            b[c[x]] = true;
            if (cnt % 2)
            {
                if (c[x] <= q)
                {
                    q++;
                    while (b[q] == true)
                        q++;
                }
            }
            else
            {
                if (c[x] >= q)
                {
                    q--;
                    while (b[q] == true)
                        q--;
                }
            }
            cnt--;
            break;
        case 'Q':
            printf("%d\n", a[q]);
        }
    }
    return 0;
}
