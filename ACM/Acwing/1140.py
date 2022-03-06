'''
Author: NEFU AB-IN
Date: 2022-03-03 20:43:36
FilePath: \ACM\Acwing\1140.py
LastEditTime: 2022-03-03 20:43:37
'''
N = 110


class Edge():
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w

    def __lt__(self, t):
        return self.w < t.w


g = [[0] * N for _ in range(N)]
fa = [i for i in range(N)]


def find(x):
    if fa[x] != x:
        fa[x] = find(fa[x])
    return fa[x]


n = int(input())
for i in range(1, n + 1):
    g[i][1:] = map(int, input().split())
lst = []
for i in range(1, n + 1):
    for j in range(1, n + 1):
        lst.append(Edge(i, j, g[i][j]))

lst.sort()
res, cnt = 0, 0
for i in range(len(lst)):
    u, v, w = lst[i].u, lst[i].v, lst[i].w
    u = find(u)
    v = find(v)
    if u != v:
        fa[u] = v
        cnt += 1
        res += w

print(res)
