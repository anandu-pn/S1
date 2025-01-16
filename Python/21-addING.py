#Add ‘ing’ at the end of a given string. If it already ends with ‘ing’, add ‘ly’ 
x=input("Enter the string:")
if (x[-3:]=="ing"):
    x=x+"ly"
else:
    x=x+"ing"
print(x)
