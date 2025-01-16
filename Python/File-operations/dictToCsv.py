import csv
dict={ 'Name': ['Alice', 'Bob', 'Charlie'], 
 'Age': [25, 30, 35], 
 'City': ['New York', 'Los Angeles', 'Chicago']
}
columns=dict.keys()
file=open('C:/Users/user/Desktop/lab/S1/Python/File-operations/newemployee.csv','w',newline='')#this newline is important
writer=csv.writer(file)
writer.writerow(columns)#write first column 
#data.values() returns a view object that displays a list of all the values in the dictionary.
#The * operator is used to unpack the values, so each list of values is passed as a separate argument to zip.
#zip then combines these lists element-wise, creating tuples where each tuple contains one element from each list.
rows=zip(*dict.values())
print(next(rows))
for row in rows:
    writer.writerow(row)
file.close()
file=open('C:/Users/user/Desktop/lab/S1/Python/File-operations/newemployee.csv','r')
rows1=csv.reader(file)
for row in rows1:
    print(row)
file.close()