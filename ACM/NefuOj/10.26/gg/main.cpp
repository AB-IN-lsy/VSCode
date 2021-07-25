#include <bits/stdc++.h>

using namespace std;

struct sa
{
    int x;
    int step;
    double gl;
};

struct cc
{
    int step;
    double gl;
};
vector < cc > v;
queue < sa > q;
int n ,d ,t;
double bfs ()
{
    q.push( (sa) {n , 0 , 1.0});
    double ans = 0.0;
    while(!q.empty()){
        sa tmp=q.front();
        q.pop();
        int step = tmp.step;
        double gl = tmp.gl;
        int x = tmp.x;
        if (x == 0){
            if (gl < 1e-6) return ans;
            ans += gl;
            v.push_back( (cc) {step , gl});
        }
        for(int i = 1 ; i < d ;i++){
            int x1 = x - i;
            if (x1 >= 0){
                q.push( (sa) {x1 , step + 1 , gl * 1 / d});
            }
            else break;
        }
        q.push( (sa) {x , step+1 , gl * 1 / d});
    }
    return ans;
}

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&d);
        double ans = bfs();
        double cnt = 0.0;
        //cout<<ans<<endl;
        for(auto i:v){
            //cout<<i.gl<<" "<<i.step<<endl;
            cnt += i.gl / ans * i.step;
        }
        printf("%.2f\n",cnt);
    }
    return 0;
}
/*
5
2 6
3 6
4 6
5 6
6 6
*/
