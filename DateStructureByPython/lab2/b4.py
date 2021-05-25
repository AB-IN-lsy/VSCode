def print_keys_values_inorder(l):
    for i in l.keys():
        print(i," ".join(sorted(l[i])))


'''
def print_keys_values_inorder(l):
    a=sorted(l.items())
    for i in a:
        print(i[0],end=" ")
        i[1].sort()
        for j in i[1]:
            print(j,end=" ")
        print()
'''
my_dict = {6:['monday', 'coffee', 'strong'], 5:['short'], 3:['may', 'and']}
print_keys_values_inorder(my_dict)