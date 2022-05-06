N = 10

g = [[] for _ in range(N)]

ans = []
vis = [0] * N


def dfs1(u, res):
    vis[u] = 1
    res.append(u)
    if u == t:
        ans.append(res[:])
        return
    for v in g[u]:
        if vis[v]:
            continue
        dfs1(v, res)
        vis[v] = 0
        res.pop()


n, m = map(int, input().split())
s, t = map(int, input().split())
for i in range(m):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)

st = list(map(int, input().split()))
st = [0, *st]

ans1 = set()
dfs1(s, [])
for path in ans:
    for i in range(len(path) - 1):
        u, v = path[i], path[i + 1]
        if st[u] + st[v] == 1:
            if st[u] == 0:
                ans1.add((u, v))
            else:
                ans1.add((v, u))
print(list(ans1))