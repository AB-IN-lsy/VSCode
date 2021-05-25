class BinarySearchTree:
    def __init__(self, data, left=None, right=None):
        self.__data = data
        self.__left = left
        self.__right = right
    def insert_left(self, new_data):
        if self.__left == None:
            self.__left = BinarySearchTree(new_data)
        else:
            t = BinarySearchTree(new_data, left=self.__left)
            self.__left = t
    def insert_right(self, new_data):
        if self.__right == None:
            self.__right = BinarySearchTree(new_data)
        else:
            t = BinarySearchTree(new_data, right=self.__right)
            self.__right = t
    def get_left(self):
        return self.__left
    def get_right(self):
        return self.__right
    def set_left(self, left):
        self.__left = left
    def set_right(self, right):
        self.__right = right
    def set_data(self, data):
        self.__data = data
    def get_data(self):
        return self.__data
    def inorder_successor(self, data):
        if self.__data == data: #先找这个数据在哪
            if self.__right == None:
                return None
            else:
                current = self.__right # 找到了就往右循环，找右边左子树第一个左子树不是None的
                while current.__left:
                    current = current.__left
                return (self, current, current.__data) # 返回一个元组(要删的，取代的，取代的值)
        elif data < self.__data and self.__left != None: # 小了往左找
            return self.__left.inorder_successor(data)
        elif data > self.__data and self.__right != None: # 大了往右找
            return self.__right.inorder_successor(data)
        else:
            return None
    def search_tree(self, data):
        if self.__data == data: 
            return self
        elif data < self.__data and self.__left != None: 
            return self.__left.inorder_successor_new(data)
        elif data > self.__data and self.__right != None: 
            return self.__right.inorder_successor_new(data)
        else:
            return None
    def __contains__(self, value):
        try:
            if self.get_data() == value:
                return True
            else:
                return self.get_left().__contains__(value) or self.get_right().__contains__(value)
        except AttributeError:
            return False
    def search(self, value):
        if self.get_data() == value:
            return self
        else:
            if self.get_left()!= None:
                lt = self.get_left().search(value)
                if lt != None:
                    return lt
            else:
                return None
            if self.get_right()!= None:
                rt = self.get_right().search(value)
                if rt != None:
                    return rt
            else:
                return None
    def insert(self, new_data):
        if new_data == self.__data:
            return
        elif new_data < self.__data:
            if self.__left == None:
                self.__left = BinarySearchTree(new_data)
            else:
                self.__left.insert(new_data)
        else:
            if self.__right == None:
                self.__right = BinarySearchTree(new_data)
            else:
                self.__right.insert(new_data)
        

def print_tree(t, level):
    print(' ' * (level*4) + str(t.get_data())) 
    if t.get_left() != None:
        print('(l)', end = '')
        print_tree(t.get_left(), level + 1) 
    if t.get_right() != None: 
        print('(r)', end = '')
        print_tree(t.get_right(), level + 1) 

def create_bst_from_list(values):
    tree = BinarySearchTree(values[0])
    for i in range(1, len(values) - 1):
        tree.insert(values[i])
    return tree

def create_bst_from_sorted(values):
    if values == []:
        return
    tree = BinarySearchTree(values[len(values) // 2])
    tree.set_left(create_bst_from_sorted(values[:len(values) // 2]))
    tree.set_right(create_bst_from_sorted(values[len(values) // 2 + 1:]))
    return tree

def get_bst_postorder(tree):
    if tree.get_left() == None and tree.get_right() == None:
        return [tree.get_data()]
    else:
        result = []
        if tree.get_left() != None:
            result += get_bst_postorder(tree.get_left())
        if tree.get_right() != None:
            result += get_bst_postorder(tree.get_right())
        result.append(tree.get_data())
        return result

def tree_sort(lst):
    tree = BinarySearchTree(lst[0])
    for i in lst[1:]:
        tree.insert(i)
    return traverse(tree)
'''
lst = [1, 2, 5, 6, 3, 4]
print(tree_sort(lst))
'''

def traverse(tree): #中序遍历
    if tree.get_left() == None and tree.get_right() == None:
        return [tree.get_data()]
    else:
        result = []
        if tree.get_left() != None:
            result += traverse(tree.get_left())
        result.append(tree.get_data())
        if tree.get_right() != None:
            result += traverse(tree.get_right())
        return result

def get_maximum(tree1):
    if tree1.get_right() == None:
        return tree1.get_data()
    else:
        return get_maximum(tree1.get_right())

def print_insert_position(bst, value):
    if bst.get_data() == value:
        print("Duplicate")
        return
    elif value < bst.get_data():
        if bst.get_left() == None:
            print(f"To the left of {bst.get_data()}")
            return
        else:
            print_insert_position(bst.get_left(), value)
    else:
        if bst.get_right() == None:
            print(f"To the right of {bst.get_data()}")
            return
        else:
            print_insert_position(bst.get_right(), value)

def is_binary_search_tree(tree, min_value, max_value):
    if tree.get_left() != None and tree.get_right() != None:
        l = is_binary_search_tree(tree.get_left(), min_value, max_value)
        r = is_binary_search_tree(tree.get_right(), min_value, max_value)
        return (tree.get_data() > tree.get_left().get_data()) and (tree.get_data() < tree.get_right().get_data() and l and r)
    elif tree.get_left() != None and tree.get_right() == None:
        l = is_binary_search_tree(tree.get_left(), min_value, max_value)
        return (tree.get_data() > tree.get_left().get_data()) and l
    elif tree.get_left() == None and tree.get_right() != None:
        r = is_binary_search_tree(tree.get_right(), min_value, max_value)
        return (tree.get_data() < tree.get_right().get_data()) and r
    else:
        return True
    
def in_order_print(tree):
    if tree != None:
        in_order_print(tree.get_left())
        print(tree.get_data(), end = " ")
        in_order_print(tree.get_right())

t = BinarySearchTree(65)
t.insert(24)
t.insert(16)
t.insert(43)
t.insert(88)
t.insert(71)
t.insert(81)

in_order_print(t)
