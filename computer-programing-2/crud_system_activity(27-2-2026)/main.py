
users = []

# Instruction
print("\n<=== Quick User Manager ===>")
print("'add' - Add user to the list.")
print("'list' - See all the user.")
print("'update' - Update user.")
print("'delete' - Delete user on the list.\n")

while True:
    usr_cmd = input("command $> ")

    if usr_cmd == "add":
        getUser = input("Add user: ")
        users.append(getUser)

    elif usr_cmd == "list":
        print("--- Users ---")
        for user in users:
            print(f"> {user}")

    elif usr_cmd == "update":
        getUser = input("User name: ")
        updatedUser = input("Update user: ")
        try:
            getUserIndex = users.index(getUser)
            users[getUserIndex] = updatedUser
        except ValueError:
            print("User doesn't seem to exist.")

    elif usr_cmd == "delete":
        userToDelete = input("Enter username to DELETE: ")
        try:
            userToIndex = users.remove(userToDelete)
        except ValueError:
            print("User doesn't seem to exist.")
    elif usr_cmd == "exit":
        print("See you next time!")
        break
