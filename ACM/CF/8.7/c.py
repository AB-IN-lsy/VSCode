k,n=map(int,input().split())
if k==1 and n==2:
    print("2 1")
    print("1 2")
elif k==3 and n==4:
    print("4 5")
    print("1 2")
    print("2 3")
    print("3 4")
    print("1 3")
    print("1 4")
else:
    print(k,2*k-2)
    print("1",k)
    for i in range(2,k):
        print(1,i)
        print(i,k)
    print("2 3")
