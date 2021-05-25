while True:
    try:
        tmp=input().split()
        lst=[int(i) for i in tmp]
        print(max(lst))
    except ValueError:
        print()
