'''
Author: NEFU AB-IN
Date: 2022-02-23 16:02:45
FilePath: \ACM\Acwing\801.py
LastEditTime: 2022-02-23 16:02:46
'''
lowbit = lambda x: x & -x

n = int(input())
a = list(map(int, input().split()))

for i in a:
    cnt = 0
    while i:
        i -= lowbit(i)
        cnt += 1
    print(cnt, end=" ")
