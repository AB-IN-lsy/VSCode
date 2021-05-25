import random
n = random.randint(0,9)
print("You have 5 chances to guess")

for i in range(5):
    x = int(input(f"{i+1} try : "))
    if x > n:
        print("big")
    elif x < n:
        print("small")
    else:
        print("congradulation!")
        break
if x != n:
    print("Game over")
    print(f"The right answer is {n}")