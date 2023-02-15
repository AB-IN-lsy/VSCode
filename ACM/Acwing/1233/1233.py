'''
Author: NEFU AB-IN
Date: 2022-03-29 17:23:48
FilePath: \ACM\Acwing\1223.py
LastEditTime: 2022-03-29 17:25:34
'''
N = int(1e3 + 10)
g = []
st = [[0] * N for _ in range(N)]
ans = 0
dir = [[-1, 0], [1, 0], [0, 1], [0, -1]]


def judge(x, y):
    for i in range(4):
        a = x + dir[i][0]
        b = y + dir[i][1]
        if g[a][b] == '.':
            return 0
    return 1


def dfs(sx, sy):
    global ans, flag
    st[sx][sy] = 1
    if judge(sx, sy):
        flag = 1
    for i in range(4):
        x = sx + dir[i][0]
        y = sy + dir[i][1]
        if x >= 0 and x < n and y >= 0 and y < n and g[x][y] == '#' and st[x][
                y] == 0:
            dfs(x, y)


n = int(input())
for i in range(n):
    g.append(list(input()))

for i in range(n):
    for j in range(n):
        if g[i][j] == '#' and st[i][j] == 0:
            flag = 0
            dfs(i, j)
            if flag == 0: ans += 1

print(ans)