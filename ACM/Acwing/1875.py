'''
Author: NEFU AB-IN
Date: 2022-01-24 19:26:58
FilePath: \ACM\Acwing\1875.py
LastEditTime: 2022-01-25 00:09:06
'''
from collections import Counter, defaultdict

d = [Counter(), Counter()]

if __name__ == "__main__":
    n = int(input())
    for _ in range(n):
        s, x = input().split()
        d[int(x) % 2][s] += 1
    res = 0
    str = 'BESIGOM'

    v = defaultdict()
    for i in range(1 << 7):
        for j in range(7):
            v[str[j]] = i >> j & 1
        if ((v['B'] + v['I']) * (v['G'] + v['O'] + v['E'] + v['S']) * v['M'] %
                2 == 0):
            sum = 1
            for j in range(7):
                sum *= d[i >> j & 1][str[j]]
            res += sum
    print(res)
