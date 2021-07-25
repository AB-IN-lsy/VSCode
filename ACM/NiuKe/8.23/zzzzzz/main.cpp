#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    /**
     * @param a: Left margin
     * @param b: Right margin
     * @return: return the greatest common multiple
     */
    long long greatestcommonmultiple(int a, int b) {
        // write your code here
        long long ans=0;
        if(b-a==2 && !(b&1)){
            ans=b/__gcd(b,b-2)*(b-2);
            ans*=(b-1);
        }
        else if(!(b&1)){
            ans=b*(b-1)*(b-3);
        }
        else ans=b*(b-1)*(b-2);
        return ans;
    }
};
int main()
{
    Solution solution;
    cout<<solution.greatestcommonmultiple(1,5000)<<endl;
    return 0;
}
