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
        }
        top=top->prev;
        cout<<"value deleted\n";
        
    }
    void peek(){
        if (top==NULL)
        {
            cout<<"Stack is underflow\n";
        }else{
            cout<<"top is:"<<top->data<<endl;
        }
        
    }
    void count(){
        int count=0;
        if (top==NULL)
        {
            cout<<"Stack is Underflow \n";
        }else{
            while (top!=NULL)
            {
                count++;
                top=top->prev;
            }
            cout<<"The Count is:"<<count<<endl;
            
        }
        
    }
    void display(){
        node* temp=top;
        if (top==NULL)
        {
            cout<<"stack is empty\n";
        }else{
            while (temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->prev;
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
    sl.insert(1);
    sl.insert(2);
    sl.insert(3);
    sl.insert(4);
    sl.display();
    sl.count();
   sl.display();
    
}