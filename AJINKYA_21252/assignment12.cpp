// Write program to implement a priority queue in C++ using an order list/array to store the 
// items in the queue. Create a class that includes the data items (which should be template) 
// and the priority (which should be int). The order list/array should contain these objects, with 
// operator <= overloaded so that the items with highest priority appear at the beginning of the 
// list/array (which will make it relatively easy to retrieve the highest item.) 
#include <iostream>
#include<string>
using namespace std;

template<class T>
class job
{
    public:
    T job_id ;
    int priority ;

    bool operator > (job const &obj) {
        if(this->priority > obj.priority )
        {
            return 1;
        }
		return 0;
	}
};

template<class T1>
class Queue
{
    private:
        int rear ;
        int front ;
        int size;
        job<T1> *job_queue;
    public:
        Queue(int s)    
        {
            rear = -1;
            front = -1 ;
            size = s;
            job_queue = new job<T1>[7];
        }


    void enque(job<T1> j)
    {
        if(isqfull())
        {
            cout<<"Queue is full !!!!"<<endl;
            return ;
        }
        cout << " Enter job id : "; cin>> j.job_id;
        cout << "Enter job priority : " ; cin >> j.priority;
        job_queue[++rear] = j ; 

        job<T1> key = job_queue[rear];
        int k = rear - 1 ;
        while(k>= 0 && key >  job_queue[k])
        {
            job<T1> temp = job_queue[k];
            job_queue[k] = job_queue[k+1];
            job_queue[k+1] = temp;
            k--;
        }
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
            cout<<"job_id:  "<< job_queue[i].job_id<<" " << " job_priority : " << job_queue[i].priority << endl;
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
            job<T1> j1 = job_queue[++front];
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
    cout << "enter size of arrray : ";
        int m;
        cin>> m;
        Queue<string> q(m);
        job<string> j ;

    while(true)
    {
        cout<<"**************MENU******************\n1.enque \n2.deque\n3.display\n4.isempty\n5.isfull\n";
        int choice = 0;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                q.enque(j);
            }
                break;
            case 2:
            {
                q.deque();
            }
                break;
            case 3:
            {
                q.display();
            }
                break;
            case 4:
            {
                if(q.isempty())
                {
                    cout<<"this is emppty";
                }
                else{
                    cout<<"not e,pty";
                }
            }
                break;
            case 5:
            {
                if(q.isqfull())
                {
                    cout<<"this is full";
                }
                else{
                    cout<<"not empty";
                }
            }
                break;
            default:
                cout<<"Enter valid input !!!!";

        }
        char check;
        cout<<"\nDo you want to continue (y/n) ?";
        cin>>check;
        if(check == 'n'){
            break;
        }

    }
}
