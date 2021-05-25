#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

string s;

void solve(string s)
{
    int n = s.size();
    long long sum_g = 0, ans = 0;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == 'G') sum_g = (sum_g + 1) % mod;
        else{
            ans = (ans + sum_g) % mod;
            sum_g = ( sum_g + (2 * sum_g % mod) ) % mod;
        }
    }
    printf("%lld\n", (ans % mod + mod)%mod );
}


int main()
{
    while(cin >> s){
        solve(s);
    }
    return 0;
}
