#include <bits/stdc++.h>
using namespace std;

int counter(int x)
{
    int y=log10(x)+1;
    int tmp,n=0;
    for(int i=1;i<=y;i++){
        tmp=x%10;
        if(tmp==2)
            n++;
        x=x/10;
    }
    return n;
}
int main()
{
    int l,r;
    int num=0;
    while(cin>>l>>r){
            num=0;
        for(int i=l;i<=r;i++){
            num+=counter(i);
        }
        cout<<num<<endl;
    }

    return 0;
}
