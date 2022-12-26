from array import *


def createarr(array , z):
    for i in range(z):
        a = int(input("enter your roll"))
        array.append(a)
        print(array)

def linear(array , key):
    s = len(array)
    for i in range(s):
        if array[i] == key:
            print(i)

def sentinel(array , key ):
    s = len(array)
    
    last = array[s-1]
    array[s-1] = key

    i =0
    while array[i]!=key:
        i = i+1

    array[s-1] = last
    if i<s-1 or array[s-1] == key :
        print(i)
    else:
        print("Not present")

def binary(array ,key ):
    s = 0
    e = len(array)

    mid = s + (e-s)/2
    mid = int(mid)
    while s<=e :
        if array[mid] == key :
            print(mid)
        if array[mid]<key:
            s = mid + 1
        else:
            e = mid -1
            
        mid = s + (e-s)/2
        mid = int(mid)

def nthfiboelement(n):
    if(n ==0 ):
        return 0
    elif(n==1):
        return 1
    else:
        return nthfiboelement(n -1 ) + nthfiboelement(n-2)

def fibonnacisearch(array , key , size ):
    n = 0
    while(nthfiboelement(n)<size):
        n = n + 1
    
    offset = -1
    while(nthfiboelement(n)>1):
        i  =  min(offset + nthfiboelement(n-2) , size-1)

        if(key < array[i]):
            n = n -2
        elif(key>array[i]):
            n = n -1
            offset = i
        else:
            return i


ajinkya = [1,3,4,6,19,21,25,30,45]
# createarr(ajinkya , 5)
# linear(ajinkya , 4)
# sentinel(ajinkya , 4 )
# binary(ajinkya,19)
# print(nthfiboelement(6))
print(fibonnacisearch(ajinkya,45,9))