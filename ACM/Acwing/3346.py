'''
Author: NEFU AB-IN
Date: 2022-03-14 08:38:52
FilePath: \ACM\Acwing\3346.py
LastEditTime: 2022-03-14 08:38:53
'''
nums = list(map(int, input().split()))
nums.sort()

print(nums[0], nums[1], nums[6] - nums[0] - nums[1])