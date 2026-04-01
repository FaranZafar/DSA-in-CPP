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
     node* head;
     public:
     stacklist(){
        head=NULL;
     }
     void push(int val){
        node* newNode=new node(val);
        if (head==NULL)
        {
            head=newNode;
        
        }else{
            newNode->prev=head;
            head=newNode;
        }
        
     }
     void pop(){
        if(head==NULL){
            cout<<"Stacklist is empty.."<<endl;
        }else{
            node* temp = head;
            head = head->prev;
            delete temp;
            cout<<"value poped successfully."<<endl;
        }
     }
     void display(){
        node* temp =head;
        if(temp==NULL){
            cout<<"Stack is empty..";
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
        return  head==NULL;
     }
};
int main(){
   stacklist sl;
   sl.push(10);
   sl.push(20);
   sl.push(30);
   sl.display();
   sl.pop();
   sl.display();
   
    return 0;
}