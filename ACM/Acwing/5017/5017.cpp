/*
 * @Author: NEFU AB-IN
 * @Date: 2023-08-26 22:46:52
 * @FilePath: \Acwing\5017\5017.cpp
 * @LastEditTime: 2023-08-26 23:12:05
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#undef int

#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(nullptr);                                                                                                  \
    cout.tie(nullptr)
#define DEBUG(X) cout << #X << ": " << X << '\n'
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

int t[N], c[N];

signed main()
{
    //freopen("Tests/input_1.txt", "r", stdin);
    IOS;
    int n, m, k, mx = k;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; ++ i){
        cin >> t[i] >> c[i];
        mx = max(mx, t[i]);
    }

    int l = k, r = mx;


    auto check  = [&](int x){
        int m_tmp = m;
        for(int i = 1; i <= n; ++ i){
            if (x > t[i]) continue;
            m_tmp -= (t[i] - x) * c[i];
            if (m_tmp < 0) return false;
        }
        return true;
    };


    while (l < r){
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << r ;
    return 0;
}