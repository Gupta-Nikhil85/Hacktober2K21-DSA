thislist = ["apple", "banana", "cherry"] #this is a list in python
print(thislist) #Output: [ "cherry"]

#length of a list
print(len(thislist)) #Output: 3

#to access a specific item in the list
index = 1 # Indices start from 0 and end at (length of list) - 1
print(thislist[1]) #Output: "banana"

#negative indexing means that you are starting from the end of the list
index = -1 
print(thislist[-1]) #Output: "cherry"

#you can also access a range of indices (excludes the last index)
print(thislist[0:2]) #Output: ["apple", "banana"]
