while True:
    try:
        tmp=input().split()[1:]
        if tmp==0:
            break
        lst=[int(i) for i in tmp]
        lst.sort(key=lambda x: abs(x),reverse=True)
        for i in lst:
            print(i,end=" ")
        print()
    except:
        break