#include<bits/stdc++.h>
#define N 300100
using namespace std;
int num,head[N];
long long a[N];
struct node {
    int next;
    int to;
}edge[N];
void add(int from,int to) {
    edge[++num].next=head[from];
    edge[num].to=to;
    head[from]=num;
}
void fs(int x,int fa) {
    for(int i=head[x];i;i=edge[i].next) {
        int v=edge[i].to;
        if(v==fa) continue;
        a[v]+=a[x];
        fs(v,x);
    }

}
int main() {
    int n,i,x,y,m;
    cin>>n>>m;
    for(i=1;i<n;i++) {
        scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
    }
    for(i=1;i<=m;i++) {
        scanf("%d%d",&x,&y);
        a[x]+=y;
    }
    fs(1,0);
    for(i=1;i<n;i++) {
        printf("%lld ",a[i]);
    }
    printf("%lld\n",a[i]);
    return 0;
}
