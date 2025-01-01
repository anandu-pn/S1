#here implement using pandas odule
"""import pandas as pd
df=pd.read_csv('C:/Users/cacet/Desktop/anan/S1/Python/File-operations/employee.csv')
#read the first column and all the row in first column
column=df.iloc[:,0]
print(column)"""
#implemented using csv module
import csv
file=open('C:/Users/user/Desktop/lab/S1/Python/File-operations/employee.csv','r')
reader=csv.reader(file)
#it is possible to use to metod column name and column index index to print the values in column use any as required
#column_index=0#first colum instead
header=next(reader) #using column name to find column
column_index=header.index('Name')
for row in reader:
    print(row[column_index])