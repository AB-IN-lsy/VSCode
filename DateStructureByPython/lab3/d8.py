def tuple_append(my_tuple, number):
    l=list(my_tuple[:2])
    l.append(number)
    return tuple(l)
my_tuple = tuple_append(([1,2,3], [4,5,6], '2', 'd'), 4)
print(my_tuple)
