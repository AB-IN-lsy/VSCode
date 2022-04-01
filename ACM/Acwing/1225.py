'''
Author: NEFU AB-IN
Date: 2022-04-01 20:38:53
FilePath: \ACM\Acwing\1225.py
LastEditTime: 2022-04-01 20:38:54
'''
k = 0


def dfs():
    global k
    res = 0
    while k < len(a):
        if a[k] == '(':
            k += 1
            res += dfs()
            k += 1
        elif a[k] == '|':
            k += 1
            res = max(res, dfs())
        elif a[k] == ')':
            break
        else:
            res += 1
            k += 1
    return res


a = input().strip()
print(dfs())
