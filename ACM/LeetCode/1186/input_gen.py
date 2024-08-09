import random


class DataGenerator:
    def __init__(self):
        self.generated_data = []

    def gen_n(self, min_val, max_val):
        number = random.randint(min_val, max_val)
        self.generated_data.append(number)
        return number

    def gen_n_(self, min_val, max_val):
        number = random.randint(min_val, max_val)
        return number

    def gen_arr(self, length, min_val, max_val):
        array = [random.randint(min_val, max_val) for _ in range(length)]
        self.generated_data.append(array)
        return array

    def save_to_file(self, filename):
        with open(filename, 'w') as file:
            for item in self.generated_data:
                if isinstance(item, list):
                    file.write(' '.join(map(str, item)) + '\n')
                else:
                    file.write(str(item) + '\n')


gen = DataGenerator()
# n = generator.gen_n(1, 10)
arr = gen.gen_arr(gen.gen_n_(1, 10000), -10000, 10000)
gen.save_to_file('input.txt')
