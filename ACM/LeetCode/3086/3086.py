'''
Author: NEFU AB-IN
Date: 2024-07-04 18:09:24
FilePath: \LeetCode\3086\3086.py
LastEditTime: 2024-07-06 21:51:06
'''
class Solution:
    def minimumMoves(self, nums: List[int], k: int, maxChanges: int) -> int:
        n = len(nums)
        def f(i: int) -> int:
            return sum(nums[max(i - 1, 0):min(i + 2, n)])

        indexSum, count = [0] * (n + 1), [0] * (n + 1)
        for i in range(n):
            indexSum[i + 1], count[i + 1] = indexSum[i] + nums[i] * i, count[i] + nums[i]
        res = inf
        for i in range(n):
            if f(i) + maxChanges >= k:
                if k <= f(i):
                    res = min(res, k - nums[i])
                else:
                    res = min(res, 2 * k - f(i) - nums[i])
            left, right = 0, n
            while left <= right:
                mid = (left + right) // 2
                i1, i2 = max(i - mid, 0), min(i + mid, n - 1)
                if count[i2 + 1] - count[i1] >= k - maxChanges:
                    right = mid - 1
                else:
                    left = mid + 1
            i1, i2 = max(i - left, 0), min(i + left, n - 1)
            if count[i2 + 1] - count[i1] > k - maxChanges:
                i1 += 1
            count1, count2 = count[i + 1] - count[i1], count[i2 + 1] - count[i + 1]
            res = min(res, indexSum[i2 + 1] - indexSum[i + 1] - i * count2 + i * count1 - (indexSum[i + 1] - indexSum[i1]) + 2 * maxChanges)
        return res