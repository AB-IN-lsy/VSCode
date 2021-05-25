def is_valid_radius(num):
    try:
        if num > 0:
            return True
        else:
            raise ValueError
    except (ValueError , TypeError):
        return "ERROR: Invalid radius!"

