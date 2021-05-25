class Rectangle:
    def __init__ (self , width = 10 , height = 10):
        self.__width = width
        self.__height = height
    def get_width(self):
        return self.__width
    def get_height(self):
        return self.__height
    def __repr__(self):
       return f'Rectangle({self.__width}, {self.__height})'
    def __str__(self):
        return f'{self.__width} x {self.__height}'
    def get_area(self):
        return self.__width * self.__height
    def get_perimeter(self):
        return 2 * (self.__width + self.__height)
r1 = Rectangle(3, 4)
print( r1 )
