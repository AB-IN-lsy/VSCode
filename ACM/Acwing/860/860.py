'''
Author: NEFU AB-IN
Date: 2022-03-04 15:38:45
FilePath: \Acwing\860\860.py
LastEditTime: 2023-03-31 15:34:41
'''
import sys

sys.setrecursionlimit(1000000000)
N = int(1e5 + 10)
g = [[] for _ in range(N)]
st = [0] * N


def dfs(u, c):
    st[u] = c
    for v in g[u]:
        if st[v] == 0:
            if not dfs(v, 3 - c):
                return False
        elif st[v] == c:
            return False
    return True


n, m = map(int, input().split())
for i in range(m):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)

flag = 1
for i in range(n):
    if st[i] == 0:
        if not dfs(i, 1):
            flag = 0
            break
if flag:
    print("Yes")
else:
    print("No")
