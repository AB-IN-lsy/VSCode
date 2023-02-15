'''
Author: NEFU AB-IN
Date: 2022-04-05 16:45:40
FilePath: \ACM\Acwing\1242.py
LastEditTime: 2022-04-05 16:45:40
'''
import sys

sys.setrecursionlimit(int(2e9))

N = int(1e6 + 10)
fa = [i for i in range(N)]


def find(x):
    if x != fa[x]:
        fa[x] = find(fa[x])
    return fa[x]


n = int(input())
a = list(map(int, input().split()))

for i in range(n):
    x = find(a[i])
    a[i] = x
    fa[x] = x + 1

for i in a:
    print(i, end=" ")
