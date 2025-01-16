string = input("Enter a string: ")
x=string[-1] + string[1:len(string)-1] + string[0]
print(x)