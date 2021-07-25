def get_maori_word(dictionary, word):
    try:
        return dictionary[word]
    except KeyError:
        return f"ERROR: {word} is not available."
dictionary ={'example': 'tauira', 'house': 'whare', 'apple': 'aporo', 'love': 'aroha', 'food': 'kai',
'hello': 'kiaora', 'work': 'mana', 'weather': 'huarere', 'greenstone': 'pounamu',
'red': 'whero', 'orange': 'karaka', 'black': 'mangu'}

print(get_maori_word(dictionary, 'house'))

print(get_maori_word(dictionary, 'orange'))
print(get_maori_word(dictionary, 'tooth'))
print(get_maori_word(dictionary, 'country'))
print(get_maori_word(dictionary, 'city'))