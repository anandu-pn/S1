class rectangle:
    def __init__(self,length,bredth):
        self.l=length
        self.b=bredth
    def area(self):
        return self.l*self.b
    def perimeter(self):
        return 2*(self.l+self.b)
l1=int(input("enter the length and length of the rectangle:")),
b1=int(input("enter the length and bredth of the rectangle:"))
#l2,b2=float(input("enter the length and bredth of the rectangle")),float(input("enter the length and bredth of the rectangle"))
r1=rectangle(l1,b1)
#r2=rectangle(l2,b2)
#area2=r2.area
print(r1.area())
#print(area2)
#print(f"area of the first rectagle is {r1.area} and the perimeter of the first rectangle is {r1.perimeter}")    
#print(f"area of the second rectagle is {r2.area} and the perimeter of the second rectangle is {r2.perimeter}")
#print(r1.perimeter)

    
        