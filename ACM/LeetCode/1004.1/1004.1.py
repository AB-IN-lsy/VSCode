'''
Author: NEFU AB-IN
Date: 2022-02-26 19:33:47
FilePath: \ACM\LeetCode\1004.1.py
LastEditTime: 2022-02-26 19:44:19
'''


class Solution:
    def longestOnes(self, nums, k) -> int:
        n = len(nums)
        res, j, cnt = 0, 0, 0  #j左端点, cnt为0的个数
        for i in range(n):
            if nums[i] == 0:
                cnt += 1
            while j <= i and cnt > k:
                if nums[j] == 0:
                    cnt -= 1
                j += 1
            res = max(res, i - j + 1)
        return res


print(Solution().longestOnes([0, 0, 0], 0))
