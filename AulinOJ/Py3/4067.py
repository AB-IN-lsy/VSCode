def h(x):
    print("+",end=" ")
    for i in range(1,x+1):
        print("-",end=" ")
    print("+",end=" ")
    for i in range(1,x+1):
        print("-",end=" ")
    print("+")
def l(x):
    print("|",end=" ")
    for i in range(1,x+1):
        print(" ",end=" ")
    print("|",end=" ")
    for i in range(1,x+1):
        print(" ",end=" ")
    print("|")
while True:
    try:
        n=int(input())
        h(n)
        for i in range(1,n+1):
            l(n)
        h(n)
        for i in range(1,n+1):
            l(n)
        h(n)
    except:
        break
