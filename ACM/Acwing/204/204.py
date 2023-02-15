'''
Author: NEFU AB-IN
Date: 2022-03-11 20:29:00
FilePath: \ACM\Acwing\204.py
LastEditTime: 2022-03-11 21:05:51
'''


def exgcd(a, b):
    global k1, k2
    if b == 0:
        k1, k2 = 1, 0
        return a
    d = exgcd(b, a % b)
    k1, k2 = k2, k1
    k2 -= (a // b) * k1
    return d


n = int(input())

m1, a1 = map(int, input().split())
flag = 0
for i in range(n - 1):
    m2, a2 = map(int, input().split())
    k1, k2 = 0, 0
    d = exgcd(m1, m2)
    if (a2 - a1) % d:
        flag = 1
        break
    k1 *= (a2 - a1) // d
    # k1' = k1 + k * (m2 // d) , k取任意整数
    t = m2 // d
    k1 = k1 % t  # 取最小的k1
    # x = a + km
    a1 = k1 * m1 + a1
    m1 = m1 // d * m2

if flag:
    print(-1)
else:
    print(a1 % m1)  #x的最小正整数解
