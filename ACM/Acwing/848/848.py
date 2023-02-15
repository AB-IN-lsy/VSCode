'''
Author: NEFU AB-IN
Date: 2022-03-02 21:20:54
FilePath: \ACM\Acwing\848.py
LastEditTime: 2022-03-02 22:15:35
'''
from collections import deque

N = int(1e5 + 10)

g = [[] for _ in range(N)]
st = [0] * N
deg = [0] * N  #入度
res = []
q = deque()

n, m = map(int, input().split())
for i in range(m):
    a, b = map(int, input().split())
    g[a].append(b)
    deg[b] += 1

for i in range(1, n + 1):
    if deg[i] == 0:
        q.appendleft(i)

while q:
    t = q.pop()
    for j in g[t]:
        deg[j] -= 1
        if deg[j] == 0:
            q.appendleft(j)
    res.append(t)

if len(res) == n:
    print(" ".join(map(str, res)))
else:
    print(-1)
