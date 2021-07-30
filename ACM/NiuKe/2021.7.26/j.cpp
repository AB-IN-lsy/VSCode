/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-30 03:42:22
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-30 03:47:08
 */
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e5;
int arr[MAXN+5];
double sum[MAXN+5];
int n,m,x,y;

bool check(double avg,int l,int r) // 共l个数，长度必须大于等于r
{
    for(int i=1;i<=l;++i) sum[i]=sum[i-1]+arr[i]-avg; //bi, 即维护了一个前缀最小值
    double minv=0;
    for(int i=r;i<=l;++i){
        minv=min(minv,sum[i-r]);
        if(sum[i]>=minv) return true;
    }
    return false;
}

int main()
{
    cin>>n>>m>>x>>y;
    double l=0,r=0;
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=n;++i){
        scanf("%d",arr+i);
        r=max(r,double(arr[i]));
    }
    while(r-l>1e-7){
        double mid=(l+r)/2;
        if(check(mid,n,x)) l=mid; // n个数，长度要为x
        else r=mid;
    }
    double ans=0;
    ans+=r;
    l=r=0;
    for(int i=1;i<=m;++i){
        scanf("%d",arr+i);
        r=max(r,double(arr[i]));
    }
    while(r-l>1e-7){
        double mid=(l+r)/2;
        if(check(mid,m,y)) l=mid;
        else r=mid;
    }
    ans+=r;
    printf("%.7f\n",ans);
    return 0;
}
