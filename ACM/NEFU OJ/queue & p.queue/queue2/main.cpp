#include <bits/stdc++.h>
using namespace std;
struct stu{
char name[256];
int num;
}a[1001];
bool judge (int t){
if(t%7==0)
    return 0;
while(t){
    if(t%10==7)
        return 0;
    t=t/10;}
    return 1;
}
queue<stu>q;
int main()
{
    int n,m,t;
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++){
        cin>>a[i].name;
        a[i].num=i;
    }
    for(int i=1;i<=n;i++){
        q.push(a[i]);
    }
    for(int i=1;i<=m-1;i++){
        q.push(a[i]);
        q.pop();
    }
    t--;
    while(q.size()>1){
        t++;
        stu tmp=q.front();
        q.pop();
        if(judge(t))
            q.push(tmp);
    }
    cout<<q.front().name;
    return 0;
}
