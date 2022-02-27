'''
Author: NEFU AB-IN
Date: 2022-02-21 19:46:13
FilePath: \ACM\LeetCode\2182.py
LastEditTime: 2022-02-21 20:12:47
'''

from collections import Counter
import heapq


class Solution:
    def repeatLimitedString(self, s: str, repeatLimit: int) -> str:
        d = Counter(s)
        h = []
        res = ""
        for i in d.keys():
            heapq.heappush(h, [-ord(i), d[i]])

        while len(h):
            t = heapq.heappop(h)
            if t[1] <= repeatLimit:
                res += chr(-t[0]) * t[1]
            else:
                res += chr(-t[0]) * repeatLimit
                t[1] -= repeatLimit

                if len(h):
                    t1 = heapq.heappop(h)
                    res += chr(-t1[0])
                    t1[1] -= 1
                    if t1[1] > 0:
                        heapq.heappush(h, t1)
                    heapq.heappush(h, t)
        return res


print(Solution().repeatLimitedString("aababab", 2))