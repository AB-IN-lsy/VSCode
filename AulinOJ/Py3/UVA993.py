while True:
    try:
        t=int(input())
        while t>0:
            t-=1
            s=int(input());a=0;b="";tmp=s
            for i in range(9,1,-1):
                while s%i==0:
                    b+=str(i)
                    s=s//i
                    a=1
            if tmp<10:
                print(tmp)
            elif a==1 and int(s)==1:
                print(b[::-1])
            else:
                print("-1")
    except:
        break
