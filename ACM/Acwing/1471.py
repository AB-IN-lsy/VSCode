'''
Author: NEFU AB-IN
Date: 2022-02-11 09:35:06
FilePath: \ACM\Acwing\1471.py
LastEditTime: 2022-02-11 09:56:24
'''
import sys

sys.setrecursionlimit(10000000)

from collections import Counter

N = 150

g = [[] for _ in range(N)]
deg = [0] * N  #出度
a = []  #出度为0的点
b = Counter()  #统计每个点能被到几次


def dfs(x):
    for y in g[x]:
        b[y] += 1
        dfs(y)


if __name__ == "__main__":
    n = int(input())
    for i in range(n - 1):
        x, y = map(int, input().split())
        g[x].append(y)
        deg[x] += 1
    for i in range(1, n + 1):  #枚举每个点，看哪个度为0
        if deg[i] == 0:
            a.append(i)
    for i in range(1, n + 1):  #dfs每个点
        dfs(i)
    for i in a:
        if b[i] == n - 1:
            print(i)
            exit(0)
    print(-1)
