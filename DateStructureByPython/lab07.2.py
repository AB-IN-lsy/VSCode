import math
class QuadraticEquation:
    def __init__(self, coeff_a = 1, coeff_b = 1, coeff_c = 1):
        self.__coeff_a = coeff_a
        self.__coeff_b = coeff_b
        self.__coeff_c = coeff_c
    def get_coeff_a(self):
        return self.__coeff_a
    def get_coeff_b(self):
        return self.__coeff_b
    def get_coeff_c(self):
        return self.__coeff_c
    def get_discriminant(self):
        return self.__coeff_b ** 2 - 4 * self.__coeff_a * self.__coeff_c
    def has_solution(self):
        return self.get_discriminant() >= 0
    def get_root1(self):
        return ((-1)*self.get_coeff_b() + math.sqrt(self.get_discriminant())) / (2 * self.get_coeff_a())
    def get_root2(self):
        return ((-1)*self.get_coeff_b() - math.sqrt(self.get_discriminant())) / (2 * self.get_coeff_a())
    def __str__(self):
        q = self.get_discriminant()
        if q < 0:
            return f'The equation has no roots.'
        elif q == 0:
            return f'The root is {self.get_root1():.2f}.'
        else:
            return f'The roots are {self.get_root1():.2f} and {self.get_root2():.2f}.'

