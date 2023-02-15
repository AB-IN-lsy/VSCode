'''
Author: NEFU AB-IN
Date: 2022-03-23 10:51:14
FilePath: \ACM\Acwing\1230.py
LastEditTime: 2022-03-23 10:51:14
'''
N = int(1e5 + 10)

from collections import Counter

s = [0] * N
d = Counter()

n, k = map(int, input().split())
ans = 0
d[0] = 1
for i in range(n):
    s[i] = int(input())
    s[i] += s[i - 1]
    ans += d[s[i] % k]
    d[s[i] % k] += 1

print(ans)