#gcd of two numbers
x=int(input("Enter the first number: "))
y=int(input("Enter the second number: "))
if x>y:
    t=y
else:
    t=x
for i in range (t,0,-1):
   
    if x%i==0 and y%i==0:
    
        break
    
    
print("the gcd of two numbers is :",i)
    
