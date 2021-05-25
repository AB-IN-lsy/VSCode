#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int breakfastNumber(vector<int>& staple, vector<int>& drinks, int x) {
        int ans=0;
        sort(staple.begin(),staple.end());
        sort(drinks.begin(),drinks.end());
        for(auto i:staple)
        {
            int tmp=upper_bound(drinks.begin(),drinks.end(),x-i)-drinks.begin();
            ans+=tmp;
        }
        return ans;
    }
};
int main()
{
    Solution solution;
    vector<int> a={10,20,5};
    vector<int> b={5,5,2};
    cout<<solution.breakfastNumber(a,b,15);
    return 0;
}
