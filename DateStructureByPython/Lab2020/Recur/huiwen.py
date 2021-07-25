def palindrome_filter(sentence):
    if len(sentence) == 0:
        return sentence
    elif len(sentence) == 1:
        if sentence[0].isalpha():
            return sentence[0].lower()
        else:
            return ""
    elif sentence[0].isalpha():
        return sentence[0].lower() + palindrome_filter(sentence[1:])
    else:
        return palindrome_filter(sentence[1:])

def is_palindrome(sentence):
    if sentence == "":
        return True
    elif sentence[0] != sentence[-1]:
        return False
    else:
        return is_palindrome(sentence[1:-1])

print(is_palindrome(palindrome_filter("Ebla was I ere I saw Elba.")))

