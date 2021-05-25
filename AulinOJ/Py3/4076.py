while True:
    try:
        a1=1
        a2=1
        a=0
        n=int(input())
        if n==1:
            print(1)
            break
        if(n==2):
            print(1)
            break
        for i in range(3,n+1):
            a=a1+a2
            a1=a2
            a2=a
        print(a)
    except:
        break