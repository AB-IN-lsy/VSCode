'''
Author: NEFU AB-IN
Date: 2022-03-02 20:23:50
FilePath: \ACM\Acwing\847.py
LastEditTime: 2022-03-02 20:33:26
'''

from collections import deque

N = int(1e5 + 10)
g = [[] for _ in range(N)]
st = [0] * N


def bfs(s):
    q = deque()
    q.appendleft([s, 0])
    st[s] = 1
    while q:
        t = q.pop()
        u, cnt = t
        if u == n:
            return cnt
        for j in g[u]:
            if st[j] == 0:
                q.appendleft([j, cnt + 1])
                st[j] = 1
    return -1


n, m = map(int, input().split())
for i in range(m):
    a, b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)

print(bfs(1))