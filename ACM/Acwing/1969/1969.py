'''
Author: NEFU AB-IN
Date: 2022-01-13 22:39:02
FilePath: \ACM\Acwing\1969.py
LastEditTime: 2022-01-13 22:58:36
'''

ID = [0] * (1000000 + 2)
lst = [0]


def solve():
    n, k = map(int, input().split())
    for _ in range(n):
        x = int(input())
        lst.append(x)
    res = -1
    for i in range(1, n + 1):
        if ID[lst[i]] != 0 and abs(i - ID[lst[i]]) <= k:
            res = max(res, lst[i])
        ID[lst[i]] = i
    print(res)


if __name__ == "__main__":
    solve()