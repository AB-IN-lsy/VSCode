'''
Author: NEFU AB-IN
Date: 2022-04-16 17:43:59
FilePath: \ACM\GPLT\L1-50.PY
LastEditTime: 2022-04-16 17:50:49
'''
from string import ascii_lowercase

l, n = map(int, input().split())

sum = 26**l
n = sum - n

for i in range(1, l + 1):
    cnt, index = 0, -1
    while cnt <= n:
        cnt += 26**(l - i)
        index += 1
    n -= (cnt - (26**(l - i)))
    print(ascii_lowercase[index], end="")
