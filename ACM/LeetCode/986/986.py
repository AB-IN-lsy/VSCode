'''
Author: NEFU AB-IN
Date: 2022-03-14 20:50:54
FilePath: \ACM\LeetCode\986.py
LastEditTime: 2022-03-14 20:50:55
'''


class Solution:
    def intervalIntersection(self, firstList: List[List[int]],
                             secondList: List[List[int]]) -> List[List[int]]:
        res = []
        i, j = 0, 0
        while i < len(firstList) and j < len(secondList):
            L, R = max(firstList[i][0],
                       secondList[j][0]), min(firstList[i][1],
                                              secondList[j][1])
            if L <= R:
                res.append([L, R])
            if firstList[i][1] <= secondList[j][1]:
                i += 1
            else:
                j += 1
        return res
