'''
Author: NEFU AB-IN
Date: 2022-01-09 09:51:53
FilePath: \ACM\Acwing\1996.py
LastEditTime: 2022-01-09 11:43:36
'''
import bisect


def solve():
    n = int(input())
    lst = []
    lst_up = []
    lst_down = []
    for _ in range(n):
        s = sorted(input())
        lst.append(s)
        lst_up.append(s)
        lst_down.append(s[::-1])

    lst_up.sort()
    lst_down.sort()

    for s in lst:
        #lower_bound
        low = bisect.bisect_left(lst_down, s) + 1
        #upper_bound
        high = bisect.bisect_right(lst_up, s[::-1])
        print(low, high)


if __name__ == "__main__":
    solve()
