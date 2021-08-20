/*
 * @Author: NEFU AB_IN
 * @Date: 2021-08-20 00:11:01
 * @FilePath: \Vscode\ACM\NiuKe\2021.8.14\h.cpp
 * @LastEditTime: 2021-08-20 00:27:06
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
    int n;
    cin >> n;
    string s;
    while(n){
        n --;
        if(n % 3 == 0) s += '2';
        else if(n % 3 == 1) s += '3';
        else s += '6'; 
        n /= 3;
    }   
    reverse(s.begin(), s.end());
    cout << s << '\n';
    return 0;
}