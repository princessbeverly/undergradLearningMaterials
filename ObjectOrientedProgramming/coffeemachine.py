class Coffee(object):
    def __init__(self, name, base_price):
        self.name = name
        self.base_price = base_price

class Option(object):
    def __init__(self, name, price):
        self.name = name
        self.price = price

class UserProfile(object):
    profiles = [] 
    
    def __init__(self, user_name, preferred_coffee, preferred_options=None, balance=0):
        self.user_name = user_name
        self.preferred_coffee = preferred_coffee
        self.preferred_options = preferred_options if preferred_options else []
        self.balance = balance
        UserProfile.profiles.append(self)

    def add_option(self, option):
        self.preferred_options.append(option)

    def get_option(self, option):
        return self.preferred_options.index(option)

class CoffeeMachine(object):
    def __init__(self):
        self.coffees = []
        self.options = []
        self.current_user = None

    def add_coffee(self, coffee):
        self.coffees.append(coffee)

    def add_option(self, option):
        self.options.append(option)

    def login(self, user_name):
        found_user = next((profile for profile in UserProfile.profiles if profile.user_name == user_name), None)
        if found_user:
            self.current_user = found_user
            print("User profile exists")
            print(f"Logged in as {user_name}")
        else:
            print("User profile not found")

    def get_coffee_price(self, coffee_name, options=None):
        options = options or []
        coffee = next((c for c in self.coffees if c.name == coffee_name), None)
        if coffee:
            price = coffee.base_price
            for opt_name in options:
                option = next((opt for opt in self.options if opt.name == opt_name), None)
                if option:
                    price += option.price
            return price
        else:
            print(f"Coffee '{coffee_name}' not found.")
            return None

    def purchase_coffee(self, coffee_name, options=None):
        if self.current_user:
            options = options or []
            price = self.get_coffee_price(coffee_name, options)
            if price is not None:
                if price <= self.current_user.balance:
                    self.current_user.balance -= price
                    print(f"Purchased {coffee_name} for ${price}")
                    print(f"Remaining balance: ${self.current_user.balance}")
                else:
                    print("Insufficient funds")
        else:
            print("User not logged in")

    def add_user(self, user_name, preferred_coffee, preferred_options=None, balance=0):
        UserProfile(user_name, preferred_coffee, preferred_options, balance)
        print(f"Added user {user_name}")

# Create coffee machine
machine = CoffeeMachine()

# Add coffees and options
machine.add_coffee(Coffee("Espresso", 1.50))
machine.add_coffee(Coffee("Latte", 2.00))
machine.add_option(Option("Milk", 0.50))
machine.add_option(Option("Sugar", 0.25))

# Create user profiles
user1 = UserProfile("John", machine.coffees[0])  # Prefers Espresso
user1.add_option(machine.options[0])  # John likes milk in his coffee

user2 = UserProfile("Jane", machine.coffees[1])  # Prefers Latte
user2.add_option(machine.options[1])  # Jane likes sugar

# Users login
machine.login("John")
machine.login("Jane")

# John purchases coffee
machine.purchase_coffee("Espresso", ["Milk"])  # Espresso with milk

# Jane purchases coffee
machine.purchase_coffee("Latte", ["Sugar"])  # Latte with sugar
