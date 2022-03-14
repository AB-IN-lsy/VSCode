'''
Author: NEFU AB-IN
Date: 2022-03-13 10:38:40
FilePath: \ACM\LeetCode\284\a.py
LastEditTime: 2022-03-13 10:38:40
'''


class Solution:
    def findKDistantIndices(self, nums, key: int, k: int):
        ans = []
        res = []
        for i in range(len(nums)):
            if key == nums[i]:
                ans.append(i)
        for key in ans:
            for i in range(len(nums)):
                if abs(key - i) <= k:
                    res.append(i)
        res = set(res)
        return list(res)


print(Solution().findKDistantIndices([2, 2, 2, 2, 2], 2, 2))
