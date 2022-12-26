
# Write a Python program to compute following operations on String: a) To display word with 
# the longest length b) To determines the frequency of occurrence of particular character in the 
# string c) To check whether given string is palindrome or not d) To display index of first 
# appearance of the substring e) To count the occurrences of each word in a given string (Do 
# not use string built-in functions)

class stringsOperation:
    def __init__(self):
        print("StringOperarion   class is constructed.")

    def createlist(self):
        list = []
        n = int(input("How many element you want to add in your list : "))
        print("Enter element to add : ")
        for i in range(n):
            list.append(input())
        return list

    def longest(self,list):
        listlong = []
        for i in list:
            a = len(i)
            listlong.append(a)
        max = 0
        for i in listlong:
            if i>max:
                max = i
        for i in list:
            if max == len(i):
                print("the longest string in given list is  is : " , i )
                print("the length of word is : ", max)


    def frequency(self,list,a):
        count = 0
        for i in list:
            if i == a :
                count = count + 1
        print("the frequency of the given character is ",count)

    def reverse(self,string):
        count = 0
        rstring =string[ ::-1]
        for i in range(len(string)):
            if rstring[i] == string[i]:
                count = count + 1
        if count == len(string):
            print("palindrome is present")
        else: 
            print("palindrome is not present")

    def indexsubstring(self,string,substring):

        if substring in string:
            print("It present")

            for i in range(len(string)):
                count = 0
                if substring[0]==string[i]:

                    for j in range(len(substring)):
                        if substring[j] == string[j+i]:
                            count = count + 1

                if count == len(substring):
                    print(" at index",i)
        else:
            print("The given  substring is not  present in the given string")


    def countword(self,string):
        list1 = string.split()

        listsubstring = []
        for i in list1:
            if i not in listsubstring:
                listsubstring.append(i)
        print("ths is list ",listsubstring)

        for substring in listsubstring:
            numofsubstring = 0
            for i in range(len(string)):
                count = 0
                if substring[0] == string[i]:

                    for j in range(len(substring)):
                        if i+j<len(string):
                            if substring[j] == string[i+j]:
                                count = count + 1

                if count == len(substring):
                    numofsubstring = numofsubstring + 1
            print("Occurrences of " ,substring , "  in a given string is " ,numofsubstring)



string1 = stringsOperation()



while(True):
    print("""*****************menu****************************
             1.check longest string in list.
             2.check frequency of character in given string.
             3.check palindrome
             4.check substring in string
             5.count word of string""")
    inputoperation = input("What operation you want to perform : ")
    if inputoperation=='1':
        str1 = string1.createlist()
        print("The list you created is : ", str1)
        string1.longest(str1)
    elif inputoperation =='2':
        str2 = input("enter string to check frequency of character : ")
        a = input("enter character you want to check : ")
        string1.frequency(str2, a)
    elif inputoperation == '3':
        b = input("enter a string to check palindrome : ")
        string1.reverse(b)
    elif inputoperation == '4':
        str3 = input("enter string to check substring in string : ")
        substring = input("enter substring : ")
        string1.indexsubstring(str3, substring)
    elif inputoperation == '5':
        str4 = input("enter string to count word in string: ")
        string1.countword(str4)
    else :
        print("enter valid input")

    a = input("Do you want to perform further operation : ")
    if a == 'n':
        break
    else:
        continue

