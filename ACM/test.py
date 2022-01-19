'''
Author: NEFU AB-IN
Date: 2021-11-05 19:16:12
FilePath: \ACM\test.py
LastEditTime: 2022-01-16 00:20:04
'''

N = 20010
INF = int(2e9)
l = [0] * N
r = [0] * N
b = [0] * 2 * N
xs = []


def find(v):
    l = 0
    r = len(xs) - 1
    while l < r:
        mid = l + r >> 1
        if xs[mid] >= v: r = mid
        else: l = mid + 1
    return r


if __name__ == '__main__':
    xs.append(-INF)
    xs.append(INF)
    readline = lambda: map(int, input().split())
    n, x, y, z = readline()
    for i in range(n):
        l[i], r[i] = readline()
        xs.append(l[i])
        xs.append(r[i] + 1)
    xs = list(set(xs))
    xs.sort()
    for i in range(n):
        L = find(l[i])
        R = find(r[i] + 1)
        b[0] += x
        b[L] += y - x
        b[R] += z - y

    res = sum = 0
    for i in range(len(xs)):
        sum += b[i]
        res = max(res, sum)
    print(xs)
    print(res)
