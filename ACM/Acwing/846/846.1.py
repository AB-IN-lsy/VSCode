'''
Author: NEFU AB-IN
Date: 2022-03-04 22:26:35
FilePath: \ACM\Acwing\846.1.py
LastEditTime: 2022-03-04 22:27:42
'''

N = int(1e5 + 10)
g = [[] for _ in range(N)]
ans = N


def dfs(u, fa):
    global ans
    cnt = 1
    res = 0
    for v in g[u]:
        if v == fa:
            continue
        s = dfs(v, u)
        res = max(res, s)
        cnt += s
    res = max(res, n - cnt)
    ans = min(ans, res)
    return cnt


n = int(input())
for i in range(n - 1):
    a, b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)

dfs(1, 0)
print(ans)