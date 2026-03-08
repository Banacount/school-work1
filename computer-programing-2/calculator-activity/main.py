
steps = 0
textLabel = "Enter a number: "
number_2 = None
number_1 = None
operation = -2

while True:
    if steps == 0:
        getInput = input(textLabel)
        try:
            number_1 = int(getInput)
            textLabel = "Enter an operation(+/-/*/'/'): "
            steps = 1
        except ValueError:
            textLabel = "Please enter a number: "
            continue

    if steps == 1:
        getInput = input(textLabel)
        if getInput == "+": operation = 0
        elif getInput == "-": operation = 1
        elif getInput == "*": operation = 2
        elif getInput == "/": operation = 3
        else:
            textLabel = "Please enter an operation(+/-/*/'/'): "
            continue

        if operation >= 0:
            textLabel = "Enter a number: "
            steps = 2

    if steps == 2:
        getInput = input(textLabel)
        try:
            number_2 = int(getInput)
        except ValueError:
            textLabel = "Please enter a number: "
            continue

    if operation == 0:
        print(f"{number_1} + {number_2} = {number_1 + number_2}")
    elif operation == 1:
        print(f"{number_1} - {number_2} = {number_1 - number_2}")
    elif operation == 2:
        print(f"{number_1} * {number_2} = {number_1 * number_2}")
    elif operation == 3:
        print(f"{number_1} / {number_2} = {number_1 / number_2}")
    else:
        print("Invalid operation.")
        break

    print("Exiting..")
    break
