#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    /**
     * 返回一个数，代表让这些数都变成奇数的最少的操作次数
     * @param n int整型 代表一共有多少数
     * @param a int整型vector 代表n个数字的值
     * @return int整型
     */
     map<int,int>vis;
    int solve(int n, vector<int>& a) {
        int cnt=0;
        // write code here
        sort(a.begin(),a.end(),less<int>());
        for(int i=0;i<a.size();i++)
        {
            cnt=0;
            if(a[i]&1) continue;
            else while(a[i]>1&&(!(a[i]&1))&&(!vis[a[i]]))
            {
                a[i]=a[i]/2;
                vis[a[i]]=1;
                cnt++;
            }
        }
        return cnt;
    }
};
int main()
{
    Solution solution;
    vector<int>a;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++) cin>>x,a.push_back(x);
    cout<<solution.solve(n,a)<<endl;
    return 0;
}
