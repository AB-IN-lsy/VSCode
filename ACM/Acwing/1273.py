'''
Author: NEFU AB-IN
Date: 2022-04-12 19:44:06
FilePath: \ACM\Acwing\1273.py
LastEditTime: 2022-04-12 19:44:06
'''
N = int(2e5 + 10)
M = 18
fmax = [[0] * M for _ in range(N)]
log = [0] * N


def init():
    for j in range(M):
        i = 1
        while i + (1 << j) - 1 <= n:
            if j == 0: fmax[i][j] = a[i]
            else:
                fmax[i][j] = max(fmax[i][j - 1], fmax[i + (1 << j - 1)][j - 1])
            i += 1

    log[1] = 0
    for i in range(2, N):
        log[i] = log[i >> 1] + 1


def query(l, r):
    k = log[r - l + 1]
    return max(fmax[l][k], fmax[r - (1 << k) + 1][k])


n = int(input())
a = list(map(int, input().split()))
a = [0, *a]

init()

m = int(input())
for i in range(m):
    l, r = map(int, input().split())
    print(query(l, r))