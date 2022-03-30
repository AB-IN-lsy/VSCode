'''
Author: NEFU AB-IN
Date: 2022-03-28 15:57:54
FilePath: \ACM\Acwing\1268.py
LastEditTime: 2022-03-28 16:00:44
'''
from bisect import bisect_left


class Node():
    def __init__(self, l, r):
        self.l = l
        self.r = r
        self.cnt = 0
        self.len = 0


class Seg():
    def __init__(self, x, y1, y2, k):
        self.x = x
        self.y1 = y1
        self.y2 = y2
        self.k = k

    def __lt__(self, t):
        return self.x < t.x


N = int(1e5 + 10)
tr = [Node(0, 0) for _ in range(N << 2)]
xs, seg = [], []


def find(x):
    return bisect_left(xs, x)


def pushup(p):
    if tr[p].cnt:
        tr[p].len = xs[tr[p].r + 1] - xs[tr[p].l]
    elif tr[p].l == tr[p].r:
        tr[p].len = 0
    else:
        tr[p].len = tr[p << 1].len + tr[p << 1 | 1].len


def bulid(p, l, r):
    tr[p] = Node(l, r)
    if l == r:
        return
    mid = l + r >> 1
    bulid(p << 1, l, mid)
    bulid(p << 1 | 1, mid + 1, r)


def modify(p, l, r, k):
    if l <= tr[p].l and tr[p].r <= r:
        tr[p].cnt += k
        pushup(p)
        return
    mid = tr[p].l + tr[p].r >> 1
    if l <= mid: modify(p << 1, l, r, k)
    if r > mid: modify(p << 1 | 1, l, r, k)
    pushup(p)


n = int(input())
for i in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    seg.append(Seg(x1, y1, y2, 1))
    seg.append(Seg(x2, y1, y2, -1))
    xs.append(y1), xs.append(y2)
ans = 0
seg.sort()
xs = sorted(list(set(xs)))
bulid(1, 0, N)
for i in range(2 * n):
    if i > 0:
        ans += tr[1].len * (seg[i].x - seg[i - 1].x)
    modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k)

print(ans)
