'''
Author: NEFU AB-IN
Date: 2022-03-16 17:31:52
FilePath: \ACM\CCF\202109-1.py
LastEditTime: 2022-03-16 17:33:28
'''
N = 110
nums = [0] * N

n = int(input())
nums[1:] = list(map(int, input().split()))

print(sum(nums))

ans = 0
for i in range(1, n + 1):
    if nums[i] == nums[i - 1]:
        ans -= nums[i]
    ans += nums[i]

print(ans)
