'''
Author: NEFU AB-IN
Date: 2022-03-02 19:43:45
FilePath: \ACM\Acwing\846.py
LastEditTime: 2022-03-02 20:02:42
'''

N = int(1e5 + 10)
st = [0] * N
g = [[] for _ in range(N)]
ans = N


def dfs(u):
    global ans
    st[u] = True
    cnt = 1  # 以u为根的子节点的个数，一开始只有u一个
    res = 0  # 连通块的点数的最大值
    for j in g[u]:
        if st[j] == 0:
            s = dfs(j)  #返回的是以u的子节点为根节点的子节点数
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

dfs(1)
print(ans)