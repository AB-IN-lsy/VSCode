t=int(input())
while t>0:
    n,a,b=map(int,input().split())
    if not(n&1):
        print("ALL")
    elif a&1:
        print("UP")
    else:
        print("DOWN")