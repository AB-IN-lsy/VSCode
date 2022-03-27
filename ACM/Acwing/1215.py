'''
Author: NEFU AB-IN
Date: 2022-03-27 08:57:51
FilePath: \ACM\Acwing\1215.py
LastEditTime: 2022-03-27 08:57:52
'''
N = int(1e6 + 10)
tr, a, cnt = [0] * N, [0] * N, [0] * N


def lowbit(x):
    return x & -x


def add(x, d):
    while x < N:
        tr[x] += d
        x += lowbit(x)


def query(x):
    res = 0
    while x:
        res += tr[x]
        x -= lowbit(x)
    return res


n = int(input())
a[1:] = list(map(int, input().split()))

for i in range(1, n + 1):
    a[i] += 1

for i in range(1, n + 1):
    add(a[i], 1)
    cnt[i] += (i - query(a[i]))

tr = [0] * N

for i in range(n, 0, -1):
    add(a[i], 1)
    cnt[i] += query(a[i] - 1)

res = 0
for i in range(1, n + 1):
    res += (cnt[i] * (cnt[i] + 1) // 2)

print(res)
