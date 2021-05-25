#dp水题
while True:
    try:
        t=int(input())
        while t>0:
            t-=1
            n=int(input())
            if n%2==0:
                print(4)
            else:
                print(n+3)
    except:
        break
