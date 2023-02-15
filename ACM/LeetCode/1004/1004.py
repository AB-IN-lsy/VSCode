'''
Author: NEFU AB-IN
Date: 2022-02-24 18:20:41
FilePath: \ACM\LeetCode\1004.py
LastEditTime: 2022-02-26 19:54:24
'''


class Solution:
    def longestOnes(self, nums, k) -> int:
        nums = [-1, *nums]
        b = [0] * len(nums)

        def check(l, r):
            if b[r] - b[l - 1] <= k:
                return True
            return False

        def find(R):
            l, r = 1, len(b) - 1
            while l < r:
                mid = l + r >> 1
                if check(mid, R):
                    r = mid
                else:
                    l = mid + 1
            return r

        for i in range(len(nums)):
            if nums[i] == 0:
                b[i] = 1
            b[i] += b[i - 1]
        res = 0
        for i in range(1, len(nums)):
            L = find(i)
            if i == L and k == 0 and nums[i] == 0:
                continue
            res = max(res, i - L + 1)
        return res


# import bisect

# class Solution:
#     def longestOnes(self, nums, k) -> int:
#         n = len(nums)
#         P = [0]
#         for num in nums:
#             P.append(P[-1] + (1 - num))

#         ans = 0
#         for right in range(n):
#             left = bisect.bisect_left(P, P[right + 1] - k)
#             ans = max(ans, right - left + 1)

#         return ans

print(Solution().longestOnes([0, 0, 0], 0))
