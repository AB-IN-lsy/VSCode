def circle(number, k):
    length = number
    people = []
    for index in range(number):
        people.append(index + 1)
    j = 0
    temp = 0
    res = 0
    while number > 1:
        index = j % length
        if people[index] != 0:
            temp += 1
        if temp == k:
            people[index] = 0
            number -= 1
            temp = 0
        j += 1
    for index, i in enumerate(people):
        if i != 0:
            res = index + 1
            
    return res
while True:
    try:      
       number,k=input().split()
       print(circle(int(number),int(k)))
    except:
        break
