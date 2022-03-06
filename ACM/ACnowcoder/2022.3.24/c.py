'''
Author: NEFU AB-IN
Date: 2022-03-04 19:16:48
FilePath: \ACM\ACnowcoder\2022.3.24\c.py
LastEditTime: 2022-03-04 20:20:37
'''
nums = list(map(int, input().split()))
cnt = 0
res = 0
for i in range(len(nums)):
    a, c = (nums[i] + cnt) // 3, (nums[i] + cnt) % 3
    cnt = 0
    if c:
        res += 4 * (i + 1)
        cnt += 1
        a -= 1
    res += a * 3 * (i + 1)
    cnt += a
print(res)