def f(x):
    if x==1:
        return 10;
    if x>1:
        return f(x-1)+2
x=int(input())
print(f(x))
