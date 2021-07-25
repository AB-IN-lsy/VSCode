class SimpleHashTable:
    def __init__(self, size = 7):
        self.__size = size
        self.__slots = [None] * size
    def __str__(self):
        return f"{self.__slots}"
    def get_hash_code(self, key):
        return key % self.__size
    def get_size(self):
        return self.__size
    def put(self, key):
        if self.__len__() == self.__size:
            raise IndexError("ERROR: The hash table is full.")
            return
        index = self.get_hash_code(key)
        if self.__slots[index] == None:
            self.__slots[index] = key
        else:
            for i in range(1, self.__size):
                new_index = self.get_new_hash_code_linear_probing(index)
                if self.__slots[new_index] == None:
                    self.__slots[new_index] = key
                    return
                index = new_index
    def __len__(self):
        return self.__size - self.__slots.count(None)
    def get_new_hash_code_linear_probing(self, index):
        return (index + 1) % self.__size
    def is_empty(self):
        return [None] * self.__size == self.__slots
    def clear(self):
        self.__slots = [None] * self.__size
    def rehashing(self, new_size):
        tmp = self.__slots
        self.__size = new_size
        self.__slots = [None] * new_size
        for _ in tmp:
            if _ != None:
                self.put(_)

class QuadraticHashTable:
    def __init__(self, size = 7):
        self.__size = size
        self.__slots = [None] * size
    def __str__(self):
        return f"{self.__slots}"
    def get_hash_code(self, key):
        return key % self.__size
    def get_size(self):
        return self.__size
    def put(self, key):
        if self.__len__() == self.__size:
            raise IndexError("ERROR: The hash table is full.")
            return
        index = self.get_hash_code(key)
        if self.__slots[index] == None:
            self.__slots[index] = key
        else:
            for i in range(1, self.__size):
                distance = i * i
                new_index = self.get_new_hash_code_quadratic_probing(index, distance)
                if self.__slots[new_index] == None:
                    self.__slots[new_index] = key
                    return
    def __len__(self):
        return self.__size - self.__slots.count(None)
    def get_new_hash_code_quadratic_probing(self, index, distance):
        return (index + distance) % self.__size
    def is_empty(self):
        return [None] * self.__size == self.__slots
    def clear(self):
        self.__slots = [None] * self.__size
    def rehashing(self, new_size):
        tmp = self.__slots
        self.__size = new_size
        self.__slots = [None] * new_size
        for _ in tmp:
            if _ != None:
                self.put(_)

class DoubleHashTable:
    def __init__(self, size = 7, second_hash_value = 5):
        self.__size = size
        self.__slots = [None] * size
        self.__second_hash_value = second_hash_value
    def __str__(self):
        return f"{self.__slots}"
    def get_hash_code(self, key):
        return key % self.__size
    def get_size(self):
        return self.__size
    def put(self, key):
        if self.__len__() == self.__size:
            raise IndexError("ERROR: The hash table is full.")
            return
        index = self.get_hash_code(key)
        if self.__slots[index] == None:
            self.__slots[index] = key
        else:
            step_value = self.get_new_hash_code_double_hashing(key)
            while self.__slots[index] != None:
                index = (index + step_value) % self.__size
            self.__slots[index] = key
    def __len__(self):
        return self.__size - self.__slots.count(None)
    def get_new_hash_code_double_hashing(self, key):
        return self.__second_hash_value - ( key % self.__second_hash_value )
    def is_empty(self):
        return [None] * self.__size == self.__slots
    def clear(self):
        self.__slots = [None] * self.__size
    def rehashing(self, new_size):
        tmp = self.__slots
        self.__size = new_size
        self.__slots = [None] * new_size
        for _ in tmp:
            if _ != None:
                self.put(_)

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

class LinkedList:
    def __init__(self):
        self.__head = None
        self.__size = 0
    def add(self, value):
        self.__head = Node(value, self.__head)
        self.__size += 1
    def size(self):
        return self.__size
    def get_head(self):
        return self.__head
    def clear(self):
        self.__head = None
        self.__size = 0
    def is_empty(self):
        return self.__head == None
    def __len__(self):
        return self.__size
    def __str__(self):
        s = "["
        current = self.__head
        while current!= None:
            s += f"{current.get_data()}"
            current = current.get_next()
            if current != None:
                s += ", "
        s += "]"
        return s

class LinkedListHashTable:
    def __init__(self, size = 7):
        self.__size = size
        self.__slots = [ LinkedList() for i in range(size) ]
    def get_hash_code(self, key):
        return key % self.__size
    def __str__(self):
        s = ""
        for _ in self.__slots:
            s += f"{_}\n"
        return s[:-1]
    def put(self, key):
        index = self.get_hash_code(key)
        self.__slots[index].add(key)
    def __len__(self):
        cnt = 0
        for _ in self.__slots:
            cnt += len(_)
        return cnt
hash_table = LinkedListHashTable()
print(hash_table.get_hash_code(2))
print(hash_table.get_hash_code(15))
print(hash_table)


    