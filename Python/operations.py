x=float(input("Enter the first number:"))
y=float(input("enter the second number:"))
z=input("enter the operation +, -, *, /  : ")

if z=='+':
    print("The sum is: ",x+y)
elif z=="-":
    print("the result is :",x-y)
elif z=="*":
    print("the result is :",x*y)
elif z=="/":
    print("the result is :",x/y)
else:
    print("enter the correct operations")
