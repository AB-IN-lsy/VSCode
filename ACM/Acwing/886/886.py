'''
Author: NEFU AB-IN
Date: 2022-03-12 10:55:10
FilePath: \ACM\Acwing\886.py
LastEditTime: 2022-03-12 10:55:11
'''
N = int(1e5 + 10)
MOD = int(1e9 + 7)
fact, infact = [0] * N, [0] * N

fact[0] = infact[0] = 1
for i in range(1, N):
    fact[i] = fact[i - 1] * i % MOD
    infact[i] = infact[i - 1] * pow(i, MOD - 2, MOD) % MOD

for i in range(int(input())):
    a, b = map(int, input().split())
    print(fact[a] * infact[b] * infact[a - b] % MOD)