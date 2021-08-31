/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-27 21:43:30
 * @FilePath: \Vscode\ACM\NiuKe\2021.8.27\h.cpp
 * @LastEditTime: 2021-08-27 21:43:30
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
    for(int i = 1; i <= 10; ++ i){
        cout << (i * log(i)) / (log(log(i))) << '\n';
    }   
    return 0;
}