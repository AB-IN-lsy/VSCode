def test_kmp():
    # Test cases
    tests = [
        ("ababcabcabababd", "ababd"),  # Pattern at the end
        ("abcabcabcabc", "abc"),      # Pattern repeated multiple times
        ("aaaaaa", "aaa"),            # Overlapping pattern
        ("abcd", "e"),                # Pattern not in string
        ("abacabadabacaba", "abacaba")  # Pattern at the start and end
    ]

    for s, p in tests:
        kmp = Std.Kmp(p)
        result = kmp.search(s)
        print(f"Text: {s}, Pattern: {p}, Match indices: {result}")


test_kmp()