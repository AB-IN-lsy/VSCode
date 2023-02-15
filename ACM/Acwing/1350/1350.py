'''
Author: NEFU AB-IN
Date: 2022-05-15 21:32:26
FilePath: \ACM\Acwing\1350.py
LastEditTime: 2022-05-15 21:42:37
'''


def single():
    res = 1
    for i in range(3):
        res *= min(n, 5)
    return res


def both():
    if n <= 5:
        return n * n * n
    res = 1
    for i in range(3):
        d = abs(a[i] - b[i])
        res *= max(0, 5 - d) + max(0, 5 - (n - d))
    return res


n = int(input())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

print(single() * 2 - both())
