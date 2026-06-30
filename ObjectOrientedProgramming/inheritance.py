# PRINCESS BEVERLY R. ALA-AN 
# Parent class
class Planet:
    def __init__(self, name, size):
        self.name = name
        self.size = size

    def get_info(self):
        return f"The planet {self.name} is {self.size} in size."

# Child classes inheriting from Planet
class GasGiant(Planet):
    def __init__(self, name, size, rings):
        super().__init__(name, size)
        self.rings = rings

    def get_info(self):
        return f"The gas giant {self.name} is {self.size} in size and has rings: {self.rings}."

class TerrestrialPlanet(Planet):
    def __init__(self, name, size, has_life):
        super().__init__(name, size)
        self.has_life = has_life

    def get_info(self):
        life_info = "has life" if self.has_life else "does not have life"
        return f"The terrestrial planet {self.name} is {self.size} in size and {life_info}."
         
# Creating instances of the classes
jupiter = GasGiant("Jupiter", "Very large", True)
earth = TerrestrialPlanet("Earth", "Medium", True)

# Accessing methods from the parent and child classes
print(jupiter.get_info())  
print(earth.get_info())    
