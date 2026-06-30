from abc import ABC, abstractmethod

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
        '''
        Initialize a Bird with its name, age, and wing span.

        Parameters:
        name (str): The name of the bird.
        age (int): The age of the bird.
        wing_span (float): The wing span of the bird.
        '''
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
dog = Dog()
lion = Lion("Simba", 5, "African Lion")
bird = Bird("Polly", 2, "Large")
zoo.add_animal(lion)
zoo.add_animal(bird)

# User interface
while True:
    print("\n1. Add an animal")
    print("2. Remove an animal")
    print("3. Display all animals")
    print("4. Make all animals make a sound")
    print("5. Exit")

    choice = input("Enter your choice: ")

    if choice == "1":
        name = input("Enter the name of the animal: ")
        age = int(input("Enter the age of the animal: "))
        type = input("Enter what type of animal: ")
            if(type == 'Lion'){
                self.breed = input("What breed?")
            }else if(type == 'Bird'){
                self.wing_span = int(input("Enter the wing spand of the bird:"))
            }else if(type == 'Fish'){
                type = input("What type of fish?")
            }else{
                print("Invalid Animal")
            }
        # Add more input prompts for additional attributes of the animal
        # Based on the selected animal type
        # Then create the animal object and add it to the zoo
    elif choice == "2":
        # Implement removal of an animal from the zoo
        pass
    elif choice == "3":
        zoo.print_animals()
    elif choice == "4":
        for animal in zoo.animals:
            print(animal.make_sound())
    elif choice == "5":
        break
    else:
        print("Invalid choice. Please try again.")
