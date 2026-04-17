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
     // insert at given position
     void insertgivenpos(int pos, int val){
        if (head==NULL)
        {
            cout<<"linked list is empty"<<endl;
        }else if(pos==1){
            Node* newNode=new Node(val);
            newNode->next=head;
            head=newNode;
            cout<<"value Entered Successfully"<<endl;
        }else{
            Node* newNode=new Node(val);
            Node* temp=head;
            int count=1;
            while (temp!=NULL && count<pos-1)
            {
                temp=temp->next;
                count++;
            }
            if(temp==NULL){
                cout<<"invalid position"<<endl;
            }else{
                newNode->next=temp->next;
                temp->next=newNode;
                cout<<"value Entered Successfully"<<endl;
            }
        }
        
     }
    // delete at a given position
    void deletegivenpos(int pos){
        if (head==NULL)
        {
            cout<<"linked list is empty"<<endl;
        }else if(pos==1){
            Node* temp=head;
            head=head->next;
            if(head==NULL) tail=NULL;
            delete temp;
            cout<<"value deleted successfully."<<endl;
        }else{
          Node* temp=head;
          int count=1;
          while (temp!=NULL && count<pos-1)
          {
            count++;
            temp=temp->next;
          }
          if (temp==NULL || temp->next==NULL)
          {
            cout<<"Invalid position"<<endl;
          }else{
            Node* toDelete=temp->next;
            temp->next=toDelete->next;
            if(toDelete==tail) tail=temp;
            delete toDelete;
            cout<<"value deleted successfully."<<endl;
          }
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
    l1.insertgivenpos(2,4);
    l1.deletegivenpos(1);
    l1.display();
   
}