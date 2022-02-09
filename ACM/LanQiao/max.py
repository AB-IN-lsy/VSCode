'''
Author: NEFU AB-IN
Date: 2022-02-09 15:23:50
FilePath: \ACM\LanQiao\max.py
LastEditTime: 2022-02-09 16:10:36
'''
ls = lambda x: x << 1
rs = lambda x: x << 1 | 1

INF = int(2e9)


class Node(object):
    def __init__(self, l, r):
        self.l = l
        self.r = r
        self.x = -INF


N = int(2e5 + 10)
tr = [Node(0, 0) for _ in range(N << 2)]


def pushup(p):
    tr[p].x = max(tr[ls(p)].x, tr[rs(p)].x)


def build(p, l, r):
    tr[p] = Node(l, r)
    if l == r:
        return
    mid = l + r >> 1
    build(ls(p), l, mid)
    build(rs(p), mid + 1, r)


def update(p, k, v):
    if tr[p].l == k and tr[p].r == k:
        tr[p].x = v
        return
    mid = tr[p].l + tr[p].r >> 1
    if k <= mid:
        update(ls(p), k, v)
    if k > mid:
        update(rs(p), k, v)
    pushup(p)


def query(p, l, r):
    res = -INF
    if l <= tr[p].l and tr[p].r <= r:
        return tr[p].x
    mid = tr[p].l + tr[p].r >> 1
    if l <= mid:
        res = max(res, query(ls(p), l, r))
    if r > mid:
        res = max(res, query(rs(p), l, r))
    return res


n, d = map(int, input().split())

t = 0
tot = 0
build(1, 1, N)
for i in range(n):
    op, n = input().split()
    n = int(n)
    if op == 'A':
        n = (n + t) % d
        tot += 1
        update(1, tot, n)
    else:
        t = query(1, tot - n + 1, tot)
        print(t)