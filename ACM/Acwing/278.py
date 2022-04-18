'''
Author: NEFU AB-IN
Date: 2022-04-02 16:44:11
FilePath: \ACM\Acwing\278.py
LastEditTime: 2022-04-02 16:44:11
'''
N = int(1e2 + 10)
M = int(1e4 + 10)
f = [0] * M

n, m = map(int, input().split())
v = list(map(int, input().split()))
v = [0, *v]

f[0] = 1
for i in range(1, n + 1):
    for j in range(m, v[i] - 1, -1):
        f[j] += f[j - v[i]]

print(f[m])
