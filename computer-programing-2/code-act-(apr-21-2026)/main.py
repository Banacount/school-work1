isRun = True

while isRun:
    num_1 = input("Enter number 1: ")
    num_2 = input("Enter number 2: ")
    operation = input("Enter operation: ")

    try:
        num_1 = int(num_1)
        num_2 = int(num_2)

        if operation == "+":
            print(num_1 + num_2)
        elif operation == "-":
            print(num_1 - num_2)
        elif operation == "*":
            print(num_1 * num_2)
        elif operation == "/":
            print(num_1 / num_2)
        else:
            raise ValueError("Not valid operation.")
        isRun = False
    except ValueError:
        print("Invalid input try again.")
