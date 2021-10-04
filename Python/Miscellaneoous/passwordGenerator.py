import random
import string
print('hello, Welcome to Password generator!')
length=int(input("enter the length of the youre password:"))
lower=string.ascii_lowercase
upper=string.ascii_uppercase
digit=string.digits
symbol=string.punctuation
all=lower+upper+digit+symbol
temp=random.sample(all,length)
password=''.join(temp)
# print(password)
print(f"Youre passwors is:{password}")