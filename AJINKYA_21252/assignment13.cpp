// A double-ended queue (deque) is a linear list in which additions and deletions may be made 
// at either end. Obtain a data representation mapping a deque into a one dimensional array. 
// Write C++ program to simulate deque with functions to add and delete elements from either 
// end of the deque.

#include<iostream>
using namespace std;
class deque
{
    private:
    int array[6];
    int front ;
    int rear;
    int s;
    public:
    deque()
    {
        front =  -1;
        rear = -1;
        s = 6;
    }
    bool isempty();
    bool isfull();
    void insertfront(int data);
    void insertend(int data);
    void deletefront();
    void deleteend();
    void display();
};
void deque::insertfront(int data)
{
    if(front == -1)
    {
        front++;
        array[++rear] = data;
        return;
    }
    if(isfull())
    {
        cout << "FULL";
    }
    else if(front != 0)
    {
        front--;
        array[front] = data;
    }
    else{
        int i = rear;
        while(i >= 0 )
        {
            array[i+1] = array[i];
            i--;
        }
        rear++;
        array[front] = data;
    }
}
void deque::insertend(int data)
{
    if(rear >= s || isfull())
    {
        cout << "FULL";
    }
    else
    {
        array[++rear] = data;
    }
}
void deque::deleteend()
{
    if(isempty())
    {
        cout << "EMPTY";
    }
    else
    {
        int item = array[rear];
        rear = rear - 1;
        cout << item << "is deleted";
    }
}
void deque :: deletefront()
{
    if(isempty())
    {
        cout << "Empty";
    }
    else
    {
        front++;
    }
}
void deque :: display()
{
    if(isempty())
    {
        cout << "Empty";
    }
    else
    {
        for(int i = front ; i<= rear ; i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
}
bool deque::isfull()
{
    if(rear - front + 1 >= s)
    {
        return 1;
    }
    return 0;
}
bool deque::isempty()
{
    if(front > rear || front == rear == -1) 
    return 1;
    return 0;
}
int main()
{
    deque dq;
    dq.insertfront(10);
    dq.display();
    dq.insertend(20);
    dq.display();
    dq.insertfront(11);
    dq.display();
    dq.insertfront(2);
    dq.display();
    dq.insertend(3);
    dq.display();
    dq.insertend(3);
    dq.display();
    dq.deleteend();
    dq.insertfront(2);
    dq.display();

}