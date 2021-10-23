/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-27 19:23:51
 * @FilePath: \Vscode\ACM\NiuKe\2021.8.27\f.cpp
 * @LastEditTime: 2021-08-27 19:25:42
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
    int a, b;
    cin >> a >> b;
    if((a + b) & 1) cout << "yukari\n";
    else cout << "akai\n"; 
    return 0;
}