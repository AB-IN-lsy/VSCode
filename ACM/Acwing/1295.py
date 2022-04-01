'''
Author: NEFU AB-IN
Date: 2022-03-31 20:40:38
FilePath: \ACM\Acwing\1295.py
LastEditTime: 2022-03-31 20:40:39
'''
from math import factorial as fact
from collections import Counter
while True:
    try:
        n = int(input())
        a = []
        cnt = 0
        d = Counter()
        i = 2
        while i <= n // i:
            if n % i == 0:
                a.append(i)
                while n % i == 0:
                    d[i] += 1
                    cnt += 1
                    n //= i
            i += 1
        if n > 1:
            a.append(n)
            cnt += 1
            d[n] += 1

        ans = fact(cnt)
        for key in d.keys():
            ans //= fact(d[key])
        print(cnt, ans)
    except:
        break