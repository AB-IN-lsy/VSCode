def get_phone(phones_dictionary, name):
    try:
        if name == "":
            return "ERROR: Invalid name!"
        if  not isinstance(name , str):
            return "ERROR: Invalid input!"
        return phones_dictionary[name]
    except KeyError:
        return f"ERROR: {name} is not available."

phones_dictionary = {'Martin':8202, 'Angela':6620, 'Ann':4947, 'Damir':2391, 'Adriana':7113, 'Andrew':5654}

print(get_phone(phones_dictionary , 'Ann'))
print(get_phone(phones_dictionary , 'Daniel'))
print(get_phone(phones_dictionary , 123))
print(get_phone(phones_dictionary , ''))