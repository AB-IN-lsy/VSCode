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
    int p1=l,p2=mid+1;///两个指针，p1为左边数组的指针的第一个，p2为右边数组的指针的第一个
    for(int i=l;i<=r;i++){
        if((p1<=mid) && ((p2>r) || a[p1] <= a[p2])){///当左区间有数，右区间没数了或者左最小小于右最小，故从左区间取数，存到b临时数组
            b[i]=a[p1];
            p1++;
        }
        else{
            b[i]=a[p2];
            p2++;
        }
    }
    for(int i=l;i<=r;i++) a[i]=b[i];///将a数组统一成b
}
void erfen(int l,int r)
{
    int mid=(l+r)/2;
    if(l<r){
        erfen(l,mid);
        erfen(mid+1,r);
    }
    _merge(l,mid,r);///1.到这儿时，l=mid=r，然后递归之后三者不相等///2.l=mid=r时，就是将这个数先放进去
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
