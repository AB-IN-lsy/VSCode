'''
Author: NEFU AB-IN
Date: 2022-01-07 21:05:49
FilePath: \ACM\LanQiao\Zhixian.py
LastEditTime: 2022-01-07 22:06:41
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


print(Line().b)
print(Line(1, 2).b)
print(Line(1).b)