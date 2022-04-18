'''
Author: NEFU AB-IN
Date: 2022-04-04 16:00:36
FilePath: \ACM\Acwing\1303.py
LastEditTime: 2022-04-04 16:43:32
'''
M = 3
Matrix = lambda: [[0] * M for _ in range(M)]


def mul(a, b):
    c = Matrix()
    for i in range(M):
        for j in range(M):
            for k in range(M):
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % m
    return c


def quickpow(a, b):
    I = Matrix()  #单位矩阵
    for i in range(M):
        for j in range(M):
            I[i][j] = 1 if i == j else 0
    while b:
        if b & 1:
            I = mul(I, a)
        b >>= 1
        a = mul(a, a)
    return I


n, m = map(int, input().split())

# Fn = [fn, fn+1, Sn]
F1 = [1, 1, 1]
A = [[0, 1, 0], [1, 1, 1], [0, 0, 1]]

B = quickpow(A, n - 1)
ans = F1[0] * B[0][2] + F1[1] * B[1][2] + F1[2] * B[2][2]

print(ans % m)
