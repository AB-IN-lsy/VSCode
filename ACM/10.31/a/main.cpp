#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll p, q;
int t;
int main()
{
    cin >> t;
    while( t -- )
    {
        cin >> p >> q;
        vector < int > v;
        if(p % q != 0) cout << p <<endl;
        else{
            ll tmp_q = q;
            ll tmp_p = p;
            for(int i = 2;i <= tmp_q / i; i++)
            {
                while(tmp_q % i==0){
                    tmp_q /= i;
                    v.push_back(i);
                }
            }
            if(tmp_q > 1) v.push_back(tmp_q);
            ll mx = -1;
            for(int i = 0; i < v.size(); i++){
                tmp_p = p;
                while(tmp_p % q == 0)
                {
                    tmp_p /= v[i];
                }
                mx = max(tmp_p , mx);
            }
            cout << mx <<endl;
        }
    }
    return 0;
}
