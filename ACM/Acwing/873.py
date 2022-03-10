'''
Author: NEFU AB-IN
Date: 2022-03-10 19:33:19
FilePath: \ACM\Acwing\873.py
LastEditTime: 2022-03-10 19:49:19
'''

for _ in range(int(input())):
    n = int(input())
    i = 2
    res = n
    while i <= n // i:
        if n % i == 0:
            res = res * (i - 1) // i
            while n % i == 0:
                n //= i
        i += 1
    if n > 1:
        res = res * (n - 1) // n
    print(res)