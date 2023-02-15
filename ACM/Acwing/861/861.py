'''
Author: NEFU AB-IN
Date: 2022-03-04 22:36:48
FilePath: \ACM\Acwing\861.py
LastEditTime: 2022-03-05 11:34:36
'''
N = 510

match, st = [0] * N, [0] * N  # match 表示左边选择的右边点
g = [[] for _ in range(N)]


def find(u):
    for v in g[u]:
        if st[v] == 0:
            st[v] = 1
            if match[v] == 0 or find(match[v]):
                match[v] = u
                return True
    return False


n1, n2, m = map(int, input().split())
res = 0

for i in range(m):
    u, v = map(int, input().split())
    g[u].append(v)

for i in range(1, n1 + 1):
    st = [0] * N  # 每次清空st数组，表示右边目前都未考虑过，相当于回溯
    if find(i):
        res += 1
print(res)
