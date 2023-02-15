'''
Author: NEFU AB-IN
Date: 2022-03-10 15:25:23
FilePath: \ACM\Acwing\198.py
LastEditTime: 2022-03-10 16:55:56
'''

import sys

sys.setrecursionlimit(int(2e9))

ps = [0, 2, 3, 5, 7, 11, 13, 17, 19, 23]
maxn = 0  #最多约数数量
ans = 0  #答案


def dfs(u, prod, last, res):  #这个素因子的下标、乘积、上一个素因子的幂、因子个数
    global ans, maxn
    if res > maxn or (res == maxn and prod < ans):
        ans = prod
        maxn = res
    if u == 9:
        return
    for i in range(1, last + 1):
        if prod * ps[u] > n:
            break
        prod *= ps[u]
        dfs(u + 1, prod, i, res * (i + 1))


n = int(input())
dfs(1, 1, 30, 1)

print(ans)