'''
Author: NEFU AB-IN
Date: 2022-02-23 16:11:57
FilePath: \ACM\Acwing\802.py
LastEditTime: 2022-02-23 17:12:41
'''
N = int(1e5 + 100)
b = [0] * N
a = []
xs = []
INF = int(2e9)


def findl(x):
    l, r = 0, len(xs) - 1
    while l < r:
        mid = l + r >> 1
        if xs[mid] >= x:
            r = mid
        else:
            l = mid + 1
    return r


def findr(x):
    l, r = 0, len(xs) - 1
    while l < r:
        mid = l + r + 1 >> 1
        if xs[mid] <= x:
            l = mid
        else:
            r = mid - 1
    return r


n, m = map(int, input().split())
for i in range(n):
    x, c = map(int, input().split())
    a.append([x, c])
    xs.append(x)

xs = [-INF, *xs, INF]
xs = list(set(xs))
xs.sort()

for i in range(len(a)):
    t = a[i][0]
    L = findl(t)
    b[L] += a[i][1]

for i in range(1, len(b)):
    b[i] += b[i - 1]

for i in range(m):
    l, r = map(int, input().split())
    L = findl(l)
    R = findr(r)
    print(L, R)
    print(b[R] - b[L - 1])
