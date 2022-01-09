'''
Author: NEFU AB-IN
Date: 2021-12-31 09:53:43
FilePath: \ACM\LanQiao\KaPian.py
LastEditTime: 2022-01-07 20:37:33
'''

lst = [2021 for i in range(10)]


def check(x):
    x_str = str(x)
    for i in x_str:
        if lst[int(i)] == 0:
            return 0
        lst[int(i)] -= 1
    return 1


def solve():
    cnt = 1
    while check(cnt):
        cnt += 1
    print(cnt - 1)


if __name__ == "__main__":
    solve()