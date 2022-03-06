'''
Author: NEFU AB-IN
Date: 2022-03-03 12:41:05
FilePath: \ACM\Acwing\852.py
LastEditTime: 2022-03-03 13:07:39
'''

from collections import deque

N = int(1e5 + 10)
INF = int(2e9)
st, dist, cnt = [0] * N, [INF] * N, [0] * N
g = [[] for _ in range(N)]
q = deque()


def spfa():
    for i in range(1, n + 1):
        q.appendleft(i)
        st[i] = 1
    while q:
        u = q.pop()
        st[u] = 0
        for v, w in g[u]:
            if dist[v] > dist[u] + w:
                dist[v] = dist[u] + w
                cnt[v] = cnt[u] + 1
                if cnt[v] >= n:
                    return True
                if st[v] == 0:
                    q.appendleft(v)
    return False


n, m = map(int, input().split())
for i in range(m):
    x, y, z = map(int, input().split())
    g[x].append([y, z])
if spfa():
    print("Yes")
else:
    print("No")