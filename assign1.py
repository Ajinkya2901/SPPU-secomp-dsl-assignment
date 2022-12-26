
def createlist(list):
    n = int(input(f"How many element you want to add in list"))
    print("Enter element to add in list ")
    for i in range(n):
        list.append(input())
    return list

def repeat(list):
    list1 = []
    for i in list:
        if i not in list1:
            list1.append(i)
    return list1

def union(list1, list2):
    union = []
    for i in list1:
        union.append(i)
    union1 = union
    for j in list2:
        union1.append(j)
    union2 = union1
    # difference()
    return union2

def intersection(list1, list2):
    intsect = []
    for i in list1:
        for j in list2:
            if i == j:
                intsect.append(i)
    return intsect

def difference(list1, list2):
    for i in list2:
        for j in list1:
            if i == j:
                list1.remove(i)
    return list1

secomp = []
cricket = []
football = []
badminton = []

print("enter element in secomp")
secomp = repeat(createlist(secomp))
print("enter element in cricket")
cricket = repeat(createlist(cricket))
print("enter element in football")
football = repeat(createlist(football))
print("enter element in badminton")
badminton = repeat(createlist(badminton))

print("element in secomp ", secomp)
print("element in cricket ", cricket)
print("element in football ", football)
print("element in badminton ", badminton)

print(max)
# secomp = [1,2,3,4,5]
# cricket =[ 2,4,5]
# football = [3,4,5,6,7]
# badminton = [2,4,1]

while(True):
    print("""*****************menu****************************
            1.cricket and badminton
            2.either cricket or badmainton not both
            3.neither cricket nor badmainton
            4.cricket and football but not badmainton""")


    a = int(input("Enter operation you want to perform : "))

    if a == 1:
        print("The student how play cricket and badmainton : ",
            repeat(intersection(cricket, badminton)))
    elif a == 2:
        print("The either cricket or badmainton not both : ",
            difference(union(cricket, badminton), intersection(cricket, badminton)))
    elif a == 3:
        print("The neither cricket nor badmainton: ",
            repeat(union(difference(secomp, cricket), difference(secomp, badminton))))
    elif a == 4:
        print("The cricket and football but not badmainton: ",
            difference(repeat(intersection(cricket, football)), badminton))
    else:
        print("enter valid input")
    
    print("Do you want to perform more operations ? ")
    z = input("Enter y if yes and n if no :")
    if z == 'y':
        continue
    else:
        print("THANK YOU!")
        break
