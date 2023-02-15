'''
Author: NEFU AB-IN
Date: 2022-02-22 11:38:52
FilePath: \ACM\Acwing\113.py
LastEditTime: 2022-02-22 11:49:35
'''
# Forward declaration of compare API.
# def compare(a, b):
# @param a, b int
# @return bool
# return bool means whether a is less than b.


class Solution(object):
    def specialSort(self, N):
        """
        :type N: int
        :rtype: List[int]
        """
        a = [1]
        for i in range(2, N + 1):
            l, r = 0, len(a) - 1
            while l < r:
                mid = l + r >> 1
                if compare(i, a[mid]):
                    r = mid
                else:
                    l = mid + 1
            if compare(i, a[r]):
                a.insert(r, i)
            else:
                a.insert(r + 1, i)
        return a