'''
Author: NEFU AB-IN
Date: 2022-04-15 17:25:41
FilePath: \ACM\GPLT\L1-033.py
LastEditTime: 2022-04-15 17:28:28
'''


def judge(n, s):
    if n < 1000:
        n *= 10
    n = list(set(str(n)))
    return len(n) == s


n, s = map(int, input().split())
cnt = 0
while True:
    if judge(n, s):
        print(cnt, f"{n:04d}")
        exit(0)
    n += 1
    cnt += 1