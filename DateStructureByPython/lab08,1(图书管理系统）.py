class Book:
    def __init__(self, code, title, status = True):
        self.__code = code
        self.__title = title
        self.__status = status
    def get_book_title(self):
        return self.__title
    def get_book_code(self):
        return self.__code
    def is_available(self):
        return self.__status
    def borrow_book(self):
        self.__status = False
    def return_book(self):
        self.__status = True
    def __str__(self):
        s = ""
        if self.__status == True:
            s = "Available"
        else:
            s = "On Loan"
        return f"{self.__title}, {self.__code} ({s})"

class Member:
    def __init__(self, member_id, name):
        self.__member_id = member_id
        self.__name = name
        self.__on_loan_books_list = []
    def get_name(self):
        return self.__name
    def get_member_id(self):
        return self.__member_id
    def borrow_book(self, book):
        self.__on_loan_books_list.append(Book.get_book_title(book))
    def return_book(self, book):
        self.__on_loan_books_list.remove(Book.get_book_title(book))
    def __str__(self):
        s = ""
        s += f"{self.__name}\n"
        s += "On loan book(s):\n"
        if self.__on_loan_books_list:
            s += "\n".join(self.__on_loan_books_list)
            return s
        else:
            s += "-"
            return s
class Record:
    def __init__(self, book, member, date):
        self.__book = book
        self.__member = member
        self.__issue_date = date
        self.__book.borrow_book()
        self.__member.borrow_book(book)
        self.__is_on_loan = not self.__book.is_available()
    def get_member_id(self):
        return self.__member.get_member_id()
    def get_book_code(self):
        return self.__book.get_book_code()
    def get_issue_date(self):
        return self.__issue_date
    def is_on_loan(self):
        return  self.__is_on_loan
    def return_book(self):
        self.__book.return_book()
        self.__member.return_book(self.__book)
        self.__is_on_loan = not self.__book.is_available()
    def __str__(self):
        return f"{self.__member.get_name()}, {self.__book.__str__()}, issued date={self.__issue_date}"

class MyLibrary:
    def __init__(self, filename):
        self.__book_list = []
        self.__on_loan_records_list = []
        self.__record__list = []
        try:
            with open(filename, "r") as f:
                cnt = 0
                for line in f:
                    code, title = line.strip().split(",")
                    self.__book_list.append( Book(code, title) )
                    cnt += 1
            self.__cnt = cnt
            print(f"{self.__cnt} books loaded.")
        except FileNotFoundError:
            print(f"ERROR: The file '{filename}' does not exist.")
    def show_all_books(self):
        for book in self.__book_list:
            print(book)
    def find_book(self, code):
        for book in self.__book_list:
            if book.get_book_code() == code and book.is_available():
                return book
        return None
    def borrow_book(self, book, member, issue_date):
        if book:
            self.__on_loan_records_list.append( Record(book, member, issue_date) )
            self.__record__list.append( Record(book, member, issue_date) )
            print(f"{book.get_book_title()} is borrowed by {member.get_name()}.")
        else:
            print("ERROR: could not issue the book.")
    def show_available_books(self):
        for book in self.__book_list:
            if book.is_available() == True:
                print(book)
    def find_record(self, code):
        for book in self.__book_list:
            if book.get_book_code() == code:
                for record in self.__on_loan_records_list:
                    if record.get_book_code() == code:
                        return record
        return None
    def return_book(self, record):
        if record:
            record.return_book()
            self.__on_loan_records_list.remove(record)
            print(f"{record.get_book_code()} is returned successfully.")
        else:
            print("ERROR: could not return the book.")
    def show_on_loan_records(self):
        for record in self.__on_loan_records_list:
            print(record)
    def show_all_records(self):
        for record in self.__record__list:
            print(record)

library = MyLibrary('simple_books.txt')
m1 = Member(1001, "Michael")
library.borrow_book(library.find_book('QS12.02.003'), m1, "2020-08-12")
library.borrow_book(library.find_book('QK12.04.002'), m1, "2020-08-15")
library.return_book(library.find_record('QK12.04.002'))
library.show_on_loan_records()
library.show_all_records()