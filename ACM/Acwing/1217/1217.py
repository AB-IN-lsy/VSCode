'''
Author: NEFU AB-IN
Date: 2022-04-05 11:45:36
FilePath: \ACM\Acwing\1217.py
LastEditTime: 2022-04-05 15:40:46
'''
M = 6
MOD = int(1e9 + 7)
Matrix = lambda: [[0] * M for _ in range(M)]


def mul(a, b):
    c = Matrix()
    for i in range(M):
        for j in range(M):
            for k in range(M):
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD
    return c


def quickpow(a, b):
    I = Matrix()
    for i in range(M):
        for j in range(M):
            I[i][j] = (i == j)
    while b:
        if b & 1:
            I = mul(I, a)
        b >>= 1
        a = mul(a, a)
    return I


n, m = map(int, input().split())
A = [[4] * M for _ in range(M)]

for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    A[a][(b + 3) % 6] = 0
    A[b][(a + 3) % 6] = 0

B = quickpow(A, n - 1)
ans = 0
for i in range(M):
    ans = (ans + 4 * sum(B[i])) % MOD

print(ans)