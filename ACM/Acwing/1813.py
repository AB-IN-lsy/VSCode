'''
Author: NEFU AB-IN
Date: 2022-01-27 22:50:49
FilePath: \ACM\Acwing\1813.py
LastEditTime: 2022-01-27 23:35:41
'''
from collections import Counter
from string import ascii_lowercase

res = Counter()

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        x, y = input().split()
        A = Counter()
        B = Counter()
        for j in x:
            A[j] += 1
        for j in y:
            B[j] += 1
        for i in ascii_lowercase:
            res[i] += max(A[i], B[i])
    for i in ascii_lowercase:
        print(res[i])