while True:
    password = input("Enter a password: ")

    hasLetter = any(let.isalpha() for let in password)
    hasNum = any(let.isdigit() for let in password)
    if hasLetter and hasNum:
        print("Password accepted.")
        break
    else:
        print("Invalid password. Try again.")
