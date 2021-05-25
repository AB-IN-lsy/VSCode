n, x, y = map(int, input().split())
tmp = n
for i in range(1, y + 1):
    n = 2 * n / 3
    if i == x:
        n += tmp / 2
    if n < tmp / 32:
        print("N0!")
        print(i, f'{n:.6f}')
        exit(0)
print("YE5!")
print(f'{n:.6f}')
    
