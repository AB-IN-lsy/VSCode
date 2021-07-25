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
        for(int i=1;i<=n;i++){
            cin>>a[i].j>>a[i].f;
            a[i].ave=(double)a[i].f/(double)a[i].j;
        }
        sort(a+1,a+n+1,cmp);
        for(int i=1;i<=n;i++){
            if(m>=a[i].j){
                sum+=a[i].f;
                m-=a[i].j;
            }
            else{
                sum+=(double)m*a[i].ave;
                break;
            }
        }
        printf("%.2f\n",sum);
    }
    return 0;
}
