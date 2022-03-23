'''
Author: NEFU AB-IN
Date: 2022-03-22 17:49:04
FilePath: \ACM\Acwing\116.py
LastEditTime: 2022-03-22 17:55:34
'''
from copy import deepcopy

g = []


def f(x, y):
    if g[x][y] == '+':
        g[x][y] = '-'
    else:
        g[x][y] = '+'


def change(x, y):
    for i in range(4):
        f(i, y)
    for i in range(4):
        f(x, i)
    f(x, y)


for i in range(4):
    g.append(list(input()))

res = []
minn = int(2e9)

backup = deepcopy(g)

for i in range(1 << 16):
    # if i == 53261:
    #     ddd = 1
    ans, flag = [], 0
    g = deepcopy(backup)
    for j in range(16):
        if i & 1 << j:
            x, y = j // 4, j % 4
            change(x, y)
            ans.append([x, y])
    for i in range(4):
        for j in range(4):
            if g[i][j] == '+':
                flag = 1
                break
        if flag: break

    if flag == 0 and len(ans) <= minn:
        if len(ans) < minn:
            res = []
        res.append(ans)
        minn = len(ans)
for ans in res:
    print(len(ans))
    for x, y in ans:
        print(x + 1, y + 1)
