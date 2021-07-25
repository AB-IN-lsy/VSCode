#include <bits/stdc++.h>
using namespace std;
int start,endn,data[401];
int t,n;
int main()
{
    cin>>t;
    while(t--){
        cin>>n;
        memset(data,0,sizeof(data));
        for(int i=1;i<=n;i++){
            cin>>start>>endn;
            if(start>endn)
                swap(start,endn);
            if(start%2==1)
                start=(start+1)/2;
            else
                start=start/2;
            if(endn%2==1)
                endn=(endn+1)/2;
            else
                endn=endn/2;
            for(int j=start;j<=endn;j++)
                data[j]++;
        }
        sort(data+1,data+201,greater<int>());
        cout<<data[1]*10<<endl;
    }
    return 0;
}
