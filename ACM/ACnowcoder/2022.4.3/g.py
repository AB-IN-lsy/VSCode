'''
Author: NEFU AB-IN
Date: 2022-04-03 14:45:47
FilePath: \ACM\ACnowcoder\2022.4.3\g.py
LastEditTime: 2022-04-03 14:45:48
'''
for _ in range(int(input())):
    x, y = map(int, input().split())
    if x < y:
        x, y = y, x
    ans = 0
    while x != 0 or y != 0:
        ans += x // y
        x = x % y
        if x < y:
            x, y = y, x
    print(ans)