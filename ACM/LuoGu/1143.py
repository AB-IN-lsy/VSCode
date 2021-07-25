def f(s,k):
    mu_ban="0123456789ABCDEF";a=""
    while s>0:
        yu_shu=s%k
        s=s//k
        a+=mu_ban[yu_shu]
    return a[::-1]
n=int(input())
s=input()
k=int(input())
print(f(int(s,n),k))