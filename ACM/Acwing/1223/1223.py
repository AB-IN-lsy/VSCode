'''
Author: NEFU AB-IN
Date: 2022-04-01 17:33:21
FilePath: \ACM\Acwing\1223.py
LastEditTime: 2022-04-01 17:33:21
'''


def gcd(a, b):
    return gcd(b, a % b) if b else a


def gcd_sub(a, b):
    if a < b:
        a, b = b, a
    if b == 1: return a
    return gcd_sub(b, a // b)


fz, fm = [], []
n = int(input())
a = list(map(int, input().split()))

a = sorted(list(set(a)))

for i in range(1, len(a)):
    d = gcd(a[i - 1], a[i])
    fz.append(a[i] // d)
    fm.append(a[i - 1] // d)

up, down = fz[0], fm[0]
for i in range(1, len(fz)):
    up = gcd_sub(up, fz[i])
    down = gcd_sub(down, fm[i])

print(f"{up}/{down}")