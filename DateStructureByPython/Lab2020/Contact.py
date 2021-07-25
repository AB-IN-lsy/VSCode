class Contact:
    def __init__(self, name, phone_number, email, status = True):
        self.__name = name
        self.__phone_number = phone_number
        self.__email = email
        self.__status = status
    
    def get_name(self):
        return self.__name
    
    def get_phone_number(self):
        return self.__phone_number
    
    def get_email(self):
        return self.__email
    
    def is_active(self):
        return self.__status
    
    def set_phone_number(self, phone_number):
        self.__phone_number = phone_number
    
    def set_email(self, email):
        self.__email = email
    
    def set_active(self, value):
        self.__status = value
    
    def __str__(self):
        if self.__status == False:
            return f"{self.get_name()} is an inactive record."
        else:
            return f"{self.get_name()} ({self.get_phone_number()}), {self.get_email()}"

class PhoneBook:
    
    def __init__(self):
        self.__phone_book = []
    
    def load_records(self, filename):
        try:
            with open(filename, "r") as f:
                for lines in f.readlines():
                    n, p, e = lines.strip().split(",")
                    self.__phone_book.append( Contact(n, p, e) )
                print(f"{len(self.__phone_book)} records loaded.")
        except FileNotFoundError:
            print(f"ERROR: The file '{filename}' does not exist.")
    
    def show_all_records(self):
        for i in self.__phone_book:
            print(i)
    
    def __len__(self):
        return len(self.__phone_book)
    
    def find_record(self, search_name):
        for i in self.__phone_book:
            if i.get_name() == search_name:
                return i
        return None
    
    def update_phone(self, search_name, phone_number):
        for i in self.__phone_book:
            if i.get_name() == search_name:
                i.set_phone_number(phone_number)
                print(f"{search_name}'s contact is updated.")
                return
        print(f"ERROR: {search_name} is not found.")
    
    def set_active(self, search_name):
        for i in self.__phone_book:
            if i.get_name() == search_name:
                i.set_active(True)
                print(f"{search_name} is active from now on.")
                return
        print(f"ERROR: {search_name} is not found.")
    
    def set_inactive(self, search_name):
        for i in self.__phone_book:
            if i.get_name() == search_name:
                i.set_active(False)
                print(f"{search_name} is inactive from now on.")
                return
        print(f"ERROR: {search_name} is not found.")
    
    def show_active_records(self):
        for i in self.__phone_book:
            if i.is_active() == True:
                print(i)
