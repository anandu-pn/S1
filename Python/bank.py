class Account:
    def __init__(self,acc_no,name,acc_type,bal):
        self.acc_no=acc_no
        self.name=name
        self.acc_type=acc_type
        self.bal=bal
    def deposit(self,amount):
        self.bal+=amount
        print("%.2f amount deposited succesfully"%(amount))
    def withdraw(self,amount):
        if amount > self.bal:
            print("insufficient balance")
        else:
            self.bal-=amount  
            print("%f amount withdrawn succesfully"%amount)
    def display(self):
        print(f"account holder:{self.name}\naccount number:{self.acc_no}\naccount type:{self.acc_type}\nbalance:{self.bal}")   
name=input("enter the name of account holder: ")
acc_no=int(input("enter the account number: "))
acc_type=input("enter the account type: ")  
member = Account(acc_no,name,acc_type,0)
while(1):
    x=int(input("enter the choice : 1.Deposit \t 2.withdraw \t 3.exit :"))
    if x==1:
        amount=float(input("enter the amount:"))
        member.deposit(amount)
    elif x==2:
        amount=float(input("enter the amount:"))
        member.withdraw(amount)
    elif x==3:
        break
    else:
        print("You entered invalid option")
    member.display()