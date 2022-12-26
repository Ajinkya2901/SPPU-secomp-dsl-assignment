#include <iostream>
using namespace std;

// template<class T>
class job
{
    public:
    string job_id;
    int priority;
    job()
    {
        job_id = " ";
        priority = 0;
    }
    // job(string job_id_ , int priority_)
    // {
    //     this->job_id = job_id_;
    //     this->priority = priority_;
    // }
};

class Queue
{
    public:
        int rear ;
        int front ;
        int size;
        job *job_queue = NULL;
    // public:
        Queue(int s)    
        {
            rear = -1;
            front = -1;
            size = s;
            job *job_queue = new job[size];
        }

    // void intersection(int array[] , int s)
    // {
    //     for(int i = 1 ; i < s ;i++)
    //     {
    //         int key = array[i];
    //         int j = i-1;
    //         while(j>= 0 && key <  array[j])
    //         {
    //             int temp = array[j];
    //             array[j] = array[j+1];
    //             array[j+1] = temp;
                
    //             j--;
    //         }
    //     }
    // }

    void enque(job j , int priority)
    {
        if(isqfull())
        {
            cout<<"Queue is full !!!!"<<endl;
            return ;
        }
        cout << "enter j";
        cin >> j.job_id;
        cin >> j.priority;
        job_queue[++rear] = j;
    }

    void display()
    {
        if(isempty())
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        for(int i = front+1 ; i <= rear ; i++)
        {
            cout<<"job_id:  "<< job_queue[i].job_id<<" " << " job_priority : " << job_queue[i].priority;
        }
        cout<<endl;
    }

    void deque()
    {
        if(rear == front)
        {
            rear = -1;
            front = -1 ;
            cout<<"All Queue is empty"<<endl;
        }
        else
        {
            job j1 = job_queue[++front];
            cout<<"this is deleeted : ";
            cout<<"job_id:  "<< j1.job_id<<" " << " job_priority : " << j1.priority;
        }
    }

    int isqfull()
    {
        if(rear == (size-1))
        {
            return 1;
        }
        return 0;
        }
        int isempty()
        {
        if(rear ==-1)
        {
            return 1;
        }
        return 0;
    }
};

int main()
{
    Queue q(4);
    job j;
    q.enque(j , 2);
    cout << "this line is executed";
    // q.display();
}