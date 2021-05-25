s,k=input().split()
for i in range(len(s)):
    print(chr(ord(s[i])^ord(k[i%len(k)])),end="")