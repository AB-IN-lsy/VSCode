while True:
    try:
        n,m=map(int,input().split())
        if n==0 and m==0:
            break
        for i in range(0,100):
            tmp=n*100+i
            if tmp%m==0:
                if i<10:
                    print("0"+str(i),end=" ")
                else:
                    print(i,end=" ")
        print()
    except:
        break