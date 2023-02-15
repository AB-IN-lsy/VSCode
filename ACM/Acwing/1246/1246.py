'''
Author: NEFU AB-IN
Date: 2022-03-31 19:49:38
FilePath: \ACM\Acwing\1246.py
LastEditTime: 2022-03-31 19:49:38
'''


def gcd(a, b):
    return gcd(b, a % b) if b else a


n = int(input())
a = list(map(int, input().split()))

a.sort()
d = a[1] - a[0]
for i in range(1, n):
    d = gcd(d, a[i] - a[i - 1])
if d:
    print((a[-1] - a[0]) // d + 1)
else:
    print(n)