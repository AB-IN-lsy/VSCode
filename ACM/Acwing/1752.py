'''
Author: NEFU AB-IN
Date: 2022-02-08 08:59:37
FilePath: \ACM\Acwing\1752.py
LastEditTime: 2022-02-09 11:29:37
'''

#扫描线求区间最大覆盖
#学习地址：https://ncc79601.blog.luogu.org/scan-line

ls = lambda p: p << 1
rs = lambda p: p << 1 | 1


class Node(object):
    def __init__(self, l, r) -> None:
        self.l = l
        self.r = r
        self.len = 0  # 区间内被截的长度
        self.tag = 0  # 被完全覆盖的次数


N = int(1010)
tr = [Node(0, 0) for _ in range(N << 3)]
lst = []
xs = []
L = [0 for _ in range(N)]
R = [0 for _ in range(N)]


def find(x):
    l = 0
    r = len(xs) - 1
    while l < r:
        mid = l + r >> 1
        if xs[mid] >= x:
            r = mid
        else:
            l = mid + 1
    return r


def pushup(p):
    if tr[p].tag:  #被覆盖过，这个区间是满的，覆盖长度就是这个区间的长度
        tr[p].len = (xs[tr[p].r + 1] - xs[tr[p].l])  #更新长度
    else:  #否则
        tr[p].len = tr[ls(p)].len + tr[rs(p)].len  #合并儿子信息


def build(p, l, r):
    tr[p] = Node(l, r)
    if l == r:
        return
    mid = l + r >> 1
    build(ls(p), l, mid)
    build(rs(p), mid + 1, r)
    pushup(p)


#l, r 是固定的，二分的永远是tr[p].l和tr[p].r
def update(p, l, r, d):
    if l <= tr[p].l and tr[p].r <= r:
        tr[p].tag += d
        pushup(p)
        return
    #pushdown(p)
    mid = tr[p].l + tr[p].r >> 1
    if l <= mid:
        update(ls(p), l, r, d)
    if mid < r:
        update(rs(p), l, r, d)
    pushup(p)


if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        l, r = map(int, input().split())
        xs.append(l)
        xs.append(r)
        lst.append([l, r])
    xs = list(set(xs))
    xs.sort()
    build(1, 0, len(xs) - 1)
    for i in range(n):
        L[i] = find(lst[i][0])
        R[i] = find(lst[i][1])
        update(1, L[i], R[i] - 1, 1)
    res = 0
    for i in range(n):
        update(1, L[i], R[i] - 1, -1)
        res = max(res, tr[1].len)
        update(1, L[i], R[i] - 1, 1)
    print(res)
