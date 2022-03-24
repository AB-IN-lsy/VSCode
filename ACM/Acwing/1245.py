'''
Author: NEFU AB-IN
Date: 2022-03-24 19:26:17
FilePath: \ACM\Acwing\1245.py
LastEditTime: 2022-03-24 19:26:18
'''
ss = "2019"


def check(x):
    x = str(x)
    for i in x:
        if i in ss:
            return True
    return False


n = int(input())
ans = 0
for i in range(1, n + 1):
    if check(i): ans += i

print(ans)