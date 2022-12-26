#include<iostream>
using namespace std;

void bubble(int arr[], int a)
{
    for(int i = 0 ; i < a - 1  ; i++)
    {
        for(int j = 0 ; j < a - i - 1 ; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main()
{
    int array[7] = {7,6,5,4,3,2,1};
    int n = 7;
    bubble(array,7);

    for(int i = 0 ; i < n ; i++)
    {
        cout << array[i];
    }
}