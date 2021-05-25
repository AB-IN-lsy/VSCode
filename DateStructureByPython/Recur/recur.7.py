def evaluate_m(i):
    if i == 1:
        return 1
    else:
        return 1 / i + evaluate_m(i - 1)

print('{} : {}'.format(2, evaluate_m(2)))
print('{} : {:.4}'.format(5, evaluate_m(5)))