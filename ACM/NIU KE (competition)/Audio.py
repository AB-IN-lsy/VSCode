x1,y1=map(float,input().split())
x2,y2=map(float,input().split())
x3,y3=map(float,input().split())

k_12=(y1-y2)/(x1-x2)
k1=-1/k_12
x_1=(x1+x2)/2
y_1=(y1+y2)/2
b1=y_1-k1*x_1

k_23=(y2-y3)/(x2-x3)
k2=-1/k_23
x_2=(x2+x3)/2
y_2=(y2+y3)/2
b2=y_2-k2*x_2

posx=(b2-b1)/(k1-k2)
posy=k1*posx+b1

print(f'{posx:.3f} {posy:.3f}')