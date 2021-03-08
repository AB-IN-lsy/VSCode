import math
n = int(input())
n = n // 4 + 1
a = 1/2 * math.pow(-4, n)+ 1/4 * math.pow(16, n)
print(a)