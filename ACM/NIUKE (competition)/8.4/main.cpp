#include<bits/stdc++.h>
using namespace std;
const int maxn=1000010;
int a[maxn],t,x;
int main()
{
    cin>>t;
    while(t--)
    {
        int maxm=-0x3f3f3f,flag=0;
        memset(a, 0, sizeof(a));
        while(cin>> x&& x!=0) {a[x]++;maxm=max(x,maxm);}
        for(int i=1;i<=maxm;i++){
            if(a[i]&1){
                cout<<"No"<<endl;
                flag=1;
                break;
            }
        }
        if(!flag) cout<<"Yes"<<endl;
    }
}
