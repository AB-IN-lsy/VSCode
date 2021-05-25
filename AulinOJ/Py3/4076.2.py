import math
def fibs(n):
    a=1/math.sqrt(5)*(((1+math.sqrt(5))/2)**n-((1-math.sqrt(5))/2))
    return int(a)
print(fibs(int(input())))