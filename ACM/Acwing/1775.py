'''
Author: NEFU AB-IN
Date: 2022-04-07 17:54:31
FilePath: \ACM\Acwing\1775.py
LastEditTime: 2022-04-07 18:08:33
'''
x, y = map(int, input().split())
xx, last = x, x
cnt = 1
flag = 0
ans = 0
while True:
    x = xx + (-1)**flag * (cnt)
    cnt *= 2
    flag ^= 1
    if min(x, last) <= y <= max(x, last):
        ans += abs(y - last)
        break
    ans += abs(x - last)
    last = x
print(ans)