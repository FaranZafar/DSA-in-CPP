#include<iostream>
using namespace std;
class QueueArray{
    private:
    int Queue[10];
    int front;
    int rear;
    public:
    QueueArray(){
        front=rear=-1;
    }
    //
    int size(){
        return(rear+1);
    }
    bool isEmpty(){
        if(front==-1){
            return true;
        }else{
            return false;
        }
    }
    bool isFull(){
        if(rear==10-1){
            return true;
        }else{
            return false;
        }
    }
    void Enqueue(int item){
        if(isFull()==true){
            cout<<"Cant insert because the Queue is Full..";

        }else{
            Queue[++rear]=item;
            cout<<"value entered"<<endl;
            if(front==-1){
                front++;
            }
        }
    }
    void dequeue(){
        if(isEmpty()==true){
            cout<<"Queue is empty"<<endl;;
        }else{
            if(front==rear){
                front--;

            }else{
                Queue[front++];
                cout<<"value deleted"<<endl;
            }
        }
    }
    void printQueue(){
        if(isEmpty()==true){
            cout<<"Queue is empty.."<<endl;
        }else{
            for(int i=front;i<=rear;i++){
                cout<<Queue[i]<<endl;
            }
        }
    }
};
int main(){
    QueueArray obj;
    obj.Enqueue(42);
    obj.Enqueue(37);
    obj.dequeue();
    obj.Enqueue(23);
    obj.Enqueue(20);
    obj.Enqueue(16);
    obj.printQueue();
    obj.dequeue();
    obj.Enqueue(46);
    obj.Enqueue(65);
    obj.printQueue();
    return 0;
}