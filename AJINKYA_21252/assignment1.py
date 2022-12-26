# In second year computer engineering class, group A student’s play cricket, group B students 
# play badminton and group C students play football. Write a Python program using functions 
# to compute following: - a) List of students who play both cricket and badminton b) List of 
# students who play either cricket or badminton but not both c) Number of students who play 
# neither cricket nor badminton d) Number of students who play cricket and football but not 
# badminton. (Note- While realizing the group, duplicate entries should be avoided, Do not 
# use SET built-in functions) 
secomp = []
cricket = []
football = []
badminton = []


def repeat(list):
    list1 = []
    for i in list :
        if i not in list1:
                list1.append(i)
    return list1


def createlist(list):
    n = int(input(f"How many element you want to add in list"))
    print("Enter element to add in list ")
    for i in range(n):
        list.append(input())
    return list


def union(list1,list2):
    union = []
    for i in list1:
        union.append(i)
    union1 = union
    for j in list2:
        union1.append(j)
    union2 = union1
    # difference()
    return union2


def intersection(list1,list2):
    intsect = []
    for i in list1:
        for j in list2:
            if i == j:
                intsect.append(i)
    return intsect


def difference(list1,list2):
    for i in list2 :
        for j in list1:
            if i==j:
                list1.remove(i)
    return list1


print("enter element in secomp")
secomp = repeat(createlist(secomp))
print("enter element in cricket")
cricket = repeat(createlist(cricket))
print("enter element in football")
football = repeat(createlist(football))
print("enter element in badminton")
badminton = repeat(createlist(badminton))

print("element in secomp ",secomp)
print("element in cricket ",cricket)
print("element in football ",football)
print("element in badminton ",badminton)

# secomp = [1,2,3,4,5]
# cricket =[ 2,4,5]
# football = [3,4,5,6,7]
# badminton = [2,4,1]

print("""*****************menu****************************
         1.cricket and badminton
         2.either cricket or badmainton not both
         3.neither cricket nor badmainton
         4.cricket and football but not badmainton""")
a = int(input("Enter operation you want to perform : "))
if a==1:
    print("The student how play cricket and badmainton : ", repeat(intersection(cricket, badminton)))
elif a ==2:
    print("The either cricket or badmainton not both : ",
          difference(union(cricket, badminton), intersection(cricket, badminton)))
elif a == 3:
    print("The neither cricket nor badmainton: ",
          repeat(union(difference(secomp, cricket), difference(secomp, badminton))))
elif a == 4:
    print("The cricket and football but not badmainton: ",
          difference(repeat(intersection(cricket, football)), badminton))
else :
    print("enter valid input")


# str1 = string1.createlist()
# print("The list you created is : ", str1)

# string1.longest(str1)

# str2 = input("enter string to check frequency of character : ")
# a = input("enter character you want to check : ")
# string1.frequency(str2,a)
#
# b = input("enter a string to check palindrome : ")
# string1.reverse(b)
#
# str3 = input("enter string to check substring in string : ")
# substring = input("enter substring : ")
# string1.indexsubstring(str3, substring)
#
# str4 = input("enter string to count word in string: ")
# string1.countword(str4)

