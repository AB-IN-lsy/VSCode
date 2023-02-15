'''
Author: NEFU AB-IN
Date: 2022-03-31 10:45:20
FilePath: \ACM\Acwing\1247.py
LastEditTime: 2022-03-31 11:27:36
'''
n, m = map(int, input().split())

a = list(map(int, input().split()))
if n == m == 0:
    print(a[0])
    exit(0)
a.sort()

if m == 0:
    print(sum(a))
else:
    ans = a[-1] - a[0]
    for i in range(1, n + m):
        if a[i] < 0:
            ans -= a[i]
        else:
            ans += a[i]
    print(ans)