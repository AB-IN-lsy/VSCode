# import
import sys, math
from collections import Counter, deque
from heapq import heappop, heappush
from bisect import bisect_left, bisect_right

# Final
N = int(1e6 + 10)
INF = int(2e9)

# Define
sys.setrecursionlimit(INF)
read = lambda: map(int, input().split())

# —————————————————————Division line ————————————————————————————————————————
st, prime = [0] * N, []


def init():
    st[0] = st[1] = 1
    for i in range(2, N):
        if st[i] == 0:
            prime.append(i)
        for j in range(len(prime)):
            if i * prime[j] >= N:
                break
            st[i * prime[j]] = 1
            if i % prime[j] == 0:
                break


init()
n, = read()
a = list(read())

for x in a:
    y = int(math.sqrt(x))
    if y * y == x:
        if st[y] == 0:
            print("YES")
        else:
            print("NO")
    else:
        print("NO")
