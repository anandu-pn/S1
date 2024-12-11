#Display the given pyramid with step number accepted from user. 
def pyr(n):
    i=1
    while(i<=n):
        for j in range(1,i+1,1):
            print(i*j,end=' ')
        i+=1
        print(" ")
n=int(input("Enter the limit: "))
pyr(n)