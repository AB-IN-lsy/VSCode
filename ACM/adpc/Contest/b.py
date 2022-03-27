'''
Author: NEFU AB-IN
Date: 2022-03-27 09:35:47
FilePath: \ACM\Contest\b.py
LastEditTime: 2022-03-27 10:00:27
'''

N = 55
b = [0] * N


def check(mid):
    s = [0] * N
    s[id] = a[id] - mid
    for i in range(id + 1, n):
        s[i] = s[i - 1] + 1
    for i in range(id - 1, -1, -1):
        s[i] = s[i + 1] - 1
    for i in range(n):
        if abs(a[i] - s[i]) > mid:
            return False
    return True


n = int(input())
a = list(map(int, input().split()))

id = 0
maxn = 0
for i in range(n):
    b[i] = a[i] + i
    if b[i] > maxn:
        maxn = b[i]
        id = i

l, r = 1, 1000000000
while l < r:
    mid = l + r >> 1
    if check(mid):
        r = mid
    else:
        l = mid + 1

print(r)