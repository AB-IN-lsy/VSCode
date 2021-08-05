#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define MP                          make_pair
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

int t, n, x;

int main()
{
    IOS;
    cin >> t;
    while(t --){
        cin >> n;
        int cnt = 0;
        for(int i = 1; i <= n; i ++){
            cin >> x;
            cnt += (x == i);
        }
        if(cnt >= 20) cout << "First\n";
        else cout << "Second\n";
    }
    return 0;
}