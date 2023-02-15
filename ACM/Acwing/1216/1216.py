'''
Author: NEFU AB-IN
Date: 2022-03-23 18:47:32
FilePath: \ACM\Acwing\1216.py
LastEditTime: 2022-03-23 18:48:48
'''
n = int(input())

ans = 0
pg = 0

while True:
    #喝
    ans += n
    pg += n
    #换
    n = pg // 3
    pg = pg % 3

    if n == 0 and pg < 3:
        break
print(ans)
