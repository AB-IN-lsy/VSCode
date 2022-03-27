'''
Author: NEFU AB-IN
Date: 2022-03-26 17:50:51
FilePath: \ACM\Acwing\1264.1.py
LastEditTime: 2022-03-27 08:57:58
'''
import numpy


class Node():
    def __init__(self, l, r):
        self.l = l
        self.r = r
        self.sum = 0


N = int(1e5 + 10)
tr = numpy.array([Node(0, 0) for _ in range(N << 2)])
a = [0] * N


def pushup(p):
    tr[p].sum = tr[p << 1].sum + tr[p << 1 | 1].sum


def build(p, l, r):
    tr[p] = Node(l, r)
    if l == r:
        tr[p].sum = a[l]
        return
    mid = l + r >> 1
    build(p << 1, l, mid)
    build(p << 1 | 1, mid + 1, r)
    pushup(p)


def modify(p, k, v):
    if k <= tr[p].l and tr[p].r <= k:
        tr[p].sum += v
        return
    mid = tr[p].l + tr[p].r >> 1
    if k <= mid: modify(p << 1, k, v)
    if k > mid: modify(p << 1 | 1, k, v)
    pushup(p)


def query(p, l, r):
    sum = 0
    if l <= tr[p].l and tr[p].r <= r:
        return tr[p].sum
    mid = tr[p].l + tr[p].r >> 1
    if l <= mid: sum += query(p << 1, l, r)
    if r > mid: sum += query(p << 1 | 1, l, r)
    return sum


n, m = map(int, input().split())
a[1:] = list(map(int, input().split()))
build(1, 1, n)
for i in range(m):
    k, x, y = map(int, input().split())
    if k:
        modify(1, x, y)
    else:
        print(query(1, x, y))