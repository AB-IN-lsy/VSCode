'''
Author: NEFU AB-IN
Date: 2022-01-18 12:50:31
FilePath: \ACM\Acwing\1934.py
LastEditTime: 2022-01-18 23:10:20
'''

import heapq

D = []
T = []

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        op, x = input().split()
        x = int(x)
        heapq.heapify(D)
        heapq.heapify(T)
        if op == 'T':
            heapq.heappush(T, x)
        else:
            heapq.heappush(D, x)
    cnt = 1
    v = 1 / cnt
    tot = 1000
    res = 0
    while len(D) and len(T):
        d = heapq.heappop(D)  # d的路程
        t = heapq.heappop(T)
        s = v * t  # t的路程
        if s > d:
            tmp = d / v
            res += tmp
            heapq.heappush(T, t - tmp)
        elif s == d:
            res += d / v
        else:
            res += t
            heapq.heappush(D, d - v * t)
        tot -= min(d, s)
        cnt += 1
        v = 1 / cnt
    while len(D):
        d = heapq.heappop(D)
        tot -= d
        res += d / v
        cnt += 1
        v = 1 / cnt
    while len(T):
        t = heapq.heappop(T)
        tot -= t * v
        res += t
        cnt += 1
        v = 1 / cnt
    print(int(res + tot / v))
