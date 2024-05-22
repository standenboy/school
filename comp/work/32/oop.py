class person:
    def __init__(self, age, name):
        self.__age = age
        self.__name = name

    def getAge(self):
        return self.__age

    def getName(self):
        return self.__name

    def getOlder(self, new):
        self.__age = new


class child(person):
    def __init__(self, age, name, school):
        super().__init__(age, name)
        self.__school = school

    def getSchool(self):
        return self.__school

    def newSchool(self, new):
        self.__school = new


if __name__ == "__main__":
    me = child(17, "lucas", "qmc")
    me.getOlder(18)
    print(me.getName())
