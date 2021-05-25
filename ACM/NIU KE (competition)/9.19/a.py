for _ in range(int(input())):
    n=int(input())
    s=input()
    f=0
    if n%2==0:#剩偶数位置的数
        for i in range(1,n,2):
            if int(s[i])%2==0:
                print(2)
                f=1
                break
        if f==0:
            print(1)
    else:
        for i in range(0,n,2):
            if int(s[i])%2!=0:
                print(1)
                f=1
                break
        if f==0:
            print(2)
            
