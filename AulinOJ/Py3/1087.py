def su(x):
    if x==0 or x==1:
        return False
    for i in range(2,x):
        if x%i==0:
            return False
    return True
s=input()
maxn=s.count(max(s,key=s.count));minn=s.count(min(s,key=s.count))
if su(maxn-minn)==True:
    print("Lucky Word");print(maxn-minn)
else:
    print("No Answer");print("0")
