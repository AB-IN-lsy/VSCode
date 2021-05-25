#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    struct sa
    {
        int x;
        int c;
    };
    int busRapidTransit(int target, int inc, int dec, vector<int>& jump, vector<int>& cost) {
        int mod=1000000007;
        unordered_map<int,int> vis;
        queue<sa>q;
        q.push( (sa) {1,inc});
        int ans=0x3f3f3f3f;
        while(!q.empty())
        {
            sa tmp=q.front();
            q.pop();
            int x=tmp.x;
            int c=tmp.c;
            if(x>target){
                ans=min(ans,c+(x-target)%mod*dec%mod);
                continue;
            }
            else if(x==target){
                ans=min(ans,c);
                continue;
            }
            else{
                ///
                int in=c+inc%mod;
                int de=c+dec%mod;
                if(x+1==target)
                {
                    ans=min(ans,in);
                    continue;
                }
                else if(vis[x+1]>in || !vis[x+1])
                {
                    q.push( (sa) {x+1,in});
                    vis[x+1]=in;
                }

                ///

                if(x-1==target)
                {
                    ans=min(ans,de);
                    continue;
                }
                else if((x!=1 && x!=0) && (!vis[x-1] || vis[x-1]>de))
                {
                    q.push( (sa) {x-1,de});
                    vis[x-1]=de;
                }


                ///
                for(int i=0;i<jump.size();i++)
                {
                    int w=c+cost[i]%mod;
                    int j=jump[i]*x;
                    if( j > target)
                        ans=min(ans,w+(j-target)%mod*dec%mod);
                    else if(j==target)
                    {
                        ans=min(ans,w);
                        break;
                    }
                    else if(!vis[j] || vis[j]>w)
                    {
                        q.push( (sa) {j,w});
                        vis[j]=w;
                    }
                }
            }
        }
        return ans%mod;
    }
};

int main()
{
    Solution solution;
    vector<int> a={3,6,8,11,5,10,4};
    vector<int> b={4,7,6,3,7,6,4};
    cout<<solution.busRapidTransit(612,4,5,a,b);
    return 0;
}
/*
612
4
5
[3,6,8,11,5,10,4]
[4,7,6,3,7,6,4]
*/
/*
31
5
3
[6]
[10]
*/
