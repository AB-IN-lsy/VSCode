'''
Author: NEFU AB-IN
Date: 2022-03-17 21:14:51
FilePath: \ACM\Acwing\3292.py
LastEditTime: 2022-03-17 21:14:52
'''
n, X, Y = map(int, input().split())

nums = []
for i in range(n):
    x, y = map(int, input().split())
    nums.append([x, y, i])

nums.sort(key=lambda x: (x[0] - X)**2 + (x[1] - Y)**2)

for i in range(3):
    print(nums[i][2] + 1)