'''
Author: NEFU AB-IN
Date: 2022-03-30 17:07:11
FilePath: \ACM\Acwing\1235.py
LastEditTime: 2022-03-30 19:31:38
'''
n, S = map(int, input().split())
a = list(map(int, input().split()))
b = [0] * (n + 1)

tmp = S / n
a.sort()

for i in range(n):
    avg = S / (n - i)
    if a[i] < avg:
        b[i] = a[i]
        S -= a[i]
    else:
        b[i] = avg
        S -= avg

s = 0.0
for i in range(n):
    s += pow(b[i] - tmp, 2)

s = pow(s / n, 0.5)
print(f"{s:.4f}")