'''
Author: NEFU AB-IN
Date: 2022-02-20 15:10:20
FilePath: \ACM\Acwing\102.py
LastEditTime: 2022-02-20 16:46:18
'''
N = int(1e5 + 100)

a = [0]
b = [0] * N


def check(x):
    for i in range(1, n + 1):
        b[i] = b[i - 1] + a[i] - x
    minv = 0
    for i in range(f, n + 1):
        minv = min(minv, b[i - f])
        if b[i] - minv >= 0:
            return True
    return False


n, f = map(int, input().split())

l, r = 0.0, 0.0

for i in range(n):
    x = int(input())
    a.append(x)
    r = max(r, float(x))

while r - l > 1e-6:
    mid = (l + r) / 2
    if check(mid):
        l = mid
    else:
        r = mid

print(int(r * 1000))