'''
Author: NEFU AB-IN
Date: 2022-02-16 09:44:56
FilePath: \ACM\Acwing\1660.py
LastEditTime: 2022-02-16 10:38:22
'''
from bisect import bisect_left

INF = int(2e9)
a = []  #装1
b = []  #装0

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        x, op = map(int, input().split())
        if op == 1:
            a.append(x)
        else:
            b.append(x)

    a.sort()
    b.sort()
    dis = INF
    a = [-INF, *a, INF]
    for i in range(len(b)):
        id = bisect_left(a, b[i]) - 1
        dis = min(dis, min(a[id + 1] - b[i], b[i] - a[id]))
    res = 0
    i, j = 1, 1
    n = len(a) - 1
    while i < n and j + 1 < n:
        j = i + 1
        while j < n and a[j] - a[i] < dis:
            j += 1
            i += 1
        res += 1
        i += 1

    if a[n - 1] - a[n - 2] >= dis:
        res += 1
    print(res)