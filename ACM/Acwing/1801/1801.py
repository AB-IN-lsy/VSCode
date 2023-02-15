'''
Author: NEFU AB-IN
Date: 2022-01-30 13:55:06
FilePath: \ACM\Acwing\1801.py
LastEditTime: 2022-01-31 10:46:22
'''
from collections import defaultdict
from itertools import permutations

b = []
c = defaultdict(int)


def judge(x, y):
    x = c[x]
    y = c[y]
    if x == 0 and y == 1:
        return True
    elif x == 1 and y == 2:
        return True
    elif x == 2 and y == 0:
        return True
    else:
        return False


if __name__ == "__main__":
    n = int(input())
    a = list(permutations(range(1, 4), 3))
    for i in range(n):
        b.append(tuple(map(int, input().split())))
    res = 0
    for i in a:
        cnt = 0
        for j in range(len(i)):
            c[i[j]] = j
        for j in b:
            if judge(j[0], j[1]):
                cnt += 1
        res = max(res, cnt)
    print(res)