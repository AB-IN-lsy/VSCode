def get_first_lower_case(s):
    try:
        if s[0].islower():
            return s[0]
        else:
            return get_first_lower_case(s[1:])
    except:
        return None

s = 'WELL done'
print(get_first_lower_case(s))

s = 'GREAT'		
print(get_first_lower_case(s))
