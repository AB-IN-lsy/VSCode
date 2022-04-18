'''
Author: NEFU AB-IN
Date: 2022-04-05 21:25:05
FilePath: \ACM\Acwing\1788.py
LastEditTime: 2022-04-05 21:25:06
'''
from collections import Counter

n = int(input())
d = Counter()

ans = 0
for i in range(n):
    x, flag = map(int, input().split())
    flag += 1
    if d[x] == (3 - flag):
        ans += 1
    d[x] = flag

print(ans)