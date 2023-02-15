'''
Author: NEFU AB-IN
Date: 2022-03-01 20:43:01
FilePath: \ACM\Acwing\175.py
LastEditTime: 2022-03-01 22:41:09
'''
from collections import deque

N = 550
q = deque()
INF = int(2e9)


def bfs(x, y):
    q.appendleft([1, 1])
    dist[x][y] = 0
    while q:
        t = q.popleft()
        x, y = t[0], t[1]
        if x == r + 1 and y == c + 1:
            return dist[x][y]
        if st[x][y]:
            continue
        st[x][y] = 1
        # 格子的偏移量
        dx = [-1, -1, 1, 1]
        dy = [-1, 1, 1, -1]  #左上，右上，右下，左下
        # 线的偏移量，每个线都在一个格子里，以它左上角的坐标作为坐标
        idx = [-1, -1, 0, 0]
        idy = [-1, 0, 0, -1]
        s = "\\/\\/"
        for i in range(4):
            x1 = x + dx[i]
            y1 = y + dy[i]
            if x1 >= 1 and x1 <= r + 1 and y1 >= 1 and y1 <= c + 1:
                w = 0
                x2 = x + idx[i]
                y2 = y + idy[i]
                if g[x2][y2] != s[i]:  #如果不和规定的相同，那么路程为1
                    w = 1
                if dist[x1][y1] > dist[x][y] + w:
                    dist[x1][y1] = dist[x][y] + w
                    if w:
                        q.append([x1, y1])
                    else:
                        q.appendleft([x1, y1])
    return -1


t = int(input())
while t:
    t -= 1
    g = [[0] * N for _ in range(N)]
    st = [[0] * N for _ in range(N)]
    dist = [[INF] * N for _ in range(N)]
    q.clear()
    r, c = map(int, input().split())
    for i in range(1, r + 1):
        g[i][1:] = list(input())
    res = bfs(1, 1)
    if res == -1:
        print("NO SOLUTION")
    else:
        print(res)