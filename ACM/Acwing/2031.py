'''
Author: NEFU AB-IN
Date: 2022-05-21 14:36:20
FilePath: \ACM\Acwing\2031.py
LastEditTime: 2022-05-21 14:45:12
'''


def check(l, r):
    i, j = l, r
    while i >= 0 and j < n:
        if a[l] - a[i] != a[j] - a[r]:
            return 0
        i -= 1
        j += 1
    return 1


n, l = map(int, input().split())

a = []
for i in range(n):
    a.append(int(input()))

a.sort()

ans = 0
for i in range(1, n - 1):  # 备选点，结点
    if check(i, i):
        ans += 1

for i in range(1, n):  # 备选点，结点中点
    if check(i - 1, i):
        ans += 1

print(ans)
