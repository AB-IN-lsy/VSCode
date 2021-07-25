class Node:
    def __init__(self, data, next = None):
        self.__data = data
        self.__next = next
    
    def get_data(self):
        return self.__data
    
    def get_next(self):
        return self.__next
    
    def set_data(self, new_data):
        self.__data = new_data
    
    def set_next(self, new_next):
        self.__next = new_next
    
    def __str__(self):
        return f"{self.__data}"
    
    def add_after(self, value):
        new_node = Node(value, self.__next)
        self.__next = new_node
    
    def remove_after(self):
        if self.__next == None:
            return
        else:
            self.__next = self.__next.__next
    
    def __contains__(self, value):
        if self.__data == value:
            return True
        current = self
        while current.__next != None:
            current = current.__next
            if current.__data == value:
                return True
        return False
    
    def get_sum(self):
        ans = self.__data
        current = self
        while current.__next != None:
            current = current.__next
            ans += current.__data
        return ans

def create_sample_node_chain():
    return Node("three", Node("linked", Node("nodes", None) ) )
    
def print_node_chain(node_of_chain):
    print(node_of_chain.get_data())
    while node_of_chain.get_next() != None:
        node_of_chain = node_of_chain.get_next()
        print(node_of_chain.get_data())

def create_node_chain(values):
    lst = []
    for _ in values:
        new_node = Node(_)
        lst.append(new_node)
    for _ in range( len(lst) - 1 ):
        lst[_].set_next( lst[_ + 1] )
    lst[len(lst) - 1].set_next(None)
    return lst[0]

def convert_to_list(first_node):
    lst = [first_node.get_data()]
    while first_node.get_next() != None:
        first_node = first_node.get_next()
        lst.append(first_node.get_data())
    return lst

def get_consecutive_sum(first_node):
    lst = [first_node.get_sum()]
    while first_node.get_next() != None:
        first_node = first_node.get_next()
        lst.append(first_node.get_sum())
    return lst


