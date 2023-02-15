'''
Author: NEFU AB-IN
Date: 2022-03-03 19:43:34
FilePath: \ACM\Acwing\859.py
LastEditTime: 2022-03-03 19:57:59
'''
N = int(2e5 + 100)
fa = [i for i in range(N)]


def find(x):
    if fa[x] != x:
        fa[x] = find(fa[x])
    return fa[x]


class Edge(object):
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w

    def __lt__(self, t):
        return self.w < t.w


lst = []
n, m = map(int, input().split())
for i in range(m):
    x, y, z = map(int, input().split())
    lst.append(Edge(x, y, z))
lst.sort()

res, cnt = 0, 0
for i in range(m):
    u, v, w = lst[i].u, lst[i].v, lst[i].w
    u = find(u)
    v = find(v)
    if u != v:
        fa[u] = v
        cnt += 1
        res += w

if cnt < n - 1:
    print("impossible")
else:
    print(res)