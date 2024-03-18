class Queue:
    def __sizeof(self):
        return len(self.__queue)

    def __shift(self):
        new = []
        for i in self.__queue

    def __init__(self, maxsize):
        self.__maxsize = maxsize
        self.__queue = []

    def add(self, data):
        if self.__sizeof(self) < self.__maxsize:
            self.__queue.append(data)

    def remove(self):
        self.__queue.pop(0)
