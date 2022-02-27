'''
Author: NEFU AB-IN
Date: 2022-02-26 22:20:54
FilePath: \ACM\LeetCode\503.py
LastEditTime: 2022-02-27 09:09:56
'''


class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        nums = [*nums * 2]
        stk, res = [], []
        for num in reversed(nums):
            while stk and stk[-1] <= num:
                stk.pop()
            if stk:
                res.append(stk[-1])
            else:
                res.append(-1)
            stk.append(num)
        return res[::-1][:len(res) // 2]