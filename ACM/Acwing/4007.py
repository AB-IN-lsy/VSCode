'''
Author: NEFU AB-IN
Date: 2022-03-16 19:23:35
FilePath: \ACM\Acwing\4007.py
LastEditTime: 2022-03-16 19:30:48
'''
from collections import Counter

n = int(input())
nums = list(map(int, input().split()))
d = Counter()

nums = [0, *nums, 0]
for i in range(1, len(nums)):
    if nums[i] > nums[i - 1]:
        d[nums[i - 1]] += 1
        d[nums[i]] -= 1

cnt, ans = 0, 0
for key in sorted(d.keys()):
    cnt += d[key]
    ans = max(ans, cnt)

print(ans)