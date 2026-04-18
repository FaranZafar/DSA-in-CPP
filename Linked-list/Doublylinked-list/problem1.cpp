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
class doublylist{
       private:
       node* head;
       node* tail;
       public:
       doublylist(){
        head=tail=NULL;
       }
       void insertbegn(int val){
        node* newNode=new node(val);
        if (head==NULL)
        {
            head=tail=newNode;
        }else{
            head->prev=newNode;
            newNode->next=head;
            head=newNode;
        }
        
       }
       void display(){
        
        if (head==NULL)
        {
            cout<<"doubly linked list is empty"<<endl;
        }else{
            node* temp=head;
            while (temp!=NULL)
            {
                cout<<temp->data<<"<->";
                temp=temp->next;
            }
            cout<<"NULL";
        }
        
       }
};
int main(){
  doublylist dl;
  dl.insertbegn(3);
  dl.insertbegn(2);
  dl.insertbegn(1);
  dl.display();
}