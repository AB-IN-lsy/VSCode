'''
Author: NEFU AB-IN
Date: 2022-01-19 19:36:30
FilePath: \ACM\Acwing\1922.1.py
LastEditTime: 2022-01-19 19:40:57
'''

from collections import Counter

d = Counter()

if __name__ == "__main__":
    n, k = map(int, input().split())
    for _ in range(n):
        g, x = map(int, input().split())
        d[x - k] += g
        d[x + k + 1] -= g
    res, sum = 0, 0
    for i in sorted(d.keys()):
        sum += d[i]
        res = max(res, sum)
    print(res)