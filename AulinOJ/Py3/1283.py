while True:
    try:
        n,m=map(int,input().split())
        x=[i+1 for i in range(n)]
        while len(x)>1:
            if m%len(x):
                i= m%len(x)-1
            else:
                i=len(x)-1
            x=x[i+1:]+x[:i]
        print(x[0])
    except:
        break