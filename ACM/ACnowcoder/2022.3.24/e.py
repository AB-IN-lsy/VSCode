'''
Author: NEFU AB-IN
Date: 2022-03-04 20:37:26
FilePath: \ACM\ACnowcoder\2022.3.24\e.py
LastEditTime: 2022-03-04 20:53:10
'''
N = int(1e5 + 10)
g = [[] for i in range(N)]
st = [0] * N


def dfs(u):
    global ans
    st[u] = True
    for v, w in g[u]:
        if not st[v] and nums[v] + w > 0:
            ans += (nums[v] + w)
            dfs(v)


n = int(input())
nums = map(int, input().split())
nums = [0, *nums]
for i in range(n - 1):
    u, v, w = map(int, input().split())
    g[u].append([v, w])
    g[v].append([u, w])

res = 0
for i in range(1, n + 1):
    ans = nums[u]
    if not st[i]:
        dfs(i)
    res = max(ans, res)
print(res)