#include <bits/stdc++.h>
using namespace std;
struct sa
{
    int j;
    int f;
    double ave;
}a[10001];
int cmp(const sa &a,const sa &b)
{
    return a.ave>b.ave;
}
int m,n;
double sum;
int main()
{
    while(cin>>m>>n){
        sum=0.0;
        if(m==-1&&n==-1)
            break;
        for(int i=1;i<=n;i++){
            cin>>a[i].j>>a[i].f;
            a[i].ave=(double)a[i].j/(double)a[i].f;
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(m>=a[i].f){
                sum+=a[i].j;
                m-=a[i].f;
            }
            else{
                sum+=(double)m*a[i].ave;
                break;
            }
        }
        printf("%.3f\n",sum);
    }
    return 0;
}
