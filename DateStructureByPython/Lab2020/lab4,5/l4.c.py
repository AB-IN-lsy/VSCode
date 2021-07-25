class ValueError(Exception):
        def __init__(self, arg):
            self.args = arg
def get_volume(radius, height):
    import math
    try:
        if radius < 0 and height < 0:
            raise ValueError("All < 0")
        elif radius == 0 or height == 0:
            raise ValueError("Either = 0")
        elif radius < 0:
            raise ValueError("r < 0")
        elif height < 0:
            raise ValueError("h < 0")
        else:
            return round(math.pi * radius * radius * height)
    except ValueError as e:
        s = "".join(e.args)
        if s == "All < 0":
            return "ERROR: Height and radius must be positive."
        if s == "Either = 0":
            return "ERROR: Not a cylinder."
        if s == "r < 0" :
            return "ERROR: Radius must be positive."
        if s == "h < 0":
            return "ERROR: Height must be positive."
    except TypeError:
        return "ERROR: Invalid input."
'''
print(get_volume(10.5, 2.5)) 
print(get_volume(-10, 2))
print(get_volume(10, -2))
print(get_volume(-10, -2))
print(get_volume(10, 0))
print(get_volume('ten', 2))
'''
