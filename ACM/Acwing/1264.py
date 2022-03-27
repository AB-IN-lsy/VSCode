'''
Author: NEFU AB-IN
Date: 2022-03-26 16:06:33
FilePath: \ACM\Acwing\1264.py
LastEditTime: 2022-03-26 16:06:35
'''
N = int(1e5 + 10)
tr, a = [0] * N, [0] * N


def lowbit(x):
    return x & -x


def add(x, d):
    while x < N:
        tr[x] += d
        x += lowbit(x)


def query(x):
    ans = 0
    while x:
        ans += tr[x]
        x -= lowbit(x)
    return ans


n, m = map(int, input().split())
a[1:] = list(map(int, input().split()))

for i in range(1, n + 1):  #一定下标从1开始
    add(i, a[i])
for i in range(m):
    k, x, y = map(int, input().split())
    if k: add(x, y)
    else: print(query(y) - query(x - 1))