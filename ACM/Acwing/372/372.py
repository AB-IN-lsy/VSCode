'''
Author: NEFU AB-IN
Date: 2022-03-05 12:00:27
FilePath: \ACM\Acwing\372.py
LastEditTime: 2022-03-05 14:55:10
'''
N = 11000
g = [[] for _ in range(N)]
gg = [0] * N
st, match = [0] * N, [0] * N


def find(u):
    for v in g[u]:
        if st[v] == 0:
            st[v] = 1
            if match[v] == 0 or find(match[v]):
                match[v] = u
                return True
    return False


n, t = map(int, input().split())
for i in range(t):
    x, y = map(int, input().split())
    gg[x * n + y] = 1

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if gg[i * n + j] and (i + j) % 2 == 0:  #偶数的不要
            continue
        for id in range(4):
            x = i + dx[id]
            y = j + dy[id]
            if x >= 1 and x <= n and y >= 1 or y <= n and not gg[x * n + y]:
                g[i * n + j].append(x * n + y)

res = 0
for i in range(1, n + 1):
    for j in range(1, n + 1):
        if ((i + j) & 1) and not gg[i * n + j]:
            st = [0] * N
            if find(i * n + j):
                res += 1
print(res)