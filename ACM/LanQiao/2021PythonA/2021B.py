'''
Author: NEFU AB-IN
Date: 2022-01-07 21:05:49
FilePath: \ACM\LanQiao\Zhixian.py
LastEditTime: 2022-01-11 21:05:21
'''


class Line(object):
    def __init__(self, k=0, b=0):  #构造函数
        self.k = k
        self.b = b

    def __lt__(self, t):
        if self.k != t.k:
            return self.k < t.k
        else:
            return self.b < t.b


x_lst = [_ for _ in range(20)]
y_lst = [_ for _ in range(21)]

points = [(x, y) for x in x_lst for y in y_lst]

s = set()

for p in points:
    for q in points:
        if p != q and p[0] != q[0]:
            k = (q[1] - p[1]) / (q[0] - p[0])
            b = q[1] - q[0] * k
            s.add((round(k, 8), round(b, 8)))

print(len(s) + 20)