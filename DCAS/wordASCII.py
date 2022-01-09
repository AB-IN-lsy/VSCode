'''
Author: NEFU AB-IN
Date: 2021-12-20 21:01:33
FilePath: \DCAS\wordASCII.py
LastEditTime: 2021-12-20 21:05:11
'''


def solve():
    s = input()
    ans = 0
    for i in s:
        ans += ord(i)
        if i == s[-1]:
            print(f"{ord(i)} = {ans}")
            return
        print(f"{ord(i)} +", end=" ")


if __name__ == "__main__":
    solve()