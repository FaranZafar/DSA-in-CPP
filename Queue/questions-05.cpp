#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=prev=NULL;
    }
};
class Queuelinked{
    private:
    node* front;
    node* rear;
    public:
    Queuelinked(){
        front=rear=NULL;
    }
    void enqueue(int val){
        node* newNode=new node(val);
        if (front==NULL)
        {
             front=rear=newNode;
        }else{
             rear->next=newNode;
             rear=newNode;
             rear->prev=front;
             cout<<"Value enter successfully.."<<endl;
        }
        
    }
    void dequeue(){
        
        if (front==NULL)
        {
            cout<<"Queued Is empty.."<<endl;
        }
        node* temp=front;
        front=front->next;
        if (front==NULL)
        {
            rear==NULL;
        }
        delete temp;
        cout<<"value removed successfully";
    }
    void display(){
        node* temp=front;
        if (temp==NULL)
        {
            cout<<"Queue is empty.."<<endl;
        }else{
            while (temp!=NULL)
            {
                cout<<temp->data<<" ->";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
        }
        
    }
};

int main(){
    int choice;
    Queuelinked ql;
    bool exit=false;
    do{
    cout<<"Enter Number to perform operation:"<<endl;
    cout<<"1.Create Queued\n";
    cout<<"2.Remove even number\n";
    cout<<"3.Display Queue\n";
    cout<<"4.Exit\n";
    cin>>choice;
    switch (choice)
    {
    case 1:{
        char cont;
        do
        {
            int val;
            cout<<"enter value:";
            cin>>val;
            ql.enqueue(val);
            cout<<"another value ? (y/n) ";
            cin>>cont;
        } while (cont=='y'||cont=='y');
        break;
    }
    case 2:{

    }
    
    default:
        break;
    }
    }while(!exit);
    
    

    return 0;
}