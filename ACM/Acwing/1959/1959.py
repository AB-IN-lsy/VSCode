'''
Author: NEFU AB-IN
Date: 2022-05-19 15:25:15
FilePath: \ACM\Acwing\1959.py
LastEditTime: 2022-05-19 17:26:49
'''
from collections import Counter


def rotate(a, b):  # ab 向量顺时针旋转90度
    b[0] -= a[0]
    b[1] -= a[1]

    x = b[1]
    y = -b[0]

    return [x + a[0], y + a[1]]


n = int(input())

d = Counter()  # 初始化坐标
turn = Counter()  # 每一次前进的方向，相对于目前正方向的偏移量

d['FL'] = [0, 1]
d['RL'] = [0, 0]
d['FR'] = [1, 1]
d['RR'] = [1, 0]

turn['F'] = 0
turn['B'] = 2
turn['L'] = 3
turn['R'] = 1

dir = [[0, 1], [1, 0], [0, -1], [-1, 0]]  # 上右下左

face = 0  # 0朝北，1朝东，2朝南，3朝西
minx, maxx, miny, maxy = 0, 1, 0, 1

for i in range(n):
    s = input()
    feet = s[:2]
    op = s[-1]

    if op == 'P':
        for key in d.keys():
            if key != feet:
                d[key] = rotate(d[feet], d[key])
        face = (face + 1) % 4
    else:
        id = (face + turn[op]) % 4
        d[feet][0] += dir[id][0]
        d[feet][1] += dir[id][1]

    for k1 in d.keys():
        for k2 in d.keys():
            if k1 != k2 and d[k1] == d[k2]:
                print(-1)
                exit(0)

    for k in d.keys():
        minx = min(minx, d[k][0])
        maxx = max(maxx, d[k][0])
        miny = min(miny, d[k][1])
        maxy = max(maxy, d[k][1])

print((maxx - minx + 1) * (maxy - miny + 1))