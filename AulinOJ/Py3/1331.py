t=int(input())
while t>0:
    t-=1
    a,b=input().split()[-2:]
    print(str(int(a)+int(b))[-2:])