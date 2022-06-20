'''
Author: NEFU AB-IN
Date: 2022-03-12 19:29:40
FilePath: \ACM\Acwing\42\c.py
LastEditTime: 2022-03-12 21:44:35
'''
N = int(1e4 + 10)
g = [[] * N for _ in range(N)]
ww = [0] * N  # 记录当前点上面的权值
maxw = [0] * N  #记录当前点下面的最大值

maxn = 0
maxjd = 1
ans = 0


def dfs1(fa, u, len):
    global maxn, maxjd
    for v, w in g[u]:
        if v == fa:
            continue
        ww[v] = ww[u] + w
        dfs1(u, v, len + w)
    if len > maxn:
        maxn = len
        maxjd = u


def dfs2(fa, u):
    for v, w in g[u]:
        if v == fa:
            continue
        maxw[u] = max(maxw[u], dfs2(u, v) + w)
    return maxw[u]


def dfs(fa, u, z):
    global ans
    for v, w in g[u]:
        if v == fa:
            continue
        cha = maxn - ww[u] - maxw[v] - w
        ww[v] += (cha + z)  #差值 和 补充父节点补的
        ans += cha
        dfs(u, v, cha + z)


n = int(input())
a = list(map(int, input().split()))
for i in range(len(a)):
    g[i + 2].append([(i + 2) // 2, a[i]])
    g[(i + 2) // 2].append([i + 2, a[i]])

dfs1(0, 1, 0)
dfs2(0, 1)
dfs(0, 1, 0)
print(maxjd)
print(ww[:35])
print(maxw[:35])
print(ans)
