'''
Author: NEFU AB-IN
Date: 2022-01-12 21:51:06
FilePath: \ACM\Acwing\1978.py
LastEditTime: 2022-01-13 22:18:30
'''
INF = float('inf')
lst = [0]


class Line(object):
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def __lt__(self, t):
        if self.a != t.a:
            return self.a < t.a
        return self.b < t.b


def solve():
    n = int(input())
    for _ in range(n):
        a, b = map(int, input().split())
        lst.append(Line(a, b))
    lst[1:] = sorted(lst[1:])
    smax = [0] * (n + 2)
    smin = [0] * (n + 2)

    smax[0] = -INF
    smin[n + 1] = INF

    for i in range(1, n + 1):
        smax[i] = max(smax[i - 1], lst[i].b)
    for i in range(n, 0, -1):
        smin[i] = min(smin[i + 1], lst[i].b)

    res = 0
    for i in range(1, n + 1):
        if lst[i].b > smax[i - 1] and lst[i].b < smin[i + 1]:
            res += 1
    print(res)


if __name__ == "__main__":
    solve()