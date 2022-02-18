'''
Author: NEFU AB-IN
Date: 2022-02-15 15:38:39
FilePath: \ACM\Acwing\2014.1.py
LastEditTime: 2022-02-15 15:43:20
'''
from collections import Counter

N = int(1e5 + 20)
a = [0] * N
b = Counter()

if __name__ == "__main__":
    n = int(input())
    for i in range(1, n + 1):
        a[i] = int(input())
        if a[i] > a[i - 1]:
            b[a[i - 1]] += 1
            b[a[i]] -= 1
    cnt, res = 0, 0
    for x in sorted(b.keys()):
        cnt += b[x]
        res = max(res, cnt)
    print(res)