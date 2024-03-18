class vehicle:
    def __init__(self, name, max_speed, miles):
        self.__name = name
        self.__max_speed = max_speed
        self.__miles = miles

    def get_name(self):
        return self.__name

    def get_max_speed(self):
        return self.__max_speed

    def get_miles(self):
        return self.__miles

    def display_info(self):
        print(f"{self.__name}, {self.__max_speed}, {self.__miles}")


class bus(vehicle):
    def __init__(self, name, max_speed, miles, capacity):
        super().__init__(name, max_speed, miles)
        self.__capacity = capacity

    def get_capacity(self):
        return self.__capacity

    def set_capacity(self, new):
        self.__capacity = new

    def display_info(self):
        print(f"{super().get_name()}, {super().get_max_speed()}, {super().get_miles()}, {self.__capacity}")


car1 = vehicle("car", 137, 55)

bus = bus("bussy", 80, 10, 0)
bus.set_capacity(80)

car1.display_info()
bus.display_info()

