class BinaryTree:
    def __init__(self, data, left = None, right = None):
        self.__data = data
        self.__left = left
        self.__right = right
    def insert_left(self, new_data):
        if self.__left == None:
            self.__left = BinaryTree(new_data)
        else:
            t = BinaryTree(new_data, left = self.__left)
            self.__left = t
    def insert_right(self, new_data):
        if self.__right == None:
            self.__right = BinaryTree(new_data)
        else:
            t = BinaryTree(new_data, right = self.__right)
            self.__right = t
    def get_left(self):
        return self.__left
    def get_right(self):
        return self.__right
    def set_data(self, new_data):
        self.__data = new_data
    def get_data(self):
        return self.__data
    def set_left(self, le):
        self.__left = le
    def set_right(self, ri):
        self.__right = ri
    
def pre_order_print(tree):
    if tree != None:
        print(tree.get_data(), end = " ")
        pre_order_print(tree.get_left())
        pre_order_print(tree.get_right())

def pre_order_list(tree):
    if tree.get_left() == None and tree.get_right() == None:
        return [tree.get_data()]
    else:
        result = []
        result.append(tree.get_data())
        if tree.get_left() != None:
            result += pre_order_list(tree.get_left())
        if tree.get_right() != None:
            result += pre_order_list(tree.get_right())
        return result

def in_order_print(tree):
    if tree != None:
        in_order_print(tree.get_left())
        print(tree.get_data(), end = " ")
        in_order_print(tree.get_right())

def in_order_list(tree):
    if tree.get_left() == None and tree.get_right() == None:
        return [tree.get_data()]
    else:
        result = []
        if tree.get_left() != None:
            result += in_order_list(tree.get_left())
        result.append(tree.get_data())
        if tree.get_right() != None:
            result += in_order_list(tree.get_right())
        return result

def post_order_print(tree):
    if tree != None:
        post_order_print(tree.get_left())
        post_order_print(tree.get_right())
        print(tree.get_data(), end = " ")

def post_order_list(tree):
    if tree.get_left() == None and tree.get_right() == None:
        return [tree.get_data()]
    else:
        result = []
        if tree.get_left() != None:
            result += post_order_list(tree.get_left())
        if tree.get_right() != None:
            result += post_order_list(tree.get_right())
        result.append(tree.get_data())
        return result

def num_leaves_new(tree):
    if tree == None:
        return 0
    else:
        return max(1, num_leaves(tree.get_left()) + num_leaves(tree.get_right()) )

def num_leaves_old(tree):
    if tree == None:
        return 0
    elif tree.get_left() == None and tree.get_right() == None:
        return 1
    else:
        return num_leaves_new(tree.get_left()) + num_leaves_new(tree.get_right())

def get_height(tree):
    if tree == None:
        return 0
    else:
        return 1 + max(get_height(tree.get_left()), get_height(tree.get_right()))

def count_nodes(tree):
    if tree == None:
        return 0
    else:
        return 1 + count_nodes(tree.get_left()) + count_nodes(tree.get_right())

def sum_tree(tree):
    if tree == None:
        return 0
    else:
        return sum_tree(tree.get_left()) + sum_tree(tree.get_right()) + tree.get_data()

def count_even(tree):
    num_even = 0
    if tree.get_data() % 2 == 0:
        num_even = 1
    if tree.get_left() != None:
        num_even += count_even(tree.get_left())
    if tree.get_right() != None:
        num_even += count_even(tree.get_right())
    return num_even

def leaves_print(tree):
    if tree == None:
        return
    else:
        if tree.get_left() == None and tree.get_right() == None:
            print(tree.get_data())
        else:
            leaves_print(tree.get_left())
            leaves_print(tree.get_right())

def leaves_list(tree, lst = []):
    if tree == None:
        return lst
    else:
        if tree.get_left() == None and tree.get_right() == None:
            lst.append(tree.get_data())
        else:
            leaves_list(tree.get_left(), lst)
            leaves_list(tree.get_right(), lst)
    return lst

def is_full(tree):
    if tree == None:
        return False
    if tree.get_left() == None and tree.get_right() == None:
        return True
    if tree.get_left() == None or tree.get_right() == None:
        return False
    return is_full(tree.get_left()) and is_full(tree.get_right())

def is_identical(tree1, tree2):
    if tree1 == None and tree2 == None:
        return True
    elif tree1 != None and tree2 == None:
        return False
    elif tree2 != None and tree1 == None:
        return False
    else:
        #Both Exist
        if tree1.get_data() != tree2.get_data():
            return False
        else:
            left_eq = is_identical(tree1.get_left(), tree2.get_left())
            right_eq = is_identical(tree1.get_right(), tree2.get_right())
            return left_eq and right_eq

def search(tree, item):
    if tree == None:
        return False
    if tree.get_data() == item:
        return True
    return search(tree.get_left(), item) or search(tree.get_right(), item)

def get_max(tree, is_integer): #True : num , False : str
    if is_integer == True:
        if tree == None:
            return float('-inf')
        else:
            return max( get_max(tree.get_left(), True), max( tree.get_data(), get_max(tree.get_right(), True) ) )
    else:
        if tree == None:
            return str(float('-inf'))
        else:
            return max( get_max(tree.get_left(), False), max( str(tree.get_data()), get_max(tree.get_right(), False) ) )

def print_tree(tree, level):
    print(' ' * (level * 4) + str(tree.get_data()) )
    if tree.get_left() != None:
        print('(L)', end = '')
        print_tree(tree.get_left(), level + 1)
    if tree.get_right() != None:
        print('(R)', end = '')
        print_tree(tree.get_right(), level + 1)

def convert_tree_to_list(tree): #tree -> list
    if tree == None:
        return None
    else:
        lst = []
        lst.append(tree.get_data()) 
        lst.append(convert_tree_to_list(tree.get_left()))
        lst.append(convert_tree_to_list(tree.get_right()))
    return lst

def create_tree_from_nested_list(lst): # list -> tree
    tree = BinaryTree(lst[0])
    if lst[1] != None:
        tree_left = create_tree_from_nested_list(lst[1])
        tree.set_left(tree_left)
    else:
        tree.set_left(lst[1])
    if lst[2] != None:
        tree_right = create_tree_from_nested_list(lst[2])
        tree.set_right(tree_right)
    else:
        tree.set_right(lst[2])
    return tree

def create_tree_from_nested_list_new(lst) : # list -> tree
    if type(lst) != list:
        return lst
    else:
        tree = BinaryTree(lst[0])
        tree.set_left(create_tree_from_nested_list_new(lst[1]))
        tree.set_left(create_tree_from_nested_list_new(lst[2]))
        return tree

def create_a_tree():
    tree = BinaryTree(10)
    tree.insert_left(5)
    tree.insert_right(15)
    right = tree.get_right()
    left = tree.get_left()
    left.insert_right(6)
    left.insert_left(3) 
    right.insert_right(19)
    right.insert_left(12)
    rr = left.get_right()
    rr.insert_right(7)
    ll = right.get_right()
    ll.insert_left(17)
    lll = ll.get_left()
    lll.insert_left(16)
    lll.insert_right(18)
    return tree

def inorder_successor(tree, data):
    lst = in_order_list(tree)
    return lst[lst.index(data) + 1]


search_tree = create_a_tree()
print(inorder_successor(search_tree, 10))
print(inorder_successor(search_tree, 5))
print(inorder_successor(search_tree, 15))