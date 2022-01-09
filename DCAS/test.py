import math


def solve():
    a, s = input().split()
    index_a = len(a) - 1
    index_s = len(s) - 1
    b = ""
    stack_a = a[len(a) - 1]
    stack_s = s[len(s) - 1]
    while index_s >= 0 and index_a >= 0:
        if int(stack_s) >= int(stack_a):
            tmp = int(stack_s) - int(stack_a)
            if tmp > 9:
                print("-1")
                return
            b = str(tmp) + b
            index_a -= 1
            index_s -= 1
            stack_a = a[index_a]
            stack_s = s[index_s]
        else:
            index_s -= 1
            stack_s = s[index_s] + stack_s
    if index_s >= 0:
        b = s[:index_s + 1] + b
        index_s = -1
    if index_a >= 0 or index_s >= 0:
        print("-1")
    else:
        for i in range(len(b)):
            if b[i] != '0':
                print(b[i:])
                return


for _ in range(int(input())):
    solve()