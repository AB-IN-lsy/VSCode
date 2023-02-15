'''
Author: NEFU AB-IN
Date: 2022-02-09 10:05:28
FilePath: \ACM\Acwing\1752.2.py
LastEditTime: 2022-02-09 10:22:02
'''
from collections import Counter

d = Counter()
a = []

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        l, r = map(int, input().split())
        d[l] += 1
        d[r] -= 1
        a.append((l, r))
    res = 0
    for i in range(n):
        d[a[i][0]] -= 1
        d[a[i][1]] += 1
        last, cnt, sum = 0, 0, 0
        for x in sorted(d.keys()):
            if cnt >= 1:
                sum += (x - last)
            cnt += d[x]
            last = x
        res = max(sum, res)
        d[a[i][0]] += 1
        d[a[i][1]] -= 1
    print(res)