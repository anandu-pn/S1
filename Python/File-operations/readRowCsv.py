import csv
file=open('C:/Users/cacet/Desktop/anan/S1/Python/File-operations/employee.csv','r')
rows=csv.reader(file)
for row in rows:
    print(row)
file.close
#can also do without without csv function
file=open('C:/Users/cacet/Desktop/anan/S1/Python/File-operations/employee.csv','r',encoding='utf-8')
row2=file.readline()
for line in row2:
    row3=line.strip().split(',')
    print(row3)