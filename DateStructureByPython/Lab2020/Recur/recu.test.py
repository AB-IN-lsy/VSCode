def sum_list(my_list):
    if len(my_list) == 1:
        return my_list[0]
    else:
        return my_list[0] + sum_list(my_list[1:])

print(sum_list([1,2,3,4]))