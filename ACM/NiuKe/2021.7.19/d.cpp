/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-19 12:19:33
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-19 13:15:06
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
typedef pair<int, int> PII;

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int flag = 0;
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        if (a1 > b1)
            swap(a1, b1);
        if (a2 > b2)
            swap(a2, b2);
        if (a1 == 2 && b1 == 8 || a2 == 2 && b2 == 8)
        {
            if (a1 == 2 && b1 == 8 && !(a2 == 2 && b2 == 8))
            {
                puts("first");
                continue;
            }
            if (a2 == 2 && b2 == 8 && !(a1 == 2 && b1 == 8))
            {
                puts("second");
                continue;
            }
        }
        else
        {
            if (a1 == b1 || a2 == b2)
            {
                if (a1 == b1 && a2 != b2)
                {
                    puts("first");
                    continue;
                }
                if (a2 == b2 && a1 != b1)
                {
                    puts("second");
                    continue;
                }
                if (a1 == b1 && a2 == b2)
                {
                    if (a1 > a2)
                    {
                        puts("first");
                        continue;
                    }
                    if (a1 < a2)
                    {
                        puts("second");
                        continue;
                    }
                }
            }
            else
            {
                if ((a1 + b1) % 10 != (a2 + b2) % 10)
                {
                    if ((a1 + b1) % 10 > (a2 + b2) % 10)
                    {
                        puts("first");
                        continue;
                    }
                    if ((a1 + b1) % 10 < (a2 + b2) % 10)
                    {
                        puts("second");
                        continue;
                    }
                }
                else
                {
                    if (b1 > b2)
                    {
                        puts("first");
                        continue;
                    }
                    if (b1 < b2)
                    {
                        puts("second");
                        continue;
                    }
                }
            }
        }
        puts("tie");
    }
    return 0;
}