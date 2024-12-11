class time:
    def __init__(self,hour,minute,second):
        self.__hour=hour
        self.__minute=minute
        self.__second=second
    def __add__(self,other):
        totalsecond=self.__second+other.__second
        totalminute=self.__minute+other.__minute+(totalsecond//60)
        totalhour=self.__hour+other.__hour+(totalminute//60)
        return time(totalhour, totalminute % 60,totalsecond %60)
    def display(self):
        print(f"sum of time is {self.__hour:02}:{self.__minute:02}:{self.__second:02}")
x1=int(input("enter the hour: "))        
y1=int(input("enter the minute: "))        
z1=int(input("enter the second: "))        
x2=int(input("enter the hour: "))        
y2=int(input("enter the minute: "))        
z2=int(input("enter the second: "))        
time1=time(x1,y1,z1)
time2=time(x2,y2,z2)
sum=time1+time2
sum.display()