#include<bits/stdc++.h>
using namespace std;
int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int a,b,c;
int main()
{
    while(~scanf("%d/%d/%d",&a,&b,&c)){
        if((a%4==0&&a%100!=0)||a%400==0)
            m[2]=29;
        else
            m[2]=28;
        int sum=0;
        for(int i=1;i<b;i++){
            sum+=m[i];
        }
        sum+=c;
        cout<<sum<<endl;
    }
    return 0;
}
