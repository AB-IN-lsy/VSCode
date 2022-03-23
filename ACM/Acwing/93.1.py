'''
Author: NEFU AB-IN
Date: 2022-03-21 21:11:14
FilePath: \ACM\Acwing\93.1.py
LastEditTime: 2022-03-21 21:11:14
'''
N = 50
st, path = [0] * N, [0] * N


def dfs(u):
    if u > m:
        for i in range(1, m + 1):
            print(path[i], end=" ")
        print()
        return
    for i in range(1, n + 1):
        if st[i] == 0 and (u == 1 or i > path[u - 1]):
            st[i] = 1
            path[u] = i
            dfs(u + 1)
            st[i] = 0


n, m = map(int, input().split())
dfs(1)
