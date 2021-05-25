#include <bits/stdc++.h>
using namespace std;
int n,x;
int main()
{
    while(cin>>n)
    {
        for(int i=1;i<=(n+1);i++){
        cin>>x;
        if(i==1){
            if(x==1)
                cout<<"x"<<"^"<<n+1-i;
            else if(x==-1)
                cout<<"-"<<"x"<<"^"<<n+1-i;
            else if(x==0)
                continue;
            else
                cout<<x<<"x"<<"^"<<n+1-i;
        }
        else if(i==(n+1)){
            if(x>0)
                cout<<"+"<<x;
            else if(x<0)
                cout<<x;
            else
                continue;
        }
        else if(x>0&&x!=1){
            if(i==n)
            cout<<"+"<<x<<"x";
            else
            cout<<"+"<<x<<"x"<<"^"<<n+1-i;
        }
        else if(x<0&&x!=-1){
            if(i==n)
            cout<<x<<"x";
            else
            cout<<x<<"x"<<"^"<<n+1-i;
        }
        else if(x==-1){
            if(i==n)
            cout<<"-"<<"x";
            else
            cout<<"-"<<"x"<<"^"<<n+1-i;
        }
        else if(x==1){
            if(i==n)
            cout<<"+"<<"x";
            else
            cout<<"+"<<"x"<<"^"<<n+1-i;
        }
        else{
            continue;
        }
    }
    printf("\n\n");
    }

    return 0;
}
