import random
def dp(lst):
    lst1 = set(lst)
    if len(lst) > len(lst1):
        return True
    else:
        return False
def ge(numbers):
    birthday = []
    for i in range(numbers):
        birthday.append(random.randint(1, 365))
    return birthday
def match(students, samples):
    count = 0
    birthday = []
    for _ in range(samples):
        birthday = ge(students)
        if dp(birthday):
            count += 1
    return count
students = 23
s = 10000
count = match(students,s)
rate = (float(count) / s) * 100
print(f"rate is {rate:.6f}%")