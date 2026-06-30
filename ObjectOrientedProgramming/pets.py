from abc import ABC, abstractmethod

class Pets(ABC):
    def __init__(self, name, age, color, owner):
        self.name = name
        self.age = age
        self.color = color
        self.owner = owner
    
    @abstractmethod
    
    def getinfo(self):
        pass
    
    @abstractmethod
    def toys(self):
        pass

class Dog(Pets):
    def getinfo(self):
        return f"{self.name} is {self.age} years old and is {self.color} owned by {self.owner}"
    
    def toys(self):
        return f"{self.name} plays with a ball."

class Cat(Pets):
    def getinfo(self):
        return f"{self.name} is {self.age} years old and is {self.color} owned by {self.owner}"

    def toys(self):
        return f"{self.name} plays with a mouse."
    
class Bird(Pets):
    def getinfo(self):
        return f"{self.name} is {self.age} years old and is {self.color} owned by {self.owner}"
    
    def toys(self):
        return f"{self.name} plays with a pebbles."

pets = [Dog("Maxie", 3, "Golden Brown", "Anabelle"), Cat("Benjamin", 4, "Gray", "Alex"), Bird("Arthur", 5, "Blue", "Anabeth")]

for pet in pets:
    print(pet.getinfo())
    print(pet.toys())