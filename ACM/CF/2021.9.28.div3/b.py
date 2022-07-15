'''
Author: NEFU AB-IN
Date: 2021-09-28 23:22:27
FilePath: \ACM\CF\2021.9.28.div3\b.py
LastEditTime: 2021-09-28 23:35:54
'''
import math


def solve():
    n = int(input())
    l = list(map(int, input().split()))
    ll = []
    for i in range(n):
        id = l.index(min(l))
        if id != 0:
            ll.append([i + 1, n, id])
        l = (l[id:] + l[:id])[1:]
    print(len(ll))
    for i in ll:
        print(f"{i[0]} {i[1]} {i[2]}")


for _ in range(int(input())):
    solve()