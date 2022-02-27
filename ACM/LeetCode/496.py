'''
Author: NEFU AB-IN
Date: 2022-02-26 22:38:13
FilePath: \ACM\LeetCode\496.py
LastEditTime: 2022-02-26 22:39:30
'''


class Solution:
    def nextGreaterElement(self, nums1: List[int],
                           nums2: List[int]) -> List[int]:
        stk, res = [], []
        d = Counter()
        for num in reversed(nums2):
            while stk and stk[-1] <= num:
                stk.pop()
            d[num] = stk[-1] if stk else -1
            stk.append(num)
        for num in nums1:
            res.append(d[num])
        return res