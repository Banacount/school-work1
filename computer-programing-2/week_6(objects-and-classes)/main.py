import os

class Item:
    def __init__(self, item_name: str = "N/a", item_price: int = 0, item_quantity: int = 1):
        self.item_name = item_name
        self.item_price = item_price
        self.item_quantity = item_quantity
        self.total_price = item_price * item_quantity

    def itemInfo(self):
        print(f"{self.item_name}: {self.item_price}PHP, {self.item_quantity}x")

    def itemInfoInList(self, numbering):
        print(f"{numbering}. {self.item_name: <15.15}  | {self.item_price: <16.2f} |")


def clearTrigger():
    os.system("clear")


# General variables
isRunning = True
cart = []

items = [
    Item("Cola mismo", 25),
    Item("Chicharon", 12),
    Item("Pancit Canton", 15),
    Item("External Misery Deluxe", 1500)
]

def main():
    global isRunning
    displayItems()

    while isRunning:
        user_cmd = input("Enter command $> ")

        # Add items to cart
        if user_cmd == "add":
            addCart()
        elif user_cmd == "remove":
            removeItemInCart()
        elif user_cmd == "items":
            displayItems()
        elif user_cmd == "checkout":
            checkoutFunc()
        elif user_cmd == "exit":
            print("Goodbye!")
            isRunning = False
            break
        elif user_cmd == "":
            clearTrigger()
        else:
            print("Command is invalid.")


# --  Command Functions --
def addCart():
    item_want = input("Enter the index or name of the item: ")
    item_index = -1

    try:
        item_index = int(item_want)
    except ValueError:
        for i, per_item in enumerate(items):
            if item_want in per_item.item_name:
                item_index = i
                break

    if item_index < 0 or item_index > (len(items)-1):
        print("No item found.")
    else:
        cart.append(items[item_index])
        print(f"Item '{items[item_index].item_name}' has been added to the cart.")


def removeItemInCart():
    item_want = input("Enter the index or name of the item: ")
    item_index = -1

    try:
        item_index = int(item_want)
    except ValueError:
        for i, per_item in enumerate(cart):
            if item_want in per_item.item_name:
                item_index = i
                break

    if item_index < 0 or item_index > (len(cart)-1):
        print("No item found.")
    else:
        temp_item = cart[item_index]
        cart.pop(item_index)
        print(f"Item '{temp_item.item_name}' has been removed to the cart.")


def checkoutFunc():
    global cart
    cart = []
    print("The cart has been checked out.")


def displayItems():
    print("----------------------------------------")
    print(f"    {"Items": ^15.15} | {"Price": ^16} |")
    print("----------------------------------------")
    for i, item in enumerate(items):
        item.itemInfoInList(i)
    print("----------------------------------------")

    if len(cart) <= 0:
        print("\n( No items in cart. Add items using 'add' )")
    else:
        print("\n<=== Items in cart ===>")
        print("----------------------------------------")
        print(f"    {"Items": ^15.15} | {"Price": ^16} |")
        print("----------------------------------------")
        for i, item in enumerate(cart):
            item.itemInfoInList(i)
        print("----------------------------------------")
        print("\n( Delete items in cart with 'remove' )")
        print("( Checkout items in cart with 'checkout' )")


# Run main loop
if __name__ == "__main__":
    main()
