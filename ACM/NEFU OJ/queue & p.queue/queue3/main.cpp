#include <bits/stdc++.h>

using namespace std;

queue<int>vis1,vis2;
int main()
{
int n,m,k,s1,s2;
cin>>n>>m;
cin>>k;
for(int i=1;i<=n;i++)
vis1.push(i);
for(int i=1;i<=m;i++)
vis2.push(i);
for(int i=1;i<=k;i++)
{
s1=vis1.front();
vis1.pop();
s2=vis2.front();
vis2.pop();
cout<<s1<<" "<<s2<<endl;
vis1.push(s1);
vis2.push(s2);
}
return 0;
}
