while True:
    try:
        n=int(input())
        if n==0:
            break
        tmp=input().split()
        lst=["".join(sorted(list(i))) for i in tmp]
        tmp1=list(filter(lambda x: lst.count("".join(sorted(list(x))))==1 ,tmp))
        tmp1.sort()
        if len(tmp1)==0:
            print("None",end="")
        else:    
            for i in tmp1:
                print(i,end=" ")
        print()
    except:
        break