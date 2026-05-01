#include<iostream>
using namespace std;
class  node{
     public:
     int data;
     node* prev;
     node(int val){
        data=val;
        prev=NULL;
     }
};
class stack{
    private:
    node* top;
    public:
    stack(){
        top=NULL;
    }
    void insert(int val){
        node* newNode =new node(val);
        if (top==NULL)
        {
            top=newNode;
        }else{
            newNode->prev=top;
            top=newNode;
            cout<<"value entered \n";
        }
        
    }
    void pop(){
        if (top==NULL)
        {
            cout<<"Stack is underflow\n";
        }else{
            node* temp =top;
            top=top->prev;
            delete temp;
            cout<<"value deleted \n";
        }
        
    }
    void peek(){
        if (top==NULL)
        {
            cout<<"Stack is underflow\n";
        }else{
            cout<<"top is:"<<top->data<<endl;
        }
        
    }
    void display(){
        if (top==NULL)
        {
            cout<<"stack is empty\n";
        }else{
            while (top!=NULL)
            {
                cout<<top->data<<"->";
                top=top->prev;
            }
            cout<<"NULL"<<endl;
        }
        
    }
    bool isEmpty(){
        return top==NULL;
    }
};





int main(){
    stack sl;
    sl.insert(10);
    sl.insert(20);
    sl.insert(30);
    sl.display();
    return 0;
}