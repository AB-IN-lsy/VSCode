'''
Author: NEFU AB-IN
Date: 2022-03-28 21:46:17
FilePath: \ACM\Acwing\1113.py
LastEditTime: 2022-03-28 21:46:17
'''
ans = 0


def dfs(sx, sy):
    global ans
    st[sx][sy] = 1
    ans += 1
    for i in range(4):
        x = sx + dx[i]
        y = sy + dy[i]
        if x >= 0 and x < n and y >= 0 and y < m and st[x][y] == 0 and g[x][
                y] == '.':
            dfs(x, y)


while True:
    m, n = map(int, input().split())
    if n + m == 0:
        break
    g = []
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]
    st = [[0] * m for _ in range(n)]
    for i in range(n):
        g.append(list(input()))
    for i in range(n):
        for j in range(m):
            if g[i][j] == '@':
                sx, sy = i, j
                break
    dfs(sx, sy)
    print(ans)
    ans = 0