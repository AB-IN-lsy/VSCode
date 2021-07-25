for _ in range(int(input())):
    n=int(input())
    lst=input().split()
    one=lst.count("1")
    zero=lst.count("0")
    if one>zero:
        lst=list(filter(lambda x: x=="1",lst))
        if len(lst)&1:
            lst.pop()
    else:
        lst=list(filter(lambda x: x=="0",lst))
    print(len(lst))
    print(" ".join(lst))