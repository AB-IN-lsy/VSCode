for _ in range(int(input())):
    a=input()
    b=input()
    c=input()
    d=input()
    lst=[(len(a),"A"),(len(b),"B"),(len(c),"C"),(len(d),"D")]
    lst.sort(key=lambda x:x[0])
    if lst[0][0]!=lst[1][0]:
        print(lst[0][1])
    elif lst[3][0]!=lst[2][0]:
        print(lst[3][1])
    else:
        print("C")