#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef unsigned long long ll;
    ll qm (ll a, ll b ,ll c){
        ll ret=1%c;
        while(b){
            if(b&1)
                ret=ret*a%c;
            a=a*a%c;
            b=b>>1;
        }
        return ret;
    }
    bool solve(int x) {
        // write code here
        ll a=0;
        while(a<1000){
            int b=qm(a, 2, 1000);
            if(b==x) return true;
            a++;
        }
        return false;
    }
};
int main()
{
    Solution solution;
    cout<<solution.solve(24)<<endl;
    return 0;
}
