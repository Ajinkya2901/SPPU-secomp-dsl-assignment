# Write a python program to store first year percentage of students in array. Write function for 
# sorting array of floating point numbers in ascending order using quick sort and display top 
# five scores.

# from array import *
# # from numpy import *
#
#
# def createarray(size):
#     name = array('i', [])
#     for i in range(size):
#         a = int(input())
#         name.append(a)
#     return name
#
#
#
#
#
# Marks = array('i',[1,5,3,0,98,100,56,34,66,-1,7])
# ajinkya = createarray(5)
# print(ajinkya)

from array import *
# from numpy import *

# arra = array('i',[10,80,30,90,40,50,70])
arra = array('i',[1,5,3,0,98,100,56,34,66,-1,7])
def swap(array , i , j):
    temp = array[i]
    array[i] = array[j]
    array[j] = temp
    # print(array)
    return array


n = len(arra)
for piv in range(n):
    print(arra)
    for j in range(piv,n):
            k = n -1
            while(k>=j):
                if(arra[k]<arra[piv] and k>j):
                    arra = swap(arra, j,k)
                if(k<j and arra[piv] > arra[k]):
                    arra = swap(arra, piv, k)
                k = k -1 


print("top 5 scores are as follows : ")
for i in range(5):
    print(arra[n-1-i])


