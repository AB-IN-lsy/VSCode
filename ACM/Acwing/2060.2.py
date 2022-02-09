'''
Author: NEFU AB-IN
Date: 2022-01-29 18:26:56
FilePath: \ACM\Acwing\2060.2.py
LastEditTime: 2022-01-29 19:12:51
'''

from collections import deque

N = 55
INF = int(2e9)
g = []
dist = [[INF for _ in range(N)] for _ in range(N)]
st = [[0 for _ in range(N)] for _ in range(N)]

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def bfs(sx, sy):
    global n, m
    q = deque()
    q.append([sx, sy])
    dist[sx][sy] = 0

    while len(q):
        t = q.pop()
        if st[t[0]][t[1]]:
            continue
        st[t[0]][t[1]] = 1

        if g[t[0]][t[1]] == 'X' and dist[t[0]][t[1]] > 0:
            return dist[t[0]][t[1]]

        for i in range(4):
            x = t[0] + dx[i]
            y = t[1] + dy[i]
            if x >= 0 and x < n and y >= 0 and y < m:
                w = 0
                if g[x][y] == '.':
                    w = 1
                if dist[x][y] > dist[t[0]][t[1]] + w:
                    dist[x][y] = dist[t[0]][t[1]] + w
                    if w == 0:
                        q.append([x, y])
                    else:
                        q.appendleft([x, y])


if __name__ == "__main__":
    n, m = map(int, input().split())
    for i in range(n):
        s = input()
        g.append(list(s))
    for i in range(n):
        for j in range(m):
            if g[i][j] == 'X':
                print(bfs(i, j))
                exit(0)
