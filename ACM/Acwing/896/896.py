'''
Author: NEFU AB-IN
Date: 2022-03-07 14:42:36
FilePath: \ACM\Acwing\896.py
LastEditTime: 2022-03-07 15:03:36
'''
N = int(1e5 + 10)
a = [0] * N
dp = []


def find(x):
    l, r = 0, len(dp)
    while l < r:
        mid = l + r >> 1
        if dp[mid] >= x:
            r = mid
        else:
            l = mid + 1
    return r


n = int(input())
a[1:] = list(map(int, input().split()))

for i in range(1, n + 1):
    pos = find(a[i])
    if pos == len(dp):
        dp.append(a[i])
    else:
        dp[pos] = a[i]
    print(dp)

print(len(dp))