from math import log10

read = lambda: map(int, input().split())

a, b = read()
c = b * log10(a)

if c > 9:
    print(-1)
else:
    print(a**b)
