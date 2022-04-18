'''
Author: NEFU AB-IN
Date: 2022-04-04 17:11:22
FilePath: \ACM\Acwing\1303.1.py
LastEditTime: 2022-04-04 17:17:12
'''


def dfs(x):
    if x == 0:
        return [0, 1]
    f = dfs(x >> 1)
    f1 = (f[0] * (2 * f[1] - f[0])) % m
    f2 = (f[0]**2 + f[1]**2) % m
    if x & 1:
        return [f2, (f1 + f2) % m]
    return [f1, f2]


n, m = map(int, input().split())
print(dfs(n + 2)[0] - 1)