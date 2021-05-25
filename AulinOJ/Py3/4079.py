n=int(input())
s=str(bin(n))
s1=s[2:]
if len(s1)<=8:
    s2=(8-len(s1))*"0"+s1
print(s2)