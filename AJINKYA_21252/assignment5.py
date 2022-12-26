# Write a python program to store second year percentage of students in array. Write function 
# for sorting array of floating-point numbers in ascending order using a) Insertion sort b) 
# Shell Sort and display top five scores
# from numpy import *
from array import *
class Sort:
    
    def createarray(self,size):
        name = array('i',[])
        for i in range(size):
            a = int(input())
            name.append(a)
        return name

    def swap(self,array,a,b):
        temp = array[a]
        array[a] = array[b]
        array[b] = temp
        return array

    # def insertion(self,array):
    #     n = len(array)
    #     arr = array
    #     print("initial",arr)
    #     count = 0

    #     for i in range(1,n):
    #         print(i,"th for loop")
    #         for j in range(0,i):
    #             if array[i-j-1]>array[i-j]:
    #                 arr = self.swap(arr,i-j-1,i-j)
    #                 count = count + 1
    #             else:
    #                 break;
    #             print(arr,count)

    def insertion1(self,array):
        print("********************USING INSERTION SORT ******************************")
        n = len(array)
        arr = array
        print("initial",arr)
        count = 0
        for i in range(1,n):
            print(i,"th for loop")
            for j in range(0,i):
                if array[j]>array[i]:
                    arr = self.swap(arr,j,i)
                    count = count +1
                # else:
                #     break;
                print(arr,count)

    def insertionshell(self,array,gap , init):
        n = len(array)
        arr = array
        i = init + gap
        while(n>=i):
            j = init
            while(i>j and n>i):
                if array[j]>array[i]:
                    arr = self.swap(arr,i,j)
                j += gap
            i += gap

    def shell(self,array):
        n= len(array)
        gap = 4
        print("********************USING SHELL SORT ******************************")
        while(gap>0):
            i = 0
            while ( gap>i):
                init = i
                self.insertionshell(array, gap ,init)
                i = i + 1
            # print("\n")
            print("gap is : ",gap ,"Array is : " ,array)
            gap = gap - 1

    def topfive(self, array):
        n = len(array)
        for i in range(5):
            print(i+1 , "th postion student marks : ",array[n-i-1],"\n")

sort1 = Sort();

Marks = array('i',[1,5,3,0,98,100,56,34,66,-1,7])
# insertion1(array1)
# array1= array('i',[12,7,22,4,71,15,28,36])
# shell(array1)
# Attendence = sort1.createarray(5)
# print(Attendence)


while(True):
    print("""**********************menu******************
            1.store second year percentage of students in array
            2.Sort using Insertion sort
            3.Sort using Shell sort
            4.Display Top five score""")

    a = int(input("Enter Operation you want to perform : "))

    if a == 1:
        # b = input("Enter name to your array")
        size  = int(input("How many student attended "))
        Marks = sort1.createarray(size)

    elif a ==2 :
        sort1.insertion1(Marks)
    elif a == 3 :
        sort1.shell(Marks)
    elif a == 4:
        sort1.topfive(Marks)
    else:
        print("Enter valid input !")


    z = input("Do you want to perform further operation ?y/n")
    if z=='n':
        break

