'''
Author: NEFU AB-IN
Date: 2022-01-21 22:34:17
FilePath: \ACM\Acwing\1922.3.py
LastEditTime: 2022-01-21 23:31:56
'''
N = int(1e6 + 10)
lst = []

if __name__ == "__main__":
    n, k = map(int, input().split())
    maxn = 0
    for i in range(n):
        g, x = map(int, input().split())
        lst.append((x, g))
    lst.sort()
    j = 0
    res, sum = 0, 0
    for i in range(n):
        sum += lst[i][1]
        while j < i and lst[i][0] - lst[j][0] > 2 * k:
            sum -= lst[j][1]
            j += 1
        res = max(res, sum)
    print(res)
