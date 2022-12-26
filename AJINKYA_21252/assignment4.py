# a) Write a python program to store roll numbers of student in array who attended training 
# program in random order. Write function for searching whether particular student attended 
# training program or not, using Linear search and Sentinel search.
# b) Write a python program to store roll numbers of student array who attended training 
# program in sorted order. Write function for searching whether particular student attended 
# training program or not, using Binary search and Fibonacci search
from array import *

class search:
    
    def createarray(self,array, size):
        array = []
        for i in range(size):
            a = int(input("enter your roll"))
            array.append(a)
        print("The array is " , array)
        return array

    def linearsearch(self,array, key):
        s = len(array)
        flag = 0
        comparison = 0
        for i in range(s):
            if array[i] == key:
                comparison = comparison + 1
                flag = flag + 1
                print("Element is present at " , i)
                break
            else:
                comparison = comparison + 1
        if(flag ==0 ):
            print("Not found ")
        print("No of comparison are : " , comparison )

    def sentinel(self,array, key):
        s = len(array)
        comparison = 0
        last = array[s - 1]
        array[s - 1] = key
        i = 0
        while array[i] != key:
            comparison = comparison +1
            i = i + 1

        array[s - 1] = last
        if i < s - 1 or array[s - 1] == key:
            print("comparison ",comparison)
            print("element is present at index : " , i)
        else:
            print("comparison ", comparison)
            print("Not present")


    def binary(self,array, key):
        array.sort()
        s = 0
        e = len(array)-1
        comparison = 0
        mid =  (s+e) / 2
        mid = int(mid)
        while s < e:
            if array[mid] == key:
                comparison = comparison + 1
                print("Element found at" ,mid)
                break
            if array[mid] < key:
                comparison = comparison + 1
                s = mid + 1
            else:
                comparison = comparison + 1
                e = mid - 1

            mid = (s + e) / 2
            mid = int(mid)
        print("no. of comparison: ",comparison)


    def nthfiboelement(self,n):
        if (n == 0):
            return 0
        elif (n == 1):
            return 1
        else: 
            return self.nthfiboelement(n - 1) + self.nthfiboelement(n - 2)

    def fibonnacisearch(self,array, key):
        array.sort()
        print("Sorted Array ",array)
        size = len(array)
        k = 0
        comparison  = 0
        while (self.nthfiboelement(k) < size):
            k = k + 1

        offset = -1
        while (self.nthfiboelement(k) > 1):
            i = min(offset + self.nthfiboelement(k - 2), size - 1)


            if (key < array[i]):
                comparison = comparison + 1
                k = k - 2
            elif (key > array[i]):
                comparison = comparison + 1
                k = k - 1
                offset = i
            else:
                print("no of comparison : ", comparison + 1)
                return i

        if (self.nthfiboelement(k-1) and array[size - 1] == key):
            return k - 1
        else:

            return -1


searchfirst = search()
array = [1, 3, 4, 6, 19, 21, 25, 30, 45]
# createarr(ajinkya , 5)
# linear(ajinkya , 4)
# sentinel(ajinkya , 4 )
# binary(ajinkya,19)
# print(nthfiboelement(6))
# print(searchfirst.fibonnacisearch(ajinkya, 45, 9))

while(True):
    print("""**********************menu******************
            1.Add attended student 
            2.Searching by linear search 
            3.Searching by sentinal search 
            4.Searching by binary search 
            5.Searching by fibonnaci search""")
    a = int(input("Enter by which search you want to search : "))
    if a == 1:
        b = input("Enter name to your array")
        size  = int(input("How many student attended "))
        array = search().createarray(b,size)
    elif a ==2 :
        b = int(input("Enter the element to search : "))
        search().linearsearch(array,b)
    elif a == 3 :
        b = int(input("Enter the element to search : "))
        search().sentinel(array,b)
    elif a == 4:
        b = int(input("Enter the element to search : "))
        search().binary(array,b)
    elif a == 5:
        b = int(input("Enter the element to search : "))
        print(search().fibonnacisearch(array ,b))
    else:
        print("Enter valid input !")
    z = input("Do you want to perform further operation ?y/n")
    if z=='n':
        break
