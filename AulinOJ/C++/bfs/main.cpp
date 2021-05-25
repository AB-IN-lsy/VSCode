#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e7 + 7;
char mp[55][55];
bool vis[55][55];
struct NODE {
    int x, y, val;
    NODE(int x, int y, int v) :x(x), y(y), val(v) {}
}S(0, 0, 0), E(0, 0, 0);
int dx[] = { 0,0,1,-1 ,1,1,-1,-1 };
int dy[] = { 1,-1,0,0 ,1,-1,1,-1 };

int N, M;
bool judge(int x, int y) {
    if (x < 0 || y < 0 || x >= N || y >= M) return false;
    for (int i = 0; i < 8; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (mp[nx][ny] == '*')  return false;
    }
    return !vis[x][y];
}
int bfs() {
    queue<NODE>q;
    S.val = 0;
    q.push(S);
    vis[S.x][S.y] = true;
    while (!q.empty()) {
        NODE now = q.front();
        q.pop();
        if (mp[now.x][now.y] == 'E')
            return now.val;
        for (int i = 0; i < 4; ++i) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];
            if (judge(nx, ny)) {
                q.push(NODE(nx, ny, now.val + 1));
                vis[nx][ny] = true;
            }
        }
    }
    return -1;
}

int main() {
    std::ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while (cin >> N >> M) {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                cin >> mp[i][j];
                if (mp[i][j] == 'S')
                    S.x = i, S.y = j;
                else if (mp[i][j])
                    E.x = i, E.y = j;
            }
        }
        int ans = bfs();
        if (ans == -1)
            cout << "Impossible" << endl;
        else
            cout << ans << endl;

    }
}
