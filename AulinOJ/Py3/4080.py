while True:
    try:
        a1=1
        a2=1
        a=0
        n=int(input())
        if n>1:
            print("1 1 ",end="")
        for i in range(3,1000):
            a=a1+a2
            a1=a2
            a2=a
            if a>n:
                break
            print(a,end=" ")
    except:
        break