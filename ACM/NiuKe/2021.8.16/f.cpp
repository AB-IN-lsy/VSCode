/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-08-16 13:08:25
 * @FilePath: \Vscode\ACM\NiuKe\2021.8.16\f.cpp
 * @LastEditTime: 2021-08-16 16:55:14
 */

#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define DEBUG(X)                    cout << #X << ": " << X << endl;
typedef pair<int , int>             PII;

int n, cnt, flag;
const int N = 1E6 + 10;
int a[N], b[N], bb[N];


int main()
{
    IOS;
    cin >> n;
    string s;
    for(int i = 1; i <= 2 * n; ++ i){
        char c;
        cin >> c;
        if(c == '(') cnt ++;
        else {
            bb[cnt] ++;
            cnt = 0;
        }
        s += c;
    }
    cnt = 0;
    for(int i = 1; i <= n; ++ i){
        cin >> a[i];
        b[a[i]] ++;
        if(b[a[i]] > 1) cnt ++;
    }
    //DEBUG(cnt);
    for(int i = 2; i <= n; ++ i){
        if(bb[i]) cnt -= bb[i] * (i - 1);
    }
    //DEBUG(cnt);
    if(cnt > 0) return cout << "NO\n", 0;
    
    return 0;
}