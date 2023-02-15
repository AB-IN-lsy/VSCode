'''
Author: NEFU AB-IN
Date: 2022-01-28 13:00:59
FilePath: \ACM\Acwing\2019.py
LastEditTime: 2022-01-29 18:53:22
'''

from collections import deque

N = 1010
INF = int(2e9)
g = [[0 for _ in range(N)] for _ in range(N)]
dist = [[INF for _ in range(N)] for _ in range(N)]
st = [[0 for _ in range(N)] for _ in range(N)]

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
#上右下左


def bfs(sx, sy):
    q = deque()
    q.append([sx, sy])
    dist[sx][sy] = 0

    while len(q):
        t = q.pop()
        if st[t[0]][t[1]]:  #出队去重
            continue
        st[t[0]][t[1]] = 1

        if t[0] == 0 and t[1] == 0:  #起点已经走完了
            break

        for i in range(4):
            x = t[0] + dx[i]
            y = t[1] + dy[i]
            if x >= 0 and x < N and y >= 0 and y < N:
                w = 0
                if g[x][y]:
                    w = 1
                if dist[x][y] > dist[t[0]][t[1]] + w:
                    dist[x][y] = dist[t[0]][t[1]] + w
                    if w == 0:
                        q.append([x, y])  #加到队头
                    else:
                        q.appendleft([x, y])  #加到队尾
    return dist[0][0]


if __name__ == "__main__":
    n, sx, sy = map(int, input().split())
    for _ in range(n):
        x, y = map(int, input().split())
        # 障碍为1
        g[x][y] = 1
    print(bfs(sx, sy))
