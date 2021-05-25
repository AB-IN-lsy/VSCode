'''
Description: https://blog.csdn.net/qq_45859188
Author: NEFU AB_IN
version: 1.0
Date: 2021-04-10 21:01:03
LastEditors: NEFU AB_IN
LastEditTime: 2021-04-15 16:52:16
'''
def dfs(x, y, step):
    lst[x][y] = 1
    if x == xg and y == yg:
        print(step)
        return
    for i in range(4):
        x1 = x + dire[i][0]
        y1 = y + dire[i][1]
        if(x1 >= 1 and x1 <= n and y1 >= 1 and y1 <= n and lst[x1][y1] == 0):
            dfs(x1, y1, step + 1)

dire = [[-1, 0], [0, -1], [1, 0], [0, 1]]
n = int(input())
lst = [[0]]
for _ in range(n):
    tmp = list(map(int, list(input())))
    tmp.insert(0, 0)
    lst.append(tmp)
xt, yt, xg, yg = map(int, input().split())
dfs(xt, yt, 0)
