'''
Author: NEFU AB-IN
Date: 2022-01-15 11:19:39
FilePath: \ACM\Acwing\1952.py
LastEditTime: 2022-01-15 14:33:57
'''
'''
可能有多个区间满足最大覆盖
区间中含有多个值
'''
from collections import Counter

INF = float('inf')
d = Counter()


def solve():
    n, x, y, z = map(int, input().split())
    for _ in range(n):
        a, b = map(int, input().split())
        d[-INF] += x
        d[a] += (y - x)
        d[b + 1] -= (y - z)
        d[INF] -= z
    res = 0
    sum = 0
    for i in sorted(d.keys()):
        sum += d[i]
        res = max(res, sum)
    print(res)


if __name__ == "__main__":
    solve()