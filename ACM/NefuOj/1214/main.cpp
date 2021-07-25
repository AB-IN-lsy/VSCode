#include <bits/stdc++.h>
using namespace std;
struct sa
{
    int x;
    int y;
    int steps;
};
char a[1005][1005];
int m, n, ans = 0xfffffff;
int x2[] = {-1, 0, 1, 0};
int y2[] = {0, 1, 0, -1};
queue<sa>ming;
queue<sa>fire;
void f()
{
    int cur=fire.size();
    while(cur--){
        sa tmp = fire.front();
        fire.pop();
        for (int i=0;i<4;i++)
        {
            int x3=tmp.x+x2[i];
            int y3=tmp.y+y2[i];
            if (x3>=1&&x3<=m&&y3>=1&&y3<=n&&a[x3][y3]=='.')
            {
                a[x3][y3] = 'F';
                fire.push({x3,y3,tmp.steps});
            }
        }
    }
}
void bfs()
{
    while (!ming.empty()){
        int cur=ming.size();
        f();
        while (cur--){
            sa tmp = ming.front();
            ming.pop();
            if ((tmp.x==1||tmp.x==m||tmp.y==1||tmp.y==n)){
                ans = min(tmp.steps,ans);
                break;
            }
            for (int i=0;i<4;i++){
                int x3=tmp.x+x2[i];
                int y3=tmp.y+y2[i];
                if (x3>=1&&x3<=m&&y3>=1&&y3<=n&&a[x3][y3]=='.'){
                    a[x3][y3] = 'J';
                    ming.push({x3,y3,tmp.steps+1});
                }
            }
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while (t--){
        ans = 0xfffffff;
        memset(a,0,sizeof(a));
        while (!ming.empty()){
            ming.pop();
        }
        while (!fire.empty()){
            fire.pop();
        }
        cin>>m>>n;
        for (int i=1;i<=m;i++){
            for (int j=1;j<=n;j++){
                cin >> a[i][j];
                if (a[i][j] == 'J'){
                    ming.push({i, j, 0});
                }
                else if (a[i][j] == 'F'){
                    fire.push({i, j, 0});
                }
            }
        }
        bfs();
        if (ans!=0xfffffff){
            cout <<ans+1<< endl;
        }
        else{
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
