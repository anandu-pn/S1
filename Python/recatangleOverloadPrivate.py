class Rectangle:
    def __init__(self, length, breadth):
        #here the "__" are the private atributes it cannot accesed outside of the class
        self.__length = length
        self.__breadth = breadth

    def area(self):
        return self.__length * self.__breadth

    def __lt__(self, other):
        return self.area() < other.area()

# Example usage
l1=int(input("enter the length and length of the rectangle:"))
b1=int(input("enter the length and bredth of the rectangle:"))
l2=int(input("enter the length and length of the rectangle:"))
b2=int(input("enter the length and bredth of the rectangle:"))
rect1 = Rectangle(l1, b1)
rect2 = Rectangle(l2, b2)

if rect1 < rect2:
    print("Rectangle 1 has a smaller area than Rectangle 2")
else:
    print("Rectangle 1 has a larger or equal area compared to Rectangle 2")
