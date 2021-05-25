def flip_list(numbers):
    if len(numbers) == 0:
        return []
    else:
        return [numbers[i] for i in range(len(numbers)-1, -1, -1)]
print(flip_list([]))
print(flip_list([1,3,5,7]))
print(flip_list([1,3,5]))
print(flip_list([1]))