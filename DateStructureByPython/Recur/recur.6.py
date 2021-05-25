def no_evens(numbers):
    try:
        if numbers[0] % 2 == 0:
            return False
        else:
            return no_evens(numbers[1:])
    except:
        return True

print(no_evens([1, 2, 3, 5, 6]))
print(no_evens([2]))
print(no_evens([1, 3, 5, 7]))
