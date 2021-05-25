#include <iostream>
using namespace std;
int a[100001],b[100001];
void quick_sort(int l ,int r)
{
    int i=l,j=r;
    int mid=(l+r)>>1;
    int x=a[mid];
    while(i<=j){
        while(a[i]<x) i++;
        while(a[j]>x) j--;
        if(i<=j){
            swap(a[i],a[j]);
            i++;j--;
        }
    }
    if(l<j) quick_sort(l,j);
    if(l<r) quick_sort(i,r);
}
void _merge(int l,int mid,int r)
{
    int p1=l,p2=mid+1;
    for(int i=l;i<=r;i++){
        if((p1<=mid) && ((p2>r) || a[p1] <= a[p2])){
            b[i]=a[p1];
            p1++;
        }
        else{
            b[i]=a[p2];
            p2++;
        }
    }
    for(int i=l;i<=r;i++) a[i]=b[i];
}
void erfen(int l,int r)
{
    int mid=(l+r)/2;
    if(l<r){
        erfen(l,mid);
        erfen(mid+1,r);
    }
    _merge(l,mid,r);
}
int main()
{
    for(int i=1;i<=6;i++)
        cin>>a[i];
    erfen(1,6);
    for(int i=1;i<=6;i++)
        cout<<a[i];
    return 0;
}
