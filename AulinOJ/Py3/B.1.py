def f(n):
    cnt=0
    for i in range(2,n+1):
        if n%i==0 and c(i)==True:
            cnt+=i
    return cnt
def c(n):
    for i in range(2,n):
        if n%i==0:
            return False
    return True
print(f(int(input())))