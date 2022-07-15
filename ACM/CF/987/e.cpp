/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-05 09:15:35
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-05 09:15:36
 */
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define MP make_pair
#define SZ(X) ((int)(X).size())
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
typedef pair<int, int> PII;

const int N = 1000005;
int n, a[N], cnt;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        while (a[i] != i)
        {
            swap(a[i], a[a[i]]);
            cnt++;
        }
    }
    if ((3 * n - cnt) & 1)
        printf("Um_nik\n");
    if ((7 * n + 1 - cnt) & 1)
        printf("Petr\n");
    return 0;
}