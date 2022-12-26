// Write C++ program for storing binary number using doubly linked lists. Write functions- a) 
// To compute 1‘s and 2‘s complement b) Add two binary numbers 
#include<iostream>
using namespace std;

class node{
    public:
        int data ;
        node *next;
        node *prev ;
        node(int data){
        this -> data = data;
        this ->next = NULL;
        this ->prev = NULL;
        }
};

void insert(node *&head ,node *&tail , int data){
    if(head == NULL ){
        head = new node(data);
        tail = head;
        return;
    }
    node *randnode = new node(data);
    randnode->next = head;
    head->prev = randnode;
    head = randnode;
}

void print(node *&head ){
    node *randnode = head;
    while(randnode->next){
        cout<<randnode->data<<" ";
        randnode = randnode->next;
    }
    cout<<randnode->data<<endl;
}

void decimaltobinary(node *&head,node *&tail , int a){
    while(a)
    {
        int bi = a % 2 ;
        insert(head,tail,bi);
        a = a/2;
        // cout<<"this is a " << a << " "; 
    }
}
void onescompliment(node *head){
    if(head == NULL){
        return;
    }
    node*temp = head;
    while(temp){
        if(temp->data == 1){
            temp->data  = 0;
        }
        else{
            temp->data = 1;
        }
        temp = temp->next;
    }
}
// void twocompliment(node *tail){
//     int carry = 0;
//     node * temp = tail;
//     while()
// }
void printtail(node *&head ){
    node *randnode = head;
    while(randnode){
        cout<<randnode->data<<" ";
        randnode = randnode->prev;
    }
    cout<<endl;
    // cout<<randnode->data<<endl;
}

node* addtobinary(node *tail ,node *tail1)
{
    int carry = 0;
    node*ans = NULL;
    while(tail || tail1)
    {
        // cout<<"this is carry at start "<<carry<<endl;
        // cout<<tail->data << tail1->data << carry << endl;
        int a ,b;
        if(tail!= NULL){
            a = tail->data;
        }
        else{
            a = 0;
        }
        
        if(tail1!= NULL){
            b = tail1->data; 
        }
        else{
            b = 0 ;
        }
        if(a && b && carry )
        {
            carry = 1;
            insert(ans,ans ,1);
            
        }
        else if(a== 0 && b == 0 && carry == 0)
        {
            carry = 0;
            insert(ans,ans ,0);
            
        }
        else if( (a == 0 && b == 0 && carry == 1) 
                ||(a == 0 && b == 1 && carry == 0) ||
                (a == 1 && b == 0 && carry == 0) )
        {
            carry = 0;
            insert(ans,ans ,1);
            
        }
        else{
            carry = 1;
            insert(ans,ans ,0);
        }
        if(tail!= NULL){
            tail = tail->prev;
        }
        
        if(tail1!= NULL){
            tail1 = tail1->prev;
        }
        // cout<<"this is carry at end "<<carry<<endl;
    }
    if(carry){
        insert(ans,ans ,1);
        carry = 0;
    }
    return ans;
}

node* twocompliment(node *binarytail){
    node *binaryhead1 = NULL;
    node *binarytail1 = NULL;
    decimaltobinary(binaryhead1 ,binarytail1 ,  1);
    node * sum = addtobinary(binarytail ,binarytail1);
    return sum;
}
int main(){
    int decimal  = 48;
    cout<<"enter number : ";
    cin>>decimal;

    node *binaryhead = NULL;
    node *binarytail = NULL;
    decimaltobinary(binaryhead ,binarytail ,  decimal);
    cout << decimal << " in binary is : " ;
    print(binaryhead);
    
    onescompliment(binaryhead);
    cout << "Ones compliment of " << decimal <<" is : " ;
    print(binaryhead);
    
    node *two = twocompliment(binarytail);
    cout << "Twos compliment of " << decimal <<" is : " ;
    print(two);

    //  int decimal1  = 48;
    // cout<<"enter number : ";
    // cin>>decimal;

    // node *binaryhead1 = NULL;
    // node *binarytail1 = NULL;
    // decimaltobinary(binaryhead1 ,binarytail1 ,  decimal1);
    // print(binaryhead1);
    // onescompliment(binaryhead1);
    // print(binaryhead1);


    // node * sum = addtobinary(binarytail ,binarytail1);
    // print(sum);
}