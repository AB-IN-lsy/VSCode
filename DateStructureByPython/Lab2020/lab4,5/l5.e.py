def read_scores(filename):
    if filename == "":
        print ("ERROR: Invalid filename!")
        return
    if  not isinstance(filename , str):
        print( "ERROR: Invalid input!" )
        return
    try:
        input_file = open(filename, "r")
    except FileNotFoundError:
        print(f"ERROR: The file '{filename}' does not exist.")
        return
    try:
        scores = input_file.read().split()
        numbers = [float(score) for score in scores if float(score) >= 0 ]
        input_file.close()
    except ValueError:
        print("ERROR: The input file contains invalid values.")
        return
    if numbers == []:
        print("ERROR: No positive scores in the input file.")
        return
    number_of_marks = len(numbers)
    total_marks = sum(numbers)
    print("There are {} score(s).".format(number_of_marks))
    print("The total is {:.2f}.".format(total_marks))
    print("The average is {:.2f}.".format(total_marks/number_of_marks))

read_scores(123)
read_scores("")
read_scores('input_unknown.txt')
read_scores('empty.txt')
read_scores('all_negatives.txt')