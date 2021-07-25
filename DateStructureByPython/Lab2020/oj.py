n, k, a = map(int, input().split())
jg = list(map(float, input().split()))
ly = list(map(float, input().split()))
a1 = a
tmp = [ (ly[i] / jg[i], jg[i], ly[i]) for i in range(n)]
tmp1 = [ (ly[i] * jg[i], jg[i], ly[i]) for i in range(n)]

tmp.sort(key= lambda x:x[0], reverse= True)
tmp1.sort(key= lambda x:x[0], reverse= True)
ans = 0
ans1 = 0

for i in tmp:
    num = a // i[1]
    if num > k:
        num = k
    a -= num * i[1]
    ans += num * (i[1] * i[2])

for i in tmp1:
    num = a1 // i[1]
    if num > k:
        num = k
    a1 -= num * i[1]
    ans1 += num * (i[1] * i[2])
print(  max ( int( (ans + 0.5) / 100) , int( (ans1 + 0.5) / 100) ) )