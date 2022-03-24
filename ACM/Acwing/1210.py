'''
Author: NEFU AB-IN
Date: 2022-03-24 15:56:38
FilePath: \ACM\Acwing\1210.py
LastEditTime: 2022-03-24 15:56:38
'''
INF = int(4e9)

n = int(input())
a = list(map(int, input().split()))
a = [0, *a]
# mn, mx = [0] * (n + 1), [0] * (n + 1)

ans = 0
for i in range(1, n + 1):
    mx, mn = -INF, INF
    for j in range(i, n + 1):
        mx = max(mx, a[j])
        mn = min(mn, a[j])
        if mx - mn == j - i:
            ans += 1

print(ans)