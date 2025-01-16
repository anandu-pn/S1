file =open('readLine.txt','r')
list=[]
list2=file.readlines()
file.seek(0) # Move the file pointer back to the beginning of the file without using it will becom list as a empty list
for line in file:
    list.append(line.strip())
file.close
print(list)
print(list2)