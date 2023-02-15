'''
Author: NEFU AB-IN
Date: 2022-03-15 16:08:06
FilePath: \ACM\Acwing\913.py
LastEditTime: 2022-03-15 16:08:07
'''
n = int(input())
nums = list(map(int, input().split()))

nums.sort()
ans = 0
for i in range(n):
    ans += nums[i] * (n - i - 1)
print(ans)