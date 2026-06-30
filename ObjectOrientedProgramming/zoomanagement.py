from abc import ABC, abstractmethod
#PRINCESS BEVERLY R. ALA-AN 
class Animal(ABC):
    @abstractmethod
    def __init__(self, name, age):
        """
        Initialize an animal with its name and age.

        Parameters:
        name (str): The name of the animal.
        age (int): The age of the animal.
        """
        self.__name = name  # 2 underscores before variable name sets it private
        self.__age = age
    
    @abstractmethod
    def make_sound(self):
        """
        Make the animal produce its characteristic sound.
        """
        pass

    @property
    def name(self):
        """
        Get the name of the animal.
        """
        return self.__name
    
    @property
    def age(self):
        """
        Get the age of the animal.
        """
        return self.__age

class Dog(Animal):
    def __init__(self, name, age, type):
        """
        Initialize a Lion with its name, age, and type.

        Parameters:
        name (str): The name of the lion.
        age (int): The age of the lion.
        type (str): The type of lion (e.g., "African Lion", "Asian Lion").
        """
        super().__init__(name, age)
        self.type = type
    
    def make_sound(self):
        return "Arf!"

class Bird(Animal):
    def __init__(self, name, age, wing_span):
        """
        Initialize a Bird with its name, age, and wing span.

        Parameters:
        name (str): The name of the bird.
        age (int): The age of the bird.
        wing_span (float): The wing span of the bird.
        """
        super().__init__(name, age)
        self.wing_span = wing_span
    
    def make_sound(self):
        return "Tweet tweet!"

# Define other animal classes similarly...
class Fish(Animal):
    def __init__(self, name, age, type):
        super().__init__(name, age)
        self.type = type
    
    def make_sound(self):
        return "Glub glub glub"
        
class Zoo:
    def __init__(self):
        self.animals = []
    
    def add_animal(self, animal):
        """
        Add an animal to the zoo.

        Parameters:
        animal (Animal): The animal object to be added to the zoo.
        """
        if animal not in self.animals:
            self.animals.append(animal)
    
    def remove_animal(self, animal):
        """
        Remove an animal from the zoo.

        Parameters:
        animal (Animal): The animal object to be removed from the zoo.
        """
        if animal in self.animals:
            self.animals.remove(animal)

    def print_animals(self):
        """
        Print information about all animals in the zoo.
        """
        for animal in self.animals:
            print(f"{animal.__class__.__name__}: {animal.name}, {animal.age} years old")
            print(animal.make_sound())

# Example usage:
zoo = Zoo()

# User interface
while True:
    print("\n1. Add an animal")
    print("2. Remove an animal")
    print("3. Display all animals")
    print("4. Make all animals make a sound")
    print("5. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        animal_type = input("Enter the type of animal (Dog, Bird, Fish): ")
        name = input("Enter the name of the animal: ")
        age = int(input("Enter the age of the animal: "))
        
        if animal_type == "Dog":
            breed = input("Enter the breed of the dog: ")
            zoo.add_animal(Dog(name, age, breed))
        elif animal_type == "Bird":
            wing_span = float(input("Enter the wing span of the bird: "))
            zoo.add_animal(Bird(name, age, wing_span))
        elif animal_type == "Fish":
            fish_type = input("Enter the type of fish: ")
            zoo.add_animal(Fish(name, age, fish_type))
        else:
            print("Invalid animal type")
    elif choice == "2":
        name = input("Enter the name of the animal to remove: ")
        for animal in zoo.animals:
            if animal.name == name:
                zoo.remove_animal(animal)
                break
        else:
            print("Animal not found")
    elif choice == "3":
        zoo.print_animals()
    elif choice == "4":
        for animal in zoo.animals:
            print(animal.make_sound())
    elif choice == "5":
        break
    else:
        print("Invalid choice. Please try again.")

