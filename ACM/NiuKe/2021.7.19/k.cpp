/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-19 13:28:03
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-19 13:47:32
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;
int a[10], b[10];
int main()
{
    IOS;
    stack<int> s;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];   
    for(int i = 1; i <= n; i ++){
        while(!s.empty() && s.top() > a[i]){
            s.pop();
        }
        s.push(a[i]);
        b[i] = s.size();
    }
    for(int i = 1; i <= n; i ++){
        cout << b[i] << " ";
    }
    return 0;
}