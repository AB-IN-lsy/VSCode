'''
Author: NEFU AB-IN
Date: 2021-11-05 19:16:12
FilePath: \ACM\CCF\201403-1.PY
LastEditTime: 2022-03-04 18:51:01
'''
from collections import Counter

d = Counter()

n = int(input())
nums = map(int, input().split())

for num in nums:
    d[num] += 1

res = 0
for key in sorted(d.keys()):
    if d[key] > 0 and d[-key] > 0:
        minn = min(d[key], d[-key])
        d[key] -= minn
        d[-key] -= minn
        res += minn
print(res)
