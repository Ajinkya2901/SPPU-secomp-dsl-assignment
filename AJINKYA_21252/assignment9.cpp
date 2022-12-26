// In any language program mostly syntax error occurs due to unbalancing delimiter such as 
// (),{},[]. Write C++ program using stack to check whether given expression is well 
// parenthesized or not. 

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

    bool pop()
    {
        if(top>=0)
        {
            top--;
        }
        else
        {
            return 0;
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
    string str ;
    cout << "Enter your string : " ;
    cin >> str;
    int n = str.length();
    // cout << n;

    stack s(n);
    for(int i = 0 ; i < n ; i++)
    {
        char c = str[i];
        if(c == '(' || c == '+'|| c == '-'|| c == '*'|| c == '/' || c == '{'|| c == '[')
        {
            s.push(c);
        }
        if(c == ')' )
        {
            if(s.isempty())
                {
                    cout << "not well parathesised ! ";
                    return 0;
                }
            while(s.peak() != '(')
            {
                s.pop();
            }
            s.pop();
        }
        if(c == '}' )
        {
            if(s.isempty())
                {
                    cout << "not well parathesised ! ";
                    return 0;
                }
            while(s.peak() != '{')
            {
                s.pop();
            }
            s.pop();
        }
        if(c == ']' )
        {
            if(s.isempty())
                {
                    cout << "not well parathesised ! ";
                    return 0;
                }
            while(s.peak() != '[')
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