#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data=value;
        next=NULL;
    }
};
class list{
     private:
     Node* head;
     Node* tail;
     public:
     list(){
        head=tail=NULL;
     }
     void Insertfornt(int value){
        Node* newNode=new Node(value);
        if(head==NULL){
            head=tail=newNode;
            cout<<"First Node entered "<<endl;
        }else{
            newNode->next=head;
            head=newNode;
            cout<<"Value entered"<<endl;
        }
     }
     //insert at the end
     void Insertend(int val){
        Node* newNode=new Node(val);
        if(head==NULL){
            head=tail=newNode;
            cout<<"value entered ";
        }else{
            tail->next=newNode;
            tail=newNode;
            cout<<"value entered"<<endl;
        }
     }
    //  count function
     void count(){
        Node* temp=head;
        int count = 0;
        if(temp==NULL){
            cout<<"0 Nodes"<<endl;

        }else{
            while (temp!=NULL)
            {
                count++;
                temp=temp->next;
            }
            cout<<"Total nodes are "<<count<<endl;
        }
     }
     //find minimum number
     void findmin(){
       Node* temp=head;
       int minNum=temp->data;
       if (temp==NULL)
       {
        cout<<"linkedlist is empty."<<endl;
       }else{
        while (temp!=NULL)
        {
            if (temp->data<minNum)
            {
                minNum=temp->data;
            }
            temp=temp->next;
        }
        cout<<"minimum number is:"<<minNum<<endl;
       }
       
     }
     //find maxmum number
     void findmax(){
       Node* temp=head;
       int minNum=temp->data;
       if (temp==NULL)
       {
        cout<<"linkedlist is empty."<<endl;
       }else{
        while (temp!=NULL)
        {
            if (temp->data>minNum)
            {
                minNum=temp->data;
            }
            temp=temp->next;
        }
        cout<<"maxmum number is:"<<minNum<<endl;
       }
       
     }
     // searching an element
     void search(int val){
        bool found=false;
        Node* temp=head;
        if(temp==NULL){
            cout<<"linked list is empty"<<endl;
        }else{
            while (temp!=NULL)
            {
                if (temp->data==val)
                {
                    found=true;
                    break;
                }
                temp=temp->next;
            }
            if(found){
                cout<<"element found"<<endl;
            }else{
                cout<<"not found"<<endl;
            }
        }
        
     }
     // delete first node
     void deletefirst(){
        if (head==NULL)
        {
            cout<<"linked list is empty"<<endl;
        }else{
            Node* temp=head;
            head=head->next;
            delete temp;
            cout<<"value deleted"<<endl;
        }
        
     }
     // delete at the end
     void deleteend(){
        if(head==NULL){
            cout<<"linked list is empty"<<endl;
        }else if(head==tail){
            delete head;
            head=tail=NULL;
            cout<<"value deleted"<<endl;
        }else{
            Node* temp=head;
            while (temp->next!=tail)
            {
                temp=temp->next;
            }
            delete tail;
            tail=temp;
            tail->next=NULL;
            cout<<"value deleted"<<endl;
        }
     }
     //display function
     void display(){
        Node* temp=head;
        if(temp==NULL){
            cout<<"linked list is empty"<<endl;
        }else{
            while (temp!=NULL)
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            }
            cout<<"NULL"<<endl;
            
        }
     }
};
int main(){
    list l1;
    l1.Insertfornt(3);
    l1.Insertfornt(2);
    l1.Insertfornt(1);
    l1.Insertend(4);
    l1.display();
    l1.count();
    l1.findmin();
    l1.findmax();
    l1.search(2);
    l1.deletefirst();
    l1.deleteend();
    l1.display();
   
}