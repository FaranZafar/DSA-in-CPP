
#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }

};
class linkedQueue{
    private:
    node* Front;
    node* Rear;
    public:
    linkedQueue(){
        Front=Rear=NULL;
    }
    void Enqueue(int val){
        node* newNode=new node(val);
        if (Front==NULL)
        {
            Front=Rear=newNode;
        }else{
            Rear->next=newNode;
            Rear=newNode;
            cout<<"Value set successfully."<<endl;
        }
        
    }
    void Dequeue(){
        
        if (Front==NULL)
        {
            cout<<"Queue is empty."<<endl;

        }else{
            node* temp=Front;
            Front=Front->next;
            if (Front == NULL) {
                Rear = NULL;
            }
            delete temp;
            cout<<"Value removed successfully."<<endl;
            
        }
        
    }
    void printqueue(){
        node* temp=Front;
        if(temp==NULL){
            cout<<"Queue is empty."<<endl;
        }else{
            while (temp != NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
            
        }
    }
    bool isEmpty(){
        return Front==NULL;
    }
    void getFront(){
        node* temp=Front;
        if (temp==NULL)
        {
            cout<<"Queue is empty"<<endl;
        }else{
            cout<<"Front of Queue is:"<<temp->data<<endl;

        }
        
    }
};
int main(){
    linkedQueue lq;
    lq.Enqueue(2);
    lq.Enqueue(8);
    lq.Enqueue(6);
    lq.Enqueue(3);
    lq.getFront();
    lq.printqueue();
    lq.Dequeue();
    lq.printqueue();
    lq.getFront();

}