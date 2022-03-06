'''
Author: NEFU AB-IN
Date: 2022-03-04 22:37:00
FilePath: \ACM\Acwing\860.1.py
LastEditTime: 2022-03-04 23:00:45
'''
N = int(1e5 + 10)
st = [0] * N
g = [[] for _ in range(N)]

from collections import deque


def bfs(s):
    q = deque()
    q.appendleft(s)
    st[s] = 1
    while q:
        u = q.pop()
        for v in g[u]:
            if not st[v]:
                st[v] = 3 - st[u]
                q.appendleft(v)
            elif st[v] == st[u]:
                return False
    return True


n, m = map(int, input().split())
for i in range(m):
    a, b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)

flag = 1
for i in range(1, n + 1):
    if not st[i]:
        if not bfs(i):
            flag = 0
            break

if flag == 1:
    print("Yes")
else:
    print("No")