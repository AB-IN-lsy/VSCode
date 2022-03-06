'''
Author: NEFU AB-IN
Date: 2022-03-04 19:35:50
FilePath: \ACM\ACnowcoder\2022.3.24\d.py
LastEditTime: 2022-03-04 19:53:02
'''
N = int(1e6 + 10)
s = input()
s = " " + s
b = [0] * N

res = 0


def qpow(a, b, p):
    a = a % p
    ret = 1
    while b:
        if b & 1:
            ret = (ret * a) % p
        b >>= 1
        a = a * 2 % p
    return ret


for i in range(1, len(s)):
    if s[i] == '(':
        b[i] = b[i - 1] + 1
    else:
        b[i] = b[i - 1] - 1
        if b[i] < 0:
            print(-1)
            exit(0)
if b[len(s) - 1] != 0:
    print(-1)
    exit(0)
for i in range(1, len(s) - 1):
    if b[i] == 0:
        res += 1
print(qpow(2, res, int(1e9 + 7)))