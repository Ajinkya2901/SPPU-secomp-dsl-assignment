// Implement C++ program for expression conversion as infix to postfix and its evaluation 
// using stack based on given conditions: 1. Operands and operator, both must be single 
// character. 2. Input Postfix expression must be in a desired format. 3. Only '+', '-', '*' and '/ ' 
// operators are expected.
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

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

int main()
{
    string str ;
    cout << "Enter your string : " ;
    cin >> str;
    int n = str.length();

    stack s(n);
    string result;

    for (int i = 0; i < n; i++) 
    {
        char c = str[i];
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') )
            result += c;

        else if (c == '(')
            s.push('(');

        else if (c == ')') 
        {
            while (s.peak() != '(') {
                result += s.peak();
                s.pop();
            }
            s.pop();
        }
        else 
        {
            while (!s.isempty()&& prec(str[i]) <= prec(s.peak())) {
                result += s.peak();
                s.pop();
            }
            s.push(c);
        }
    }

    
    while (!s.isempty())
    {
        result += s.peak();
        s.pop();
    }

    cout << result << endl;
    
}