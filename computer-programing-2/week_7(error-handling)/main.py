import time
import os
import random

money = 0
run_loop = True

def work_get():
    global money
    print("Working..")
    earn = random.randint(50, 200)
    time.sleep(2)
    money += earn
    print(f"You earned +{earn} PHP!")
    input("Enter to continue..")

def withdraw():
    global money
    if money <= 0:
        print("Zero cash can't withdraw")
        input("Enter to continue..")
        return

    withdraw_amount_in = input("Enter a withdraw amount: ")

    try:
        withdraw_amount = int(withdraw_amount_in)

        if withdraw_amount > money:
            raise ValueError("Insufficient funds.")
        elif withdraw_amount <= 0:
            raise ValueError("Withraw amount cannot be negative.")
        else:
            money -= withdraw_amount
            print("Withdraw successful.")
            input("Enter to continue..")
    except ValueError as err:
        print(str(err))
        input("Enter to continue..")

while run_loop:
    os.system('clear')
    print("-- Simple withrawal system --")
    print("[ 1 ] - Work or Get Money.")
    print("[ 2 ] - Withdraw Money.")
    print("[ 3 ] - Exit.")
    print(f"\nCurrent Cash: [ {money} PHP ]")

    user_in = input("Enter an option: ")

    try:
        user_cmd = int(user_in)

        if user_cmd == 1:
            work_get()
        elif user_cmd == 2:
            withdraw()
        elif user_cmd == 3:
            run_loop = False
    except ValueError:
        print("Invalid command.")
        input("Enter an option..")

print("Thanks for using this program. Goodbye!")
