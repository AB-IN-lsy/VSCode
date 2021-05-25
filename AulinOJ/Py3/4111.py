def GCD(a, b):
    r=a%b
    while r:
        a = b
        b = r
        r = a % b
    return b
a=int(input())
b=int(input())
s=GCD(a,b)
print(s)