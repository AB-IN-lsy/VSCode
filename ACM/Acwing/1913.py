'''
Author: NEFU AB-IN
Date: 2022-01-21 18:24:16
FilePath: \ACM\Acwing\1913.py
LastEditTime: 2022-01-21 21:34:49
'''
from collections import Counter


class Node(object):
    def __init__(self, x, op):
        self.x = x
        self.op = op

    def __lt__(self, a):
        return self.x < a.x

    def __repr__(self):
        return f"[{self.x}, {self.op}]"


N = int(1e5 + 10)
d = Counter()
lst = []

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        x, b = input().split()
        x = int(x)
        op = 1 if b == 'G' else -1
        lst.append(Node(x, op))
    lst.sort()

    # 求连续最长的相同字母子串
    last, res, sum = 0, 0, 0
    for i in range(n):
        if i == 0 or lst[i].op != lst[i - 1].op:
            last = lst[i].x
        res = max(res, lst[i].x - last)

    for i in range(n):
        # d用来存Si'的前缀和的最早下标x，即左闭右开（不包含i）
        if sum not in d:
            d[sum] = lst[i].x
        sum += lst[i].op
        if sum in d:
            res = max(res, lst[i].x - d[sum])
    print(res)