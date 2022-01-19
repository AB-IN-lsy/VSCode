'''
Author: NEFU AB-IN
Date: 2022-01-11 17:10:01
FilePath: \ACM\Acwing\1987.1.py
LastEditTime: 2022-01-11 17:13:02
'''
lst = []


def solve():
    n = int(input())
    pos = 0  #初始位置为0
    for _ in range(n):
        x, op = input().split()
        x = int(x)
        if op == 'L':
            lst.append((pos - x, 1))
            lst.append((pos, -1))
            pos -= x
        else:
            lst.append((pos, 1))
            lst.append((pos + x, -1))
            pos += x
    last, cnt, res = 0, 0, 0
    for x, y in sorted(lst):
        if cnt >= 2:
            res += (x - last)
        cnt += y
        last = x
    print(res)


if __name__ == "__main__":
    solve()