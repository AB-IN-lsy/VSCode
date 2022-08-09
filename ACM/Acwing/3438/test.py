'''
Author: NEFU AB-IN
Date: 2022-08-08 00:50:55
FilePath: \Acwing\3438\test.py
LastEditTime: 2022-08-08 00:59:00
'''
import sys
# fast IO
input = sys.stdin.readline
read = lambda: map(int, input().split())


def f(s, k):
    mu_ban = "0123456789ABCDEF"
    a = ""
    while s > 0:
        yu_shu = s % k
        s = s // k
        a += mu_ban[yu_shu]
    return a[::-1]


a, n, b = input().split()
a, b = int(a), int(b)

ans = int(n, a)

print(ans)
print(f(ans, b))