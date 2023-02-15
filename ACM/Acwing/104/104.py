'''
Author: NEFU AB-IN
Date: 2022-03-15 16:19:02
FilePath: \ACM\Acwing\104.py
LastEditTime: 2022-03-15 16:19:03
'''
n = int(input())

nums = list(map(int, input().split()))
nums.sort()

pivot = nums[n // 2]
ans = 0
for num in nums:
    ans += abs(num - pivot)

print(ans)