def binary_search(numbers, value):
    try:
        return numbers.index(value)
    except:
        return -1

numbers = [13, 18, 54, 61, 78, 93]
print(binary_search(numbers, 10))