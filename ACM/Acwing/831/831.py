'''
Author: NEFU AB-IN
Date: 2022-02-27 21:04:00
FilePath: \ACM\Acwing\831.py
LastEditTime: 2022-02-27 21:14:38
'''
N = int(1e5 + 10)
h, p = [0] * N, [0] * N
p[0] = 1

P, MOD = 131, 1 << 64


def get(l, r):
    return (h[r] - h[l - 1] * p[r - l + 1] % MOD) % MOD


n_ss = int(input())
ss = input()
ss = " " + ss
res_ss = 0
for i in range(1, n_ss + 1):
    res_ss = (res_ss * P % MOD + ord(ss[i])) % MOD

n_s = int(input())
s = input()
s = " " + s

for i in range(1, n_s + 1):
    h[i] = (h[i - 1] * P % MOD + ord(s[i])) % MOD
    p[i] = p[i - 1] * P % MOD

for i in range(1, n_s + 1):
    if get(i, i + n_ss - 1) == res_ss:
        print(i - 1, end=" ")
