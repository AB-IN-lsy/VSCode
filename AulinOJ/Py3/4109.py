while True:
    try:
        a,b=map(int,input().split())
        judge=1
        for i in range(a,b+1):
            c=1
            for j in range(2,i):
                if i%j==0:
                    c=0;break
            if c:
                print(i,end=" ");judge=0
        if judge:
            print(0)
    except:
        break