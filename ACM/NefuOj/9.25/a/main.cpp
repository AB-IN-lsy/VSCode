#include <bits/stdc++.h>

using namespace std;
const int N=1e6+10;
struct sa{
    int t;
    int v;
    bool operator <(const sa &a) const {
        return a.t > t;
    }
}a[N];
int num;

priority_queue< int,vector<int>,greater<int>>q;

int n;
int main()
{
    while(cin>>n)
    {
        for(int i=1;i<=n;i++){
            cin>>a[i].t>>a[i].v;
        }
        sort(a+1,a+1+n);
        long long sum=0;
        for(int i=1;i<=n;i++){
            if(a[i].t>q.size()){
                sum+=a[i].v;
                q.push( a[i].v );
            }
            else{
                sum+=a[i].v;
                q.push( a[i].v );
                sum-=q.top();
                q.pop();
            }
        }
        cout<<sum<<endl;
        while(!q.empty()) q.pop();
    }
    return 0;
}
