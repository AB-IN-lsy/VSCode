'''
Author: NEFU AB-IN
Date: 2022-02-11 16:24:27
FilePath: \ACM\Acwing\844.py
LastEditTime: 2022-02-11 16:37:41
'''

from collections import deque

N = 110
g = []
vis = [[0 for _ in range(N)] for _ in range(N)]

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def bfs(x, y):
    q = deque()
    q.appendleft((x, y, 0))
    vis[x][y] = 1
    while len(q):
        t = q.pop()
        x = t[0]
        y = t[1]
        cnt = t[2]
        if x == n - 1 and y == m - 1:
            return cnt
        for i in range(4):
            a = x + dx[i]
            b = y + dy[i]
            if a >= 0 and a < n and b >= 0 and b < m and vis[a][b] == 0 and g[
                    a][b] == 0:
                q.appendleft((a, b, cnt + 1))
                vis[a][b] = 1


if __name__ == "__main__":
    n, m = map(int, input().split())
    for i in range(n):
        g.append(list(map(int, input().split())))

    print(bfs(0, 0))