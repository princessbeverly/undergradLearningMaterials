from abc import ABC, abstractmethod

class Pet(ABC):
    def __init__(self, name, age, color, owner):
        self.name = name
        self.age = age
        self.color = color
        self.owner = owner
    
    @abstractmethod
    def get_info(self):
        pass
    
    @abstractmethod
    def toys(self):
        pass

class Dog(Pet):
    def get_info(self):
        return f"{self.name} is {self.age} years old, {self.color}, and owned by {self.owner}."

    def toys(self):
        return f"{self.name} loves to play with a ball."

class Cat(Pet):
    def get_info(self):
        return f"{self.name} is {self.age} years old, {self.color}, and owned by {self.owner}."

    def toys(self):
        return f"{self.name} loves to play with a mouse."

class Bird(Pet):
    def get_info(self):
        return f"{self.name} is {self.age} years old, {self.color}, and owned by {self.owner}."

    def toys(self):
        return f"{self.name} loves to play with a ball."

pets = [Dog("Maxie", 10, "Golden", "Olivia"), Cat("Malone", 3, "Gray", "Cathy"), Bird("Bethany", 4, "Blue", "Alex")]

for pet in pets:
    print(pet.get_info())
    print(pet.toys())
