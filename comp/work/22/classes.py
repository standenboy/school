class Human:
    def __init__(self, name, height, eye):
        self.__name = name
        self.__height = height
        self.__eye = eye

    def set_eye(self, new_color):
        self.__eye = new_color
    
    def get_name(self):
        return self.__name
    
    def get_eye(self):
        return self.__eye

human1 = Human('john','2cm','blue')

human1.set_eye('green')

print(human1.get_eye())
