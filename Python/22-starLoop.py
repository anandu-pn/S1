# Construct the pattern using nested loop
x=int(input("enter the height :"))
for i in range(1,x+1,1):
    print("*"*i)
    if i==x:
        for j in range(i-1,0,-1):
            print("*"*j)