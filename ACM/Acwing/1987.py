'''
Author: NEFU AB-IN
Date: 2022-01-11 14:11:42
FilePath: \ACM\Acwing\1987.py
LastEditTime: 2022-01-11 17:05:32
'''

from collections import Counter

d = Counter()


def solve():
    n = int(input())
    pos = 0  #初始位置为0
    for _ in range(n):
        x, op = input().split()
        x = int(x)
        if op == 'L':
            d[pos - x] += 1
            d[pos] -= 1
            pos -= x
        else:
            d[pos] += 1
            d[pos + x] -= 1
            pos += x
    last, cnt, res = 0, 0, 0
    for x in sorted(d.keys()):
        if cnt >= 2:
            res += (x - last)
        cnt += d[x]
        last = x
    print(res)


if __name__ == "__main__":
    solve()