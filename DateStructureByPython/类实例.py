class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y
    def halfway(self, other1, other2):
        return Point( (self.x + other1.x + other2.x) / 3, (self.y + other1.y + other2.y) / 3)
    def __str__(self):
        return f"x = {self.x} y = {self.y}"
p = Point(2, 4)
q = Point(1, 3)
z = Point(2, 5)
print( p.halfway(q, z) )
