'''
Author: NEFU AB-IN
Date: 2021-09-28 23:22:27
FilePath: \ACM\CF\2021.9.28.div3\b.py
LastEditTime: 2021-09-28 23:30:35
'''
import math


def solve():
    n = int(input())
    l = list(map(int, input().split()))
    print(n)
    for i in range(n):
        id = l.index(min(l))
        print(f"{i + 1} {n} {id}")
        l = (l[id:] + l[:id])[1:]


for _ in range(int(input())):
    solve()