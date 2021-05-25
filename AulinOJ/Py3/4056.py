def f(x):
    cnt=0
    for i in x:
        cnt+=int(i)
    return cnt
while True:
    try:
        s=input().strip();num=0
        while int(s)>=10:
            s=f(str(s))
            num+=1
        print(num)
    except:
        break
