'''
Author: NEFU AB-IN
Date: 2022-02-23 10:33:49
FilePath: \ACM\Acwing\2816.py
LastEditTime: 2022-02-23 10:38:16
'''
N = int(1e5 + 100)
a = [0] * N
b = [0] * N

n, m = map(int, input().split())
a[1:] = map(int, input().split())
b[1:] = map(int, input().split())

j = 1
for i in range(1, n + 1):
    while j <= m and b[j] != a[i]:
        j += 1
    if j > m:
        print("No")
        exit(0)
    else:
        j += 1
print("Yes")