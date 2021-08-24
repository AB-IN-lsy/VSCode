/*
 * @Author: NEFU AB_IN
 * @Date: 2021-07-16 18:21:31
 * @FilePath: \Vscode\test.cpp
 * @LastEditTime: 2021-08-21 19:08:48
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(X)                    cout << #X << ": " << X << endl;
typedef pair<int , int>             PII;

signed main()
{
    IOS;
    int t;
    cin >> t;
    while(t --){
        int n, k;
        cin >> n >> k;
        if(n == 1) {
            cout << "No!\n";
            continue;
        }
        if((n & k)) cout << "Yes!\n";
        else cout << "No!\n";
    }
    return 0;
}