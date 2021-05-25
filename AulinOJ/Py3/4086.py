while True:
    try:
        tmp=input().split()
        lst=[int(i) for i in tmp]
        lst.sort(reverse=True)
        for i in lst:
            print(i,end=" ")
        print()
    except:
        break