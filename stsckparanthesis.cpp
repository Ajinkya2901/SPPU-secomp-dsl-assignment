#include<iostream>
using namespace std;
class stack
{
private:
    int size;
    char *arr;
    int top;
public:
    stack(int size){
        this->size = size;
        arr = new char[size];
        top = -1;
    }

    void push(int a)
    {
        if(size - top > 1)
        {
            top++;
            arr[top] = a;
        }
        else
        {
            cout<<"stack is full";
        }
    }

    void pop()
    {
        if(top>=0)
        {
            top--;
        }
        else
        {
            cout << "stack is empty";
        }
    }

    char peak()
    {
        if(top>=0)
        {
            return arr[top];
        }
        else
        {
            return -1;
        }
    }
    bool isempty()
    {
        if(top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};


int main()
{
    // stack <int> s;
    // s.push(45);
    // s.push(5);
    // s.push(4);
    // s.push(405);
    // s.push(90);
    // s.pop();
    // cout<<s.top();
    // cout<<s.empty();
    // cout<<s.size();
    // stack s(5) ;
    // s.push(56);
    // s.push(6);
    // s.push(98);
    // s.push(78);
    // s.push(3456);
    // // s.push(4566);
    // s.peak();
    // s.pop();
    // s.peak();
    // s.pop();
    // s.peak();
    // s.pop();
    // s.peak();
    // s.pop();

    string str ;
    cout << "Enter your string :  " ;
    cin >> str;
    int n = str.length();
    // cout << n;

    stack s(n);
    for(int i = 0 ; i < n ; i++)
    {
        char c = str[i];
        if(c == '(' || c == '+'|| c == '-'|| c == '*'|| c == '/')
        {
            s.push(c);
        }
        if(c == ')')
        {
            while(s.peak() != '(')
            {
                s.pop();
            }
            s.pop();
        }
    }
    if(s.isempty())
    {
        cout << "well parathesised ! "; 
    }
    else{
        cout << "not well ";
    }

}