def f(x):
    if x%4==0 and x%100!=0 or x%400==0:
        return True
    else:
        return False
mon=[0,31,28,31,30,31,30,31,31,30,31,30,31]
while True:
    try:
        y,m,d=map(int,input().split())
        for i in range(1,10001):
            d+=1
            if f(y):
                mon[2]=29
            else:
                mon[2]=28
            if d>mon[m]:
                d=1;m+=1
            if m>12:
                m=1;y+=1
        print(f'{y}-{m}-{d}')
    except:
        break