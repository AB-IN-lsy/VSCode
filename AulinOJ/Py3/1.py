a, b = input().split(';')
c, d, e = map(float, b.split(','))
c += 1e-8
d += 1e-8
e += 1e-8
print('The each subject score of  No. %s is %.2f, %.2f, %.2f.' %(a, c, d, e))