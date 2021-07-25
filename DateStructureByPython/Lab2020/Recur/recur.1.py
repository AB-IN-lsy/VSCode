def count_consonants(word):
    if not word:
        return 0
    return 'bcdfjhjklmnpqrstvwxyz'.count(word[0].lower()) + count_consonants(word[1:])

print(count_consonants('This is a Test'))
