#include<iostream>
using namespace std;
void swap(int *a ,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[] , int s , int e)
{
    int piv = arr[e];
    int j = s -1;
    for(int i = s ; i < e ; i++)
    {
        if(arr[i] <= piv)
        {
            j++;
            swap(&arr[i] , &arr[j]);
        }
    }
    j++;
    swap(&arr[j] , &arr[e]);
    return j;
}
void quicksort(int arr[] , int s ,int e)
{
    if(s >= e) return ;
    int p = partition(arr , s ,e);
    quicksort(arr , s , p-1);
    quicksort(arr , p+1 , e);
}
int main()
{
    int array[8] = {25 , 57, 48, 37, 12, 92, 86, 33};
    quicksort(array , 0 , 7);
    for(int i = 0 ; i < 8 ; i++)
    {
        cout << array[i] << " ";
    }
}