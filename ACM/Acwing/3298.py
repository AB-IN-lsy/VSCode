'''
Author: NEFU AB-IN
Date: 2022-03-17 17:47:16
FilePath: \ACM\Acwing\3298.py
LastEditTime: 2022-03-17 17:47:17
'''
N = int(1e5 + 10)


class Node():
    def __init__(self, grade=0, flag=0):
        self.grade = grade
        self.flag = flag


n = int(input())
nums = [Node() for _ in range(N)]

for i in range(1, n + 1):
    nums[i].grade, nums[i].flag = map(int, input().split())

nums.sort()
ans = 0
maxn = 0

for i in range(1, n + 1):
    nums[i].flag += nums[i - 1].flag

for i in range(1, n + 1):
    sum = i - (nums[i - 1].flag - nums[0].flag)
    sum += nums[n].flag - nums[i - 1].flag
    if maxn <= sum:
        maxn = sum
        ans = i
print(ans)