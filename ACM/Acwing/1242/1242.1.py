'''
Author: NEFU AB-IN
Date: 2022-04-05 18:21:40
FilePath: \ACM\Acwing\1242.1.py
LastEditTime: 2022-04-05 19:06:47
'''

N = int(1e6 + 10)
Matrix = lambda: [0] * N
lowbit = lambda x: x & -x
tr, a = Matrix(), Matrix()


def add(x, d):
    i = x
    while i < N:
        tr[i] += d
        i += lowbit(i)


def query(x):
    i, ans = x, 0
    while i:
        ans += tr[i]
        i -= lowbit(i)
    return ans


def check(l, r):
    return r - query(r) > (l - 1) - query(l - 1)


n = int(input())
a = list(map(int, input().split()))
a = [0, *a]

for i in range(1, n + 1):
    l, r = a[i], N
    while l < r:
        mid = l + r >> 1
        if check(a[i], mid):
            r = mid
        else:
            l = mid + 1
    print(r, end=" ")
    add(r, 1)