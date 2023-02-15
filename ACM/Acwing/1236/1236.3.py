'''
Author: NEFU AB-IN
Date: 2022-03-24 19:02:00
FilePath: \ACM\Acwing\1236.3.py
LastEditTime: 2022-03-24 19:20:24
'''
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
c = list(map(int, input().split()))

a.sort()
b.sort()
c.sort()
ja, jc, ans = 0, 0, 0
for i in range(n):
    while ja < n and a[ja] < b[i]:
        ja += 1
    while jc < n and c[jc] <= b[i]:
        jc += 1
    ans += ja * (n - jc)

print(ans)