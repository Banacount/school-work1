
MSGFILE = "message.txt"
# Initialize file here
try:
    file = open(MSGFILE, "x")
    file.write("")
    file.close()
    print("Created a message.txt file.")
except FileExistsError:
    print("")

# Functions
def sendMessage(message: str):
    try:
        with open(MSGFILE, "a") as file:
            file.write(message + "\n")
        print("Message sent!")
    except:
        print("Error: Check if message.txt exists.")

def viewMessages():
    try:
        with open(MSGFILE, "r") as file:
            print("\n-- Messages --")
            for line in file: print(line, end="")
    except:
        print("Error: Check if message.txt exists.")

isRun = True
while isRun:
    print("Welcome to Messaging App")
    print("1. Send Message")
    print("2. View Messages")
    print("3. Exit")

    user_in = input("Enter choice: ")

    if user_in == "1":
        user_msg = input("Enter your message: ")
        sendMessage(user_msg)
    elif user_in == "2":
        viewMessages()
    elif user_in == "3":
        isRun = False

    print("")

