#include <bits/stdc++.h>

using namespace std;

const int N=5e3+10;
struct sa
{
    int x;
    int y;
}a[N];

vector <int> v;

int n,m,x,y,c,mn,ans;
int main()
{
    freopen("test.in","r",stdin);
    freopen("w.txt","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n ;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    for(int i = 1; i <= m ;i++){
        scanf("%d",&c);
        v.push_back(c);
    }
    for(int i = 1; i <= n - 1 ;i++){
        if( find(v.begin(),v.end(),i+1) != v.end()) continue;
        mn = abs(a[i].x - a[i+1].x) + abs(a[i].y - a[i+1].y);
        for(auto j : v){
            mn = min(mn , abs(a[j].x - a[i+1].x) + abs(a[j].y - a[i+1].y));
        }
        ans += mn;
    }
    printf("%d\n",ans);
    return 0;
}
