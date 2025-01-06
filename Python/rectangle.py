class Rectangle:
    def __init__(self, length, breadth):
        #here the "__" are the private atributes it cannot accesed outside of the class
        self.__length = length
        self.__breadth = breadth

    def area(self):
        return self.__length * self.__breadth
rect1 = Rectangle(10, 12)
rect2 = Rectangle(9, 14)
if rect1.area() < rect2.area():
    print("Rectangle 1 has a smaller area than Rectangle 2")
else:
    print("Rectangle 1 has a larger or equal area compared to Rectangle 2")