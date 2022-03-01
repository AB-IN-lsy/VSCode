'''
Author: NEFU AB-IN
Date: 2022-02-27 18:29:35
FilePath: \ACM\Acwing\600.py
LastEditTime: 2022-02-27 18:35:55
'''

N = int(1e5 + 10)

if __name__ == "__main__":
    n = int(input())
    a = []
    for i in range(n):
        a.append(int(input()))

    stk, res = [], [0] * N
    for i in range(n - 1, -1, -1):
        while stk and a[stk[-1]] <= a[i]:
            stk.pop()
        res[i] = stk[-1] + 1 if stk else 0
        stk.append(i)
    for i in range(n):
        print(res[i])