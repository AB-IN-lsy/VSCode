'''
Author: NEFU AB-IN
Date: 2022-03-21 15:26:33
FilePath: \ACM\Acwing\94.py
LastEditTime: 2022-03-21 15:26:33
'''


def dfs(u):
    if u > n:
        for i in range(1, n + 1):
            print(path[i], end=" ")
        print()
        return
    for i in range(1, n + 1):
        if st[i] == 0:
            st[i] = 1
            path[u] = i
            dfs(u + 1)
            st[i] = 0


n = int(input())
st = [0] * (n + 1)
path = [0] * (n + 1)
dfs(1)
