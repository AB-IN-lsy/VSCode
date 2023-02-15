'''
Author: NEFU AB-IN
Date: 2022-03-30 21:45:16
FilePath: \ACM\Acwing\1749.py
LastEditTime: 2022-03-30 21:53:25
'''


def S(x1, y1, x2, y2):
    return (x2 - x1) * (y2 - y1)


x1, y1, x2, y2 = map(int, input().split())
X1, Y1, X2, Y2 = map(int, input().split())

if X1 <= x1 and x2 <= X2 and Y1 <= y1 and y2 <= Y2:  #全覆盖
    print(0)
elif X1 <= x1 and x2 <= X2 and Y1 <= y1 and y1 <= Y2 <= y2:  #x全覆盖，y上面未覆盖完全
    print(S(x1, y1, x2, y2) - S(x1, y1, x2, Y2))
elif X1 <= x1 and x2 <= X2 and Y2 >= y2 and y1 <= Y1 <= y2:  #x全覆盖，y下面未覆盖完全
    print(S(x1, y1, x2, y2) - S(x1, Y1, x2, y2))
elif Y1 <= y1 and y2 <= Y2 and X1 <= x1 and x1 <= X2 <= x2:  #y全覆盖，x右面未覆盖完全
    print(S(x1, y1, x2, y2) - S(x1, y1, X2, y2))
elif Y1 <= y1 and y2 <= Y2 and X2 >= x2 and x1 <= X1 <= x2:  #y全覆盖，x左面未覆盖完全
    print(S(x1, y1, x2, y2) - S(X1, y1, x2, y2))
else:
    print(S(x1, y1, x2, y2))
