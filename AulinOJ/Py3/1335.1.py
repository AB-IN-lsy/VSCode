i=input()
x=(((ord(i)&31)+21)%26+64)
i=chr(x)
print(i)
