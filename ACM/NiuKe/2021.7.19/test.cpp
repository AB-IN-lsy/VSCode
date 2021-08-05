/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-22 00:21:21
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-08-05 10:50:25
 */
#include <iostream>
#include <algorithm>
using namespace std;
int b[1000010];
int a[1000010];
int st[1000010];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        int pos;
        cin>>pos>>a[pos];
    }
    for(int i=1;i<=n;i++){
        if(!a[i])a[i]=a[i-1]+1;
        else if(a[i]>a[i-1]+1){
                cout<<"-1"<<endl;
                return 0;
        }
    }
    int cnt=0,top=0;
    for(int i=n;i>=1;i--){
        while(a[i]>top)st[++top]=++cnt;//++cnt能保证先把小的弹出来再把大的弹出来
        b[i]=st[top];
        top--;
    }
    for(int i=1;i<=n;i++)cout<<b[i]<<' ';
    return 0;
}

