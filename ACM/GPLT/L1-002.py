'''
Author: NEFU AB-IN
Date: 2022-04-13 11:35:27
FilePath: \ACM\GPLT\L1-002.py
LastEditTime: 2022-04-13 21:52:47
'''


def gcd(a, b):
    return gcd(b, a % b) if b else a


n = int(input())
lst = input().split()

f = []
ans = 0
fm = 1
fz = 0
for s in lst:
    x, y = map(int, s.split("/"))
    d = gcd(x, y)
    x //= d
    y //= d
    #     ans += x // y
    #     x -= (x // y) * y
    fm = y // gcd(fm, y) * fm
    f.append([x, y])

# print(f)

for i in range(n):
    f[i][0] *= fm // f[i][1]
    fz += f[i][0]
d = gcd(fz, fm)
fz //= d
fm //= d

if fz % fm == 0:
    print(fz // fm)
elif abs(fz) // fm:
    print(fz // fm, f"{fz - fm * (fz // fm)}/{fm}")
else:
    print(f"{fz}/{fm}")