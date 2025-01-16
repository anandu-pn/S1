# qn 10 roots of the equation
from math import*
a=int(input("enter the coefficient of x^2: "))
b=int(input("enter the coefficient of x :"))
c=int(input("enter the constant :"))
r1=0
r2=0
d=b*b-(4*a*c)
if (d)>=0:
        r1=(-b+sqrt(d))/(2*a)
        r2=(-b-sqrt(d))/(2*a)
        print("the roots of the equation are",r1,"and",r2)

else:
       r=-b/(2*a)
       i=sqrt(-d)/(2*a)
       print("the roots of the equation are",r,"+",i,"i","and",r,"-",i,"i")
       