def get_max_list(numbers):
    if len(numbers) == 1:
        return numbers[0]
    else:
        return max(numbers[0], get_max_list(numbers[1:]))

lst = [1, 4, 5, -9]
print(get_max_list(lst))
lst = [1]
print(get_max_list(lst))

def get_max_len_list(words):
    if len(words) == 1:
        return len(words[0])
    else:
        return max(len(words[0]), get_max_len_list(words[1:]))

lst = ['This', 'is', 'a', 'test']
print(get_max_len_list(lst))

lst = ['hello']
print(get_max_len_list(lst))