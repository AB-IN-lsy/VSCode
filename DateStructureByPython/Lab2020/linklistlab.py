class Node:
    def __init__(self, data, next=None):
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
        while current != None:
            s += f"{current.get_data()}"
            current = current.get_next()
            if current != None:
                s += ", "
        s += "]"
        return s

    def __contains__(self, search_value):
        current = self.__head
        while current != None:
            if current.get_data() == search_value:
                return True
            current = current.get_next()
        return False

    def __getitem__(self, index):
        current = self.__head
        cnt = 0
        while current != None:
            if cnt == index:
                return current.get_data()
            cnt += 1
            current = current.get_next()

    def add_all(self, a_list):
        for _ in a_list:
            self.add(_)

    def get_min_odd(self):
        current = self.__head
        mn = 999
        while current != None:
            _ = current.get_data()
            if _ & 1:
                mn = min(mn, _)
            current = current.get_next()
        return mn

    def reverse(self):
        current = self.__head
        if current == None or current.get_next() == None:
            return
        end = current.get_next()
        while end != None:
            current.set_next(end.get_next())
            end.set_next(self.__head)
            self.__head = end
            end = current.get_next()


class SquareNumber:
    def __init__(self, count=5):
        self.__count = count

    def __iter__(self):
        return SquareNumberIterator(self.__count)


class SquareNumberIterator:
    def __init__(self, count):
        self.__count = count
        self.__current = 1

    def __next__(self):
        if self.__current > self.__count:
            raise StopIteration
        else:
            self.__current += 1
            return (self.__current - 1)**2


class LinkedListIterator:
    def __init__(self, head):
        self.__current = head

    def __next__(self):
        if self.__current is None:
            raise StopIteration
        data = self.__current.get_data()
        self.__current = self.__current.get_next()
        return data


values = LinkedList()
values.add('cherry')
values.add('banana')
values.add('apple')
for value in values:
    print(value)