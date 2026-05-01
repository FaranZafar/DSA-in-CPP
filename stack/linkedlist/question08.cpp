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
    void min(){
        int min=top->data;
        while (top!=NULL)
        {
            if (top->data<min)
            {
                min=top->data;
            }
            top=top->prev;
        }
        cout<<"Manimum Number:"<<min<<endl;
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
    sl.insert(40);
    sl.display();
    sl.min();
   sl.display();
    
}