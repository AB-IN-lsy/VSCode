'''
Author: NEFU AB-IN
Date: 2022-03-29 11:19:18
FilePath: \ACM\Acwing\1224.py
LastEditTime: 2022-03-29 11:54:55
'''
N = int(1e6 + 10)
st = [0] * N

n = int(input())
a = list(map(int, input().split()))
a = [0, *a]

ans = 0
for i in range(1, n + 1):
    if a[i] != i:
        for j in range(i + 1, n + 1):
            if a[j] == i:
                a[i], a[j] = a[j], a[i]
        ans += 1

print(ans)