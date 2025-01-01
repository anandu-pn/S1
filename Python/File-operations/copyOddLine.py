file1=open('C:/Users/cacet/Desktop/anan/S1/Python/File-operations/readLine.txt','r')
file2=open('C:/Users/cacet/Desktop/anan/S1/Python/File-operations/writeLine.txt','w+')
i=1
for line in file1:
    if(i%2==1):
        file2.write(line)
    i+=1
file2.close
file1.close