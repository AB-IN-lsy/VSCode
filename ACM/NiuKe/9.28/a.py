n=int(input())
x=int(input())
n=n%6
if n==0:
    if x==0:
        print(0)
    if x==1:
        print(1)
    if x==2:
        print(2)
if n==1:
    if x==0:
        print(1)
    if x==1:
        print(0)
    if x==2:
        print(2)
if n==2:
    if x==0:
        print(1)
    if x==1:
        print(2)
    if x==2:
        print(0)
if n==3:
    if x==0:
        print(2)
    if x==1:
        print(1)
    if x==2:
        print(0)
if n==4:
    if x==0:
        print(2)
    if x==1:
        print(0)
    if x==2:
        print(1)
if n==5:
    if x==0:
        print(0)
    if x==1:
        print(2)
    if x==2:
        print(1)
