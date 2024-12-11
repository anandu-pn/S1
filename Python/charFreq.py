#character frequency
x=input("Enter the srting: ")
frequency={}
for char in x:
    if char in frequency:
        frequency[char] += 1
    else:
        frequency[char] = 1

print(frequency)