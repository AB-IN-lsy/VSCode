'''
Author: NEFU AB-IN
Date: 2022-01-14 15:37:40
FilePath: \ACM\Acwing\1960.py
LastEditTime: 2022-01-14 21:21:21
'''

from tkinter import N

p = [-1] * (1 << 16)
n = 0


def update(state):
    res = 0
    for i in range(n):  #枚举每一位
        j = (i - 1 + n) % n  #代表前一位的位置
        x = state >> i & 1  #state i 位置上的位置
        y = state >> j & 1  #state j 位置上的位置
        res |= (x ^ y) << i  #stste i 位置上的数变成x^y
    return res


def printS(state):
    for i in range(n):
        print(state >> i & 1)


def solve():
    state = 0
    global n
    n, b = map(int, input().split())
    for i in range(n):
        x = int(input())
        state |= x << i  #状态压缩，将二进制串储存成十进制
    i = 1
    while True:
        state = update(state)  #更新状态
        if i == b:
            printS(state)
            return
        elif p[state] == -1:
            p[state] = i
        else:  #说明进入下一个循环了
            len = i - p[state]  #循环节
            r = (b - i) % len  #余数
            while r > 0:
                state = update(state)
                r -= 1
            printS(state)
            return
        i += 1


if __name__ == "__main__":
    solve()