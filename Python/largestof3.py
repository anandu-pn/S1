#qn 3 largest of 3 numb
x=int(input("enter the first number"))
y=int(input("enter the second number"))
z=int(input("enter the third number"))
if x>y and x>z:
    print(x,"is the largest number among the three")
elif y>z and y>x:
     print(y,"is the largest number among the three")
else:
    print(z,"is the greatest number among the three")
    
