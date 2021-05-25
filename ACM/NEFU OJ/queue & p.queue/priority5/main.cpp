#include <bits/stdc++.h>
using namespace std;

int k,id,tim;
struct node
{
    int id,tim,sum;
};
bool operator < (const node &s1,const node &s2)
{
    if(s1.sum!=s2.sum)return s1.sum>s2.sum;
    return s1.id>s2.id;
}
priority_queue<node,vector<node> >q;
int main()
{
    string s;
    ios::sync_with_stdio(false);
    while(cin>>s)
    {
        if (s=="#") break;
        cin>>id>>tim;
        q.push({id,tim,tim});
    }
    cin>>k;
    while(k--)
    {
        node tmp=q.top();
        q.pop();
        printf("%d\n",tmp.id);
        q.push({tmp.id,tmp.tim,tmp.sum+tmp.tim});
    }
    return 0;
}
