'''
Author: NEFU AB-IN
Date: 2022-03-01 23:17:33
FilePath: \ACM\Acwing\842.py
LastEditTime: 2022-03-01 23:26:06
'''
N = 10
path, st = [0] * N, [0] * N


def dfs(x):
    if x == n + 1:
        for i in range(1, n + 1):
            print(path[i], end=" ")
        print()
        return
    for i in range(1, n + 1):
        if not st[i]:
            path[x] = i
            st[i] = 1
            dfs(x + 1)
            st[i] = 0


n = int(input())
dfs(1)