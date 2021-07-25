#include <bits/stdc++.h>

using namespace std;
int check(string x){
    if(x=="10") return 10;
    if(x[0]>='2' && x[0]<='9') return x[0]-'0';
    if(x[0]=='A') return 1;
    if(x[0]=='J') return 11;
    if(x[0]=='Q') return 12;
    if(x[0]=='K') return 13;
}
int t,n;
string x;
int main()
{
    cin>>t;
    for(int j=1;j<=t;j++){
        int f=0;
        cin>>n;
        int sum=0;
        for(int i=1;i<=n;i++){
            cin>>x;
            sum+=check(x);
            if(sum&1) f=1;
        }
        if(f) printf("Case #%d: Girl\n",j);
        else printf("Case #%d: Song\n",j);
    }
    return 0;
}
/*
2
5
J Q K 10 4
5
2 5 6 8 K
*/
