/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-05-28 22:36:46
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-05-29 09:46:51
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

const int N = 1e5 + 10;
int a[N], n;
int main()
{
    IOS;
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    multiset <int> s1;
    for(int i = 1; i <= n; i++){
        auto tmp = s1.upper_bound(a[i]); //最长不下降子序列
        if(tmp != s1.end()) s1.erase(tmp);
        s1.insert(a[i]);
    }
    cout << "最长不下降子序列" << endl;
    for(auto& i : s1) cout << i << " ";
    cout << "\n";

    multiset <int> s2;
    for(int i = 1; i <= n; i++){
        auto tmp = s2.lower_bound(a[i]); //最长上升子序列
        if(tmp != s2.end()) s2.erase(tmp);
        s2.insert(a[i]);
    }
    cout << "最长上升子序列" << endl;
    for(auto& i : s2) cout << i << " ";
    cout << "\n";

    multiset <int, greater<int>> s3;
    for(int i = 1; i <= n; i++){
        auto tmp = s3.upper_bound(a[i]); //最长不上升子序列
        if(tmp != s3.end()) s3.erase(tmp);
        s3.insert(a[i]);
    }
    cout << "最长不上升子序列" << endl;
    for(auto& i : s3) cout << i << " ";
    cout << "\n";

    multiset <int, greater<int>> s4;
    for(int i = 1; i <= n; i++){
        auto tmp = s4.lower_bound(a[i]); //最长下降子序列
        if(tmp != s4.end()) s4.erase(tmp);
        s4.insert(a[i]);
    }
    cout << "最长下降子序列" << endl;
    for(auto& i : s4) cout << i << " ";
    cout << "\n";
    return 0;
}
/*
10
1 3 5 2 6 1 3 1 1 1
*/