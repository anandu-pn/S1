# Fibonacci series of N terms  
def fib(n):
    if n<1:
        pass
    else:
        i=0
        a,b=0,1
        while(i<n):
            print(a,end=' ')
            c=a+b
            a=b
            b=c
            i+=1
            

n=int(input("enter the limit:"))
fib(n)