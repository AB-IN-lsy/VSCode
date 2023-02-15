'''
Author: NEFU AB-IN
Date: 2022-02-04 18:06:33
FilePath: \ACM\Acwing\1789.py
LastEditTime: 2022-02-04 19:53:32
'''

from collections import defaultdict
from string import ascii_uppercase

d = defaultdict(list)

if __name__ == "__main__":
    s = input()
    for i in range(len(s)):
        d[s[i]].append(i)
    # print(d)
    res = 0
    for i in ascii_uppercase:
        x1 = d[i][0]
        x2 = d[i][1]
        for j in d.keys():
            if i == j:
                continue
            y1 = d[j][0]
            y2 = d[j][1]
            if ((y1 < x1 < y2) and
                (not (y1 < x2 < y2))) or ((y1 < x2 < y2) and
                                          (not (y1 < x1 < y2))):
                res += 1
    print(res // 2)