#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

const int N = 2e5 + 10;

ll a[N], b[N], c[N];
int n;

bool cmd(int l, int r)
{

    return b[r] - b[l - 1] == (c[r] ^ c[l - 1]);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", a + i);
        b[i] = b[i - 1] + a[i];
        c[i] = c[i - 1] ^ a[i];
    }

    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        int t = i;
        for (int l = i, r = n; l <= r;)
        {
            int mid = (l + r) / 2;
            if (cmd(i, mid))
                l = mid + 1, t = mid;
            else
                r = mid - 1;
        }
        res += t - i + 1;
    }
    cout << res << endl;
    return 0;
}