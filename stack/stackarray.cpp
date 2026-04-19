#include<iostream>
using namespace std;
#define Max 10
int stack[Max];
int top=-1;

//function 1
void push(int x){
    if(top==Max-1){
        cout<<"Stack is overflowed\n";
        return;
    }
    stack[++top]=x;
}
//function 2
void pop(){
    if (top==-1)
    {
        cout<<"Stac is underflowed\n";
        return;
    }
    cout<<"Popped:"<<stack[top--]<<endl;
    
}
//function 3
void peek(){
    if (top!=-1)
    {
        cout<<"top element:"<<stack[top]<<endl;
    }
    
}
int main(){
    push(10);
    push(20);
    push(30);
    pop();
    peek();
    return 0;

}