class Member:
    def __init__(self, member_id, name):
        self.__member_id = member_id
        self.__name = name
        self.__on_loan_books_list = []
    def get_name(self):
        return self.__name
    def get_member_id(self):
        return self.__member_id
    
    