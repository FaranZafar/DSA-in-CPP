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
class queue{
    private:
    node* front;
    node* rear;
    public:
    queue(){
        front=rear=NULL;
    }
    void enqueue(int val){
        node* newNode=new node(val);
    }

};

int main(){

    return 0;
}