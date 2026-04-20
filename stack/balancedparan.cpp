#include<iostream>
#include<string>
using namespace std;

class node{
    public:
    char data;
    node* prev;
    node(char val){
        data=val;
        prev=NULL;
    }
};
class stacklist{
    private:
    node* tail;
    public:
    stacklist(){
        tail=NULL;
    }
    void push(char x){
       node* newNode=new node(x);
       if (tail==NULL)
       {
         tail=newNode;
         return;
       }
       newNode->prev=tail;
       tail=newNode;
       
    }
    void pop(){
        if (tail==NULL)
        {
            cout<<"stack is empty\n";
            return;
        }
        node* temp = tail;
        tail=tail->prev;
        delete temp;
    }
    char top(){
        if (tail!=NULL)
        {
            return tail->data;
        }
        // assume not empty
        return '\0';
    }
    void peek(){
        if (tail!=NULL)
        {
            cout<<"Top Node data:"<<tail->data<<endl;
        }
        else
        {
            cout<<"stack is empty\n";
        }
        
    }
    bool isbalanced(string exp){
        for(char c : exp){
            if(c == '(' || c == '[' || c == '{'){
                push(c);
            }else if(c == ')'){
                if(isEmpty() || top() != '('){
                    return false;
                }
                pop();
            }else if(c == ']'){
                if(isEmpty() || top() != '['){
                    return false;
                }
                pop();
            }else if(c == '}'){
                if(isEmpty() || top() != '{'){
                    return false;
                }
                pop();
            }
        }
        return isEmpty();
    }
    bool isEmpty(){
        return tail==NULL;
    }
};


int main(){
    stacklist sl;
    string exp;
    cout << "Enter expression: ";
    cin >> exp;
    if(sl.isbalanced(exp)){
        cout << "Balanced" << endl;
    }else{
        cout << "Not balanced" << endl;
    }
    return 0;
}