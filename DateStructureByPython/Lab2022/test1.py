N = 10

g = [[] for _ in range(N)]

is_ans = 0


def dfs(u, fa, ans, flag):
    global is_ans
    if is_ans:
        return
    if u == t:
        is_ans = 1
        print(ans)
        return
    for v in g[u]:
        if v == fa:
            continue
        if st[v] and flag:
            continue
        if st[v]:
            flag = 1
        ans.append(v)
        dfs(v, u, ans, flag)
        ans.pop()
        if st[v]:
            flag = 0


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
        # if st[u] + st[v] == 1:
        #     if st[u] == 0:
        #         ans.add((u, v))
        #     else:
        #         ans.add((v, u))

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
# is_trusted: 0, untrusted: 1
dfs(s, -1, [s], 0)
if not is_ans:
    print(None)

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
''' 
6 6
1 6
1 2
2 3
1 4
4 5
5 6
2 6
0 1 1 1 1 0

[1, 2, 3]

5 4
1 3
1 2
2 3
3 4
4 5
0 1 0 1 0

None

6 6
1 6
1 2
2 3
1 4
4 5
5 6
2 6
0 1 1 1 1 0
[1, 2, 6]
'''
