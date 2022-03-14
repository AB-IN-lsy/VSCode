'''
Author: NEFU AB-IN
Date: 2022-03-11 21:30:15
FilePath: \ACM\Acwing\885.py
LastEditTime: 2022-03-11 21:32:31
'''

N = 2020
c = [[0] * N for _ in range(N)]
MOD = int(1e9 + 7)


def init():
    for i in range(N):
        for j in range(i + 1):
            if j == 0: c[i][j] = 1
            else: c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD


init()
for _ in range(int(input())):
    a, b = map(int, input().split())
    print(c[a][b])
