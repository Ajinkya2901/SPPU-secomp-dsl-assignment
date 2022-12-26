// Queues are frequently used in computer programming, and a typical example is the creation 
// of a job queue by an operating system. If the operating system does not use priorities, then 
// the jobs are processed in the order they enter the system. Write C++ program for simulating 
// job queue. Write functions to add job, display job and delete job from queue.
#include<iostream>
using namespace std;
class Queue
{
    private:
        int rear ;
        int front  ;
        int size;
        int *job = NULL;
    public:
        Queue(int s)    
        {
            rear = -1;
            front = -1 ;
            size = s;
            job = new int[s];
        }

        void enque(int job_id)
        {
            if(isqfull())
            {
                cout<<"Queue is full !!!!"<<endl;
                return ;
            }
            job[++rear] = job_id;
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
                cout<<job[i]<<" ";
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
                    int x = job[++front];
                    cout<<"this is delted"<<x<<endl;
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
    Queue q(5);
    // q.enque(45);
    // q.enque(4);
    // q.enque(7);
    // q.enque(4667);
    // q.enque(005);
    // q.deque();
    // q.deque();
    // q.deque();
    // q.deque();
    // q.deque();
    // q.enque(7);
    // q.enque(78);
    // q.enque(36);
    // q.enque(101);
    // q.enque(73);
    // q.enque(45);
    // cout<<q.isempty();
    // cout<<q.isqfull();
    // q.display();
    

while(true)
    {
        cout<<"**************MENU******************\n1.enque \n2.deque\n3.display\n4.isempty\n5.isfull";
        int choice = 0;
        cout<<"Enter your choice : ";
        cin>>choice;


        switch(choice)
        {
            case 1:
            {
                int a;
                cout<<"Eneter num to enque: ";
                cin>>a;
                q.enque(a);
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