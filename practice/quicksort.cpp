#include<iostream>
using namespace std;


//love babber
int partition(int arr[] ,int s, int e)
{
    int piv = arr[s];
    int count = 0;
    for(int i = s +1; i  <= e ; i++ )
    {
        if(arr[i] <= piv) count++;
    }
    int temp = arr[s ];
    arr[s ] = arr[s + count];
    arr[s + count] = temp;
    int i = s ; int j = e;
    while(i < s+ count && s+count <j)
    {
        while(arr[i]<piv)
        {
            i++;
        }
        while (arr[j] > piv)
        {
            j--;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        
    }
    return s + count;
}
void quicksort(int arr[] ,int s, int e)
{
    if(s>=e){return;}
    int p = partition(arr ,s,e);
    quicksort(arr, s , p -1);
    quicksort(arr ,  p +1 , e);
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