'''
Author: NEFU AB-IN
Date: 2022-01-25 17:28:23
FilePath: \ACM\Acwing\799.py
LastEditTime: 2022-01-25 17:39:28
'''

from collections import Counter

d = Counter()

if __name__ == "__main__":
    n = int(input())
    lst = list(map(int, input().split()))

    j = 0
    res = 0
    for i in range(n):
        d[lst[i]] += 1
        while j < i and d[lst[i]] == 2:
            d[lst[j]] -= 1
            j += 1
        res = max(res, i - j + 1)
    print(res)