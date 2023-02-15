'''
Author: NEFU AB-IN
Date: 2022-03-26 21:07:10
FilePath: \ACM\Acwing\1270.py
LastEditTime: 2022-03-26 21:22:17
'''
'''
Author: NEFU AB-IN
Date: 2022-03-26 17:50:51
FilePath: \ACM\Acwing\1264.1.py
LastEditTime: 2022-03-26 21:03:12
'''


class Node():
    def __init__(self):
        self.l = 0
        self.r = 0
        self.max = -1


N = int(1e5 + 10)
tr = [Node() for _ in range(N << 2)]
a = [0] * N


def pushup(p):
    tr[p].max = max(tr[p << 1].max, tr[p << 1 | 1].max)


def build(p, l, r):
    tr[p].l, tr[p].r = l, r
    if l == r:
        tr[p].max = a[l]
        return
    mid = l + r >> 1
    build(p << 1, l, mid)
    build(p << 1 | 1, mid + 1, r)
    pushup(p)


def modify(p, k, v):
    if k <= tr[p].l and tr[p].r <= k:
        tr[p].max = v
        return
    mid = tr[p].l + tr[p].r >> 1
    if k <= mid: modify(p << 1, k, v)
    if k > mid: modify(p << 1 | 1, k, v)
    pushup(p)


def query(p, l, r):
    ans = -1
    if l <= tr[p].l and tr[p].r <= r:
        return tr[p].max
    mid = tr[p].l + tr[p].r >> 1
    if l <= mid: ans = max(ans, query(p << 1, l, r))
    if r > mid: ans = max(ans, query(p << 1 | 1, l, r))
    return ans


n, m = map(int, input().split())
a[1:] = list(map(int, input().split()))
build(1, 1, n)
for i in range(m):
    x, y = map(int, input().split())
    print(query(1, x, y))