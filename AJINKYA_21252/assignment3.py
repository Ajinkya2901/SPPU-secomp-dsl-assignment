# Write a python program to compute following computation on matrix: 
# a) Addition of two matrices b) Subtraction of two matrices
# c) Multiplication of two matrices d) Transpose of a matrix



from numpy import *

class Matrix:
    def __init__(self):
        print("The Constructor")

    def createmat(self):
        r = int(input("Enter no. of row you want to create : "))
        c = int(input("Enter no. of column you want to create : "))

        a = array([ [0]*c ]*r )
        print("Enter element at :")
        for i in range(0, r):
            for j in range(0, c):
                a[i][j] = int(input())
        return a

    def sum(self,mat1,mat2):
        if len(mat2)!=len(mat1) or len(mat2[0])!=len(mat1[0]) :
            print("Enter Valid  input")
        else:
            result = array( [  [0]*len(mat1[0]) ]*len(mat1))
            for i in range(0,len(mat1)):
                for j in range(0,len(mat2[0])):
                    result[i][j] = mat1[i][j] + mat2[i][j]
            print("Sum of two matrix is:\n", result)

    def product(self,mat1,mat2):
        if len(mat2)!= len(mat1[0]):
            print("Enter valid input")
        else:
            result = array( [  [0]*len(mat2[0])]*len(mat1))

            for i in range(len(mat1)):

                for j in range(len(mat2[0])):

                    for k in range(len(mat2)):
                        result[i][j] += mat1[i][k] * mat2[k][j]
            print("product of two matrix is:\n", result)


    def sub(self,mat1,mat2):
        if len(mat2)!=len(mat1) or len(mat2[0])!=len(mat1[0]):
            print("Enter Valid  input")
        else:
            result = array( [  [0]*len(mat1[0]) ]*len(mat1))
            for i in range(0,len(mat1)):
                for j in range(0,len(mat1[0])):
                    result[i][j] = mat1[i][j] - mat2[i][j]
            print("substraction of two matrix is:\n", result)

    def transpose(self,mat1):
        result = array( [  [0]*len(mat1)]  *len(mat1[0]) )
        for i in range(len(mat1[0])):
            for j in range(len(mat1)):
                result[i][j] = mat1[j][i]
        print("transpose of matrix is:\n", result)



matrix1 = Matrix()

mat1 = matrix1.createmat()
print(mat1)

mat2 = matrix1.createmat()
print(mat2)


while(True):
    print("""*****************menu****************************
             1.Addition of matrix .
             2.Substraction of matrix.
             3.Multiplication of matrix.
             4.Transpose of matrix.""")
    inputoperation = input("What operation you want to perform : ")
    if inputoperation=='1':
        matrix1.sum(mat1, mat2)


    elif inputoperation =='2':
        matrix1.sub(mat1, mat2)


    elif inputoperation == '3':
        matrix1.product(mat1, mat2)


    elif inputoperation == '4':
        matrix1.transpose(mat1)


    else :
        print("enter valid input")

    a = input("Do you want to perform further operation : ")
    if a == 'n':
        break;
    else:
        continue;
