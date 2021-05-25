try:
    t=int(input())
    while t>0:
        t-=1
        r=float(input())
        s=3.1415*r*r
        print("%6f"%s)
except ValueError:
    print()
