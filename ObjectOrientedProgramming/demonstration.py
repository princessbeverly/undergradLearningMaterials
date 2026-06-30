from abc import ABC, abstractmethod

class Vehicle(ABC):
    def __init__(self, make, model):
        self.make = make
        self.model = model

    @abstractmethod
    def start(self):
        pass

    @abstractmethod
    def stop(self):
        pass

class Car(Vehicle):
    def start(self):
        return f"{self.make} {self.model} starts its engine."

    def stop(self):
        return f"{self.make} {self.model} stops its engine."

class Truck(Vehicle):
    def start(self):
        return f"{self.make} {self.model} starts its diesel engine."

    def stop(self):
        return f"{self.make} {self.model} stops its diesel engine."

# Create a list of vehicles
vehicles = [Car("Toyota", "Camry"), Truck("Ford", "F-150")]

# Iterate over the vehicles and call the same method on each
for vehicle in vehicles:
    print(vehicle.start())
    print(vehicle.stop())