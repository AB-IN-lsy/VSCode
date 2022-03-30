'''
Author: NEFU AB-IN
Date: 2022-03-30 20:16:21
FilePath: \ACM\Acwing\1239.py
LastEditTime: 2022-03-30 20:16:22
'''
MOD = int(1e9 + 9)
n, k = map(int, input().split())
a = []
for i in range(n):
    a.append(int(input()))

a.sort()
l, r = 0, n - 1
res = 1
sign = 1  #符号，1代表正，-1代表负
if k & 1:
    res = a[r]
    r -= 1
    k -= 1
    if res < 0:
        sign = -1

while k:
    x = a[l] * a[l + 1]
    y = a[r] * a[r - 1]
    if x * sign > y * sign:
        res = abs(res) * abs(x) % MOD
        l += 2
    else:
        res = abs(res) * abs(y) % MOD
        r -= 2
    k -= 2
print(res * sign)
