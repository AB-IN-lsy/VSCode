/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-05 22:07:14
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-05 22:14:06
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

const int N = 2E6 + 10;
int a[N], q[N];

int main()
{
    IOS;
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    int l = 1, r = 0;
    for(int i = 1; i <= n; i ++){
        while(l <= r && q[l] + k - 1 < i) l ++;
        while(l <= r && a[q[r]] <= a[i]) r --;
        q[++ r] = i;
        if(i >= k) cout << a[q[l]] << '\n';
    }
    return 0;
}