def f(x):
    if x==1:
        return 1
    else:
        return f(x-1)*x
n=int(input())
s=input();ans=1;a=set(s)
for i in a:
    ans*=f(s.count(i))
print(int(f(n)/ans))
