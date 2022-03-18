'''
Author: NEFU AB-IN
Date: 2022-03-18 14:10:22
FilePath: \ACM\Acwing\1459.py
LastEditTime: 2022-03-18 14:10:22
'''
from collections import Counter

k, n = map(int, input().split())

d = Counter()

for _ in range(k):
    nums = list(map(int, input().split()))
    for i in range(len(nums)):
        for j in range(i + 1, len(nums)):
            d[(nums[i], nums[j])] += 1

ans = 0
for i, j in d.keys():
    if d[(j, i)]:
        continue
    ans += 1
print(ans)
