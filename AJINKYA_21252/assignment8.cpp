// Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set B 
// of students like butterscotch ice-cream. Write C++ program to store two sets using linked 
// list. compute and display- a) Set of students who like both vanilla and butterscotch b) Set of 
// students who like either vanilla or butterscotch or not both c) Number of students who like 
// neither vanilla nor butterscotch

#include<iostream>
using namespace std;

class node{
    public:
        int data ;
        node *next;
        node(int data){
        this -> data = data;
        this ->next = NULL;
        }
};

void insert(int posi , node *&head ,int data){
    node *randnode = new node(data);
    node *temp = head;
    for(int i = 1; i< posi-1 ;i++){
        temp = temp->next;
    }
    randnode->next = temp->next;
    temp->next = randnode;
}
void print(node *&head ){
    node *randnode = head;
    while(randnode->next){
        cout<<randnode->data<<" ";
        randnode = randnode->next;
    }
    cout<<randnode->data<<endl;
}





node* append(int n){
    int data;
    cin>>data;
    node *head = new node(data);
    node*randnode = head;
    for(int i = 0 ; i< n -1 ;i++){
        int data;
        cin>>data;
        randnode->next = new node(data);
        randnode = randnode->next;
    }
    return head;
}

void createappend(node *&head ,int data)
{
    if(head == NULL){
        head = new node(data);
        return;
    }
    node*randnode = head;
    while(randnode->next){
        randnode = randnode->next;
    }
    randnode->next = new node(data);
}

node * intersection(node *h1 , node * h2)
{
    node *temp = NULL;
    node *randnode1 = h1;
    while(true)
    {
        node *randnode2 = h2;
        while(true)
        {
            if( randnode1->data == randnode2->data)
            {
                createappend(temp ,randnode2->data);
            }
            if(randnode2->next == NULL)
            {
                break;
            }
            randnode2 = randnode2->next;
        }
        if(randnode1->next == NULL)
        {
            break;
        }
        randnode1 = randnode1->next;
    }
    return temp;
}

void deleteNode(node*&head, int key)
{

    node* temp = head;
    node* prev = NULL;
    if (temp != NULL && temp->data == key) {
        head = temp->next; 
        delete temp; 
        return;
    }
    else 
    {
        while (temp != NULL && temp->data != key)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
            return;
        prev->next = temp->next;
        delete temp;
    }
}
node* merge(node *a, node *b)
{
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;

    node *c;
    if(a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
    return c;
}


void sub(node * &h1 , node *&h2){
    node *randnode2 = h2;
    while(true)
    {
        node*randnode1 = h1;
        while(true)
        {
            if(randnode2->data== randnode1->data)
            {
                deleteNode(h1,randnode2->data);
            }
            if(randnode1->next == NULL)
            {
                break;
            }
            randnode1 = randnode1->next;
        }
        if(randnode2->next == NULL)
        {
            break;
        }
        randnode2 = randnode2->next;
    }
}
void swap(int array[] , int i ){
    int temp = array[i];
    array[i] = array[i+1];
    array[i +1] =temp;
}
void bubble(int array[] , int size)
{
    for(int i = 0 ; i < size -1; i++){
        for(int  j= 0 ; j < size ; j++){
            if(array[j]>array[j+1]){
                swap(array , j);
            }
        }
    }
}

int main(){

    int nostudent = 0;

    
    cout<<"Enter  no of student : ";
    cin>>nostudent;
    node * seta = append(nostudent);


    cout<<"Enter roll Number of student like vanilla : ";
    cin>>nostudent;cout<<"Enter  roll no : ";
    node * setvanilla = append(nostudent);


    cout<<"Enter roll Number of student like butterscoch:  : ";
    cin>>nostudent;cout<<"Enter  roll no : ";
    node * butterscotch = append(nostudent);


    cout<<"roll no of all student  : ";print(seta);
    cout<<"vanila  : ";print(setvanilla);
    cout<<"butersoch  : ";print(butterscotch);

    
    cout<<endl<<"Set of students who like both vanilla and butterscotch : ";
    node * intsetofvanibutter = intersection(setvanilla , butterscotch);
    print(intsetofvanibutter);

    cout<<endl<<"Set of students who like neither vanilla nor butterscotch : ";
    sub(seta,setvanilla);
    print(seta);
    sub(seta,butterscotch);
    print(seta);

    cout<<endl<<"Set of students who like either vanilla or butterscotch or not both : ";
    node *c = merge(setvanilla,butterscotch);
    sub(c,intsetofvanibutter);
    sub(c,intsetofvanibutter);
    print(c);


}