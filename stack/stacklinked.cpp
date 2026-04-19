#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* prev;
    node(int val){
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
    void push(int x){
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
        cout<<"Popped:"<<tail->data<<endl;
        tail=tail->prev;
        tail->prev=NULL;
    }
    void peek(){
        if (tail!=NULL)
        {
            cout<<"Top Node data:"<<tail->data<<endl;
        }
        
    }
    void isEmpty(){
        if (tail==NULL)
        {
            cout<<"stack is empty\n";
        }
        
    }
};

int main(){
    stacklist sl;
    sl.isEmpty();
    sl.push(1);
    sl.push(2);
    sl.push(3);
    sl.push(4);
    sl.pop();
    sl.peek();
    return 0;
}