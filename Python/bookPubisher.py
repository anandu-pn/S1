class publisher:
    def __init__(self,name):
        self.name=name
class book(publisher):
    def __init__(self,name,title,author):
        super().__init__(name)
        self.title=title
        self.author=author
class python(book):
    def __init__(self,name,title,author,price,pages):
        super().__init__(name,title,author)
        self.price=price
        self.pages=pages
    def display(self):
        print(f"Publisher: {self.name}") 
        print(f"Title: {self.title}") 
        print(f"Author: {self.author}") 
        print(f"Price: {self.price}") 
        print(f"Number of Pages: {self.pages}")
pub=input("enter the publisher: ")
tit=input("enter the Title: ")
auth=input("enter the author: ")
price=input("enter the price: ")
pages=input("enter the pages: ")

python_book = python(pub,tit,auth,price,pages) 

python_book.display()