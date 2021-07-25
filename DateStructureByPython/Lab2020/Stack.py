class Stack:
    def __init__(self):
        self.__items = []
        #最左边是底，最右边是栈顶
    
    def is_empty(self):
        return self.__items == []
    
    def push(self, item):
        self.__items.append(item)
    
    def pop(self):
        if self.is_empty():
            raise IndexError("ERROR: The stack is empty!")
        else:
            return self.__items.pop()
    
    def peek(self):
        if self.is_empty():
            raise IndexError("ERROR: The stack is empty!")
        else:
            return self.__items[len(self.__items) - 1]       
    
    def __str__(self):
        return f"Stack: {self.__items}"   
    
    def __len__(self):
        return len(self.__items)   
    
    def clear(self):
        self.__items.clear()
    
    def push_list(self, a_list):
        self.__items += a_list
    
    def multi_pop(self, number):
        if self.__len__() < number:
            return False
        else:
            for i in range(number):
                self.pop()
            return True    
    
    def copy(self):
        import copy
        tmp = Stack()
        tmp.__items = copy.deepcopy(self.__items)
        return tmp
    
    def __eq__(self, other):
        try:
            return self.__items == other.__items
        except:
            return False


def is_balanced_brackets(ss):
    muban_z = "([{"
    muban_y = ")]}"
    d = dict(zip(muban_z, muban_y))
    s = Stack()
    for i in ss:
        if i in muban_z:
            s.push(i)
        elif i in muban_y:
            try:
                if d[s.peek()] == i:
                    s.pop()
                else:
                    return False
            except:
                return False
    if s.is_empty():
        return True
    else:
        return False

def evaluate_postfix(postfix_list):
    s = Stack()
    for i in postfix_list:
        if i.isdigit():
            s.push(i)
        else:
            tmp1 = int(s.pop())
            tmp2 = int(s.pop())
            s.push( compute(tmp2, tmp1, i) )
    return s.peek()

def compute(number1, number2, operator):
    if operator == '+':
        return number1 + number2
    elif operator == '-':
        return number1 - number2
    elif operator == '*':
        return number1 * number2
    elif operator == '/':
        return number1 // number2
    elif operator == '^':
        return number1 ** number2
    elif operator == '%':
        return number1 % number2

print(is_balanced_brackets('({x})(())()'))
