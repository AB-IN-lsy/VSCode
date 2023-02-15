'''
Author: NEFU AB-IN
Date: 2022-03-29 16:03:21
FilePath: \ACM\Acwing\1240.py
LastEditTime: 2022-03-29 16:12:05
'''
N = int(1e5 + 10)
height = 0
cnt = [0] * N


def dfs(u, c):
    global height
    if u > n:
        height = max(height, c - 1)
        return
    cnt[c] += a[u]
    dfs(u << 1, c + 1)
    dfs(u << 1 | 1, c + 1)


n = int(input())
a = list(map(int, input().split()))
a = [0, *a]

dfs(1, 1)
maxn = -int(1e20)
ans = 0
for i in range(1, height + 1):
    if cnt[i] > maxn:
        maxn = cnt[i]
        ans = i

print(ans)