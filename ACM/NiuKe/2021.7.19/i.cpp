/*
 * @Description: file content
 * @Author: NEFU AB_IN
 * @version: 1.0
 * @Date: 2021-07-21 18:04:20
 * @LastEditors: NEFU AB_IN
 * @LastEditTime: 2021-07-21 21:36:33
 */
#include<bits/stdc++.h>
using namespace std;
#define LL                          long long
#define ULL                         unsigned long long
#define SZ(X)                       ((int)(X).size())
#define IOS                         ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
typedef pair<int , int>             PII;

struct sa{
    int x1, y1, x2, y2;
    string s;
    sa(int x1, int y1, int x2, int y2, string s  = ""): x1(x1), x2(x2), y1(y1), y2(y2), s(s) {};
    sa add(int dx1, int dy1, int dx2, int dy2){
        sa newst(x1 + dx1, y1 + dy1, x2 + dx2, y2 + dy2, s);
        return newst;
    }
};

int vis[25][25][25][25]; // status

int a1[25][25], a2[25][25]; // two distinct graph

const int dir1[4][2] = { {1, 0}, {0, -1}, {0, 1}, {-1, 0} }; //下左右上 D L R U
const int dir2[4][2] = { {1, 0}, {0, 1}, {0, -1}, {-1, 0} }; //下右左上 D R L U
const char step_n_c[] = {'D', 'L', 'R', 'U'};
map <char, int> step_c_n = {{'D', 0}, {'L', 1}, {'R', 2}, {'U', 3}};

string bfs(){
    queue <sa> q;
    vis[20][20][20][1] = 1;
    q.push(sa(20, 20, 20, 1));
    while(q.size()){
        sa t = q.front();
        q.pop();
        if(t.x1 == 1 && t.y1 == 20 && t.x2 == 1 && t.y2 == 1) {
            return t.s;
        }
        for(int i = 0; i < 4; i ++){
            // init new sa variable
            sa now = t.add(dir1[i][0], dir1[i][1], dir2[i][0], dir2[i][1]);
            if(!a1[now.x1][now.y1] || now.x1 < 1 || now.y1 < 1 || now.x1 > 20 || now.y1 > 20){
                now = now.add(-dir1[i][0], -dir1[i][1], 0, 0);
            }// If its way is blocked, or it reaches the border, then this movement is omitted.
            if(!a2[now.x2][now.y2] || now.x2 < 1 || now.y2 < 1 || now.x2 > 20 || now.y2 > 20){
                now = now.add(0, 0, -dir2[i][0], -dir2[i][1]);
            }
            if(!vis[now.x1][now.y1][now.x2][now.y2]){
                now.s += step_n_c[i];
                vis[now.x1][now.y1][now.x2][now.y2] = 1;
                //cout << now.x1 << " " << now.y1 << " " << now.x2 << " " << now.y2 << endl;
                q.push(now);
            }
        }
    }
    return "None";
}

void solve(string ans){
    //  sign path
    int x1 = 20, y1 = 20, x2 = 20, y2 = 1;
    a1[x1][y1] = 2, a2[x2][y2] = 2;
    for(auto c : ans){
        int id = step_c_n[c];
        if(a1[x1 + dir1[id][0]][y1 + dir1[id][1]]) { // not block, so sign 2
            x1 = x1 + dir1[id][0];
            y1 = y1 + dir1[id][1];
            a1[x1][y1] = 2;
        }
        if(a2[x2 + dir2[id][0]][y2 + dir2[id][1]]) {
            x2 = x2 + dir2[id][0];
            y2 = y2 + dir2[id][1];
            a2[x2][y2] = 2;
        }
    }
    //  print
    for(int i = 1; i <= 20; i++){
        for(int j = 1; j <= 20; j++){
            if(a1[i][j] == 1) putchar('.');
            else if(a1[i][j] == 0) putchar('#');
            else if(a1[i][j] == 2) putchar('A');
        }
        putchar(' ');
        for(int j = 1; j <= 20; j++){
            if(a2[i][j] == 1) putchar('.');
            else if(a2[i][j] == 0) putchar('#');
            else if(a2[i][j] == 2) putchar('A');
        }
        putchar('\n');
    }
}


int main()
{
    char x;
    for(int i = 1; i <= 20; i ++){
        for(int j = 1; j <= 20; j ++){
            scanf("%c", &x);
            a1[i][j] = x == '.' ? 1 : 0; // 1 represent there is a path, so that
                                         // donot worry the border
        }
        scanf("%c", &x);
        for(int j = 1; j <= 20; j ++){
            scanf("%c", &x);
            a2[i][j] = x == '.' ? 1 : 0; 
        }
        getchar();
    }

    string ans = bfs();
    printf("%d\n", ans.size());
    cout << ans << endl;
    solve(ans);    
    return 0;
}
