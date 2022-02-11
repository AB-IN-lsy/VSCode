'''
Author: NEFU AB-IN
Date: 2022-02-10 11:44:19
FilePath: \ACM\Acwing\1715.py
LastEditTime: 2022-02-10 11:47:10
'''

a = []

if __name__ == "__main__":
    n = int(input())
    for i in range(n):
        s, t, b = map(int, input().split())
        a.append((s, b))
        a.append((t, -b))
    a.sort()

    last, cnt, res = 0, 0, 0

    for x, y in a:
        cnt += y
        last = x
        res = max(cnt, res)
    print(res)
