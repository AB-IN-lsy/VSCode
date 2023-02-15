'''
Author: NEFU AB-IN
Date: 2022-03-09 17:39:55
FilePath: \ACM\Acwing\866.py
LastEditTime: 2022-03-09 17:41:02
'''


def judge(n):
    if n <= 1:
        return False
    i = 2
    while i <= n // i:
        if n % i == 0:
            return False
        i += 1
    return True


for _ in range(int(input())):
    n = int(input())
    print("Yes") if judge(n) else print("No")