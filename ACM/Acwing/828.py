'''
Author: NEFU AB-IN
Date: 2022-02-27 17:02:45
FilePath: \ACM\Acwing\828.py
LastEditTime: 2022-02-27 17:08:23
'''

if __name__ == "__main__":
    n = int(input())
    stk = []

    for i in range(n):
        op = input().split()
        if op[0] == "push":
            stk.append(op[1])
        if op[0] == "pop":
            stk.pop()
        if op[0] == "empty":
            print("NO" if stk else "YES")
        if op[0] == "query":
            print(stk[-1])