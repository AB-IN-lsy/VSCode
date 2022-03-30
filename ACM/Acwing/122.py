'''
Author: NEFU AB-IN
Date: 2022-03-30 11:24:05
FilePath: \ACM\Acwing\122.py
LastEditTime: 2022-03-30 14:45:58
'''
N = int(1e6 + 10)
n = int(input())
a, s, c = [0], [0] * N, []

for i in range(1, n + 1):
    a.append(int(input()))
    s[i] = s[i - 1] + a[i]

b = sum(a) // n
for i in range(1, n):
    c.append(i * b - s[i])
c.append(0)

c.sort()

ans = 0
for i in range(n):
    ans += abs(c[i] - c[n // 2])
print(ans)