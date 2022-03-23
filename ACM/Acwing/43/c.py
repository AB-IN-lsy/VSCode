'''
Author: NEFU AB-IN
Date: 2022-03-19 18:54:05
FilePath: \ACM\Acwing\43\c.py
LastEditTime: 2022-03-19 19:21:13
'''
N = int(2e5 + 10)
nums = [0] * N

n, t = map(int, input().split())
nums[1:] = list(map(int, input().split()))

for i in range(1, n + 1):
    nums[i] += nums[i - 1]

ans = 0

for i in range(1, n + 1):
    l, r = i, n
    while l < r:
        mid = l + r + 1 >> 1
        if nums[mid] - nums[l - 1] < t:
            l = mid
        else:
            r = mid - 1
    ans = r - l + 1

print(ans)