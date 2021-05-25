#include <bits/stdc++.h>
using namespace std;
int vis[1001];char b[1001];
string a;
int main()
{
    while(getline(cin,a)){
        int len=a.size();
        for(int i=0;i<len;i++){
            if(a[i]<='z'&&a[i]>='a')
                vis[a[i]&31]++;
            if(a[i]=='#')
                goto label;
        }
    }
    label:
    int num=1;
    for(int i='a';i<='z';i++){
        b[num++]=i;
    }
    for(int i=1;i<=26;i++){
        cout<<b[i]<<" "<<vis[i]<<endl;
    }
    return 0;
}
