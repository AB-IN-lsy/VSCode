import math
def d(x1,y1,x2,y2):
    return math.sqrt((x2-x1)**2+(y2-y1)**2)
x1,y1,x2,y2,x3,y3=map(float,input().split())
a=d(x1,y1,x2,y2)
b=d(x1,y1,x3,y3)
c=d(x2,y2,x3,y3)
p=(a+b+c)/2
print(f'{math.sqrt(p*(p-a)*(p-b)*(p-c)):.2f}')
