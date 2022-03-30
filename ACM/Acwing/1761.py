'''
Author: NEFU AB-IN
Date: 2022-03-30 21:09:27
FilePath: \ACM\Acwing\1761.py
LastEditTime: 2022-03-30 21:09:27
'''


def S(x1, y1, x2, y2):
    return (y2 - y1) * (x2 - x1)


def cale(x_11, y_11, x_12, y_12, x1, y1, x2, y2):
    xl = max(x_11, x1)
    xr = min(x_12, x2)
    if xr <= xl:
        return 0
    yl = max(y_11, y1)
    yr = min(y_12, y2)
    if yr <= yl:
        return 0
    return S(xl, yl, xr, yr)


x_11, y_11, x_12, y_12 = map(int, input().split())
x_21, y_21, x_22, y_22 = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())

print(
    S(x_11, y_11, x_12, y_12) + S(x_21, y_21, x_22, y_22) -
    (cale(x_11, y_11, x_12, y_12, x1, y1, x2, y2) +
     cale(x_21, y_21, x_22, y_22, x1, y1, x2, y2)))
