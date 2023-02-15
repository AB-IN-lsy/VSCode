'''
Author: NEFU AB-IN
Date: 2022-03-21 19:53:58
FilePath: \ACM\Acwing\95.py
LastEditTime: 2022-03-21 20:33:08
'''
from copy import deepcopy

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]


def turn(x, y):
    g[x][y] ^= 1
    for id in range(4):
        idx = x + dx[id]
        idy = y + dy[id]
        if idx >= 0 and idx < 5 and idy >= 0 and idy < 5:
            g[idx][idy] ^= 1


n = int(input())
for _ in range(n):
    g = []
    for i in range(5):
        g.append(list(map(int, input())))

    backup = deepcopy(g)
    minn = int(1e18)
    for op in range(1 << 5):
        if op == 16:
            k = 1
        flag, ans = 0, 0
        g = deepcopy(backup)
        for j in range(5):
            if op & 1 << j:
                ans += 1
                turn(0, j)

        for i in range(4):
            for j in range(5):
                if g[i][j] == 0:
                    turn(i + 1, j)
                    ans += 1
        for j in range(5):
            if g[4][j] == 0:
                flag = 1
                break
        if flag == 0:
            minn = min(minn, ans)
    if minn == int(1e18):
        print(-1)
    else:
        print(minn)
    if _ < n - 1:
        b = input()