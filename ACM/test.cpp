#include <bits/stdc++.h>
using namespace std;
#define SZ(X) ((int)(X).size())
#define IOS                                                                                                            \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
#define DEBUG(X) cout << #X << ": " << X << endl;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
signed main()
{
    IOS;
    vector<int> a(13, 3);
    iota(a.begin(), a.end(), 2);
    for (auto i : a)
        cout << i << " ";
    return 0;
}