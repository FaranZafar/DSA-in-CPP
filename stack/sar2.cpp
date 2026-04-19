#include<iostream>
using namespace std;
#define Max 10
class arraystack{
   private:
    int stack[Max];
    int top=-1;
   public: 
    void push(int x){
       if ( top==Max-1)
       {
         cout<<"Stack is overflowed\n";
         return;
       }
       stack[++top]=x;
       
    }
    void pop(){
        if (top==-1)
        {
            cout<<"Stack is overflowed\n";
            return;
        }
        cout<<"poped:"<<stack[top--]<<endl;

        
    }
    void peek(){
        if (top!=-1)
        {
            cout<<"Top Element:"<<stack[top]<<endl;
        }
        
    }
    void isEmpty(){
        if (top==-1)
        {
            cout<<"Stack is empty"<<endl;
        }
        
    }
};
int main(){
    arraystack as;
    as.isEmpty();
    as.push(1);
    as.push(2);
    as.push(3);
    as.push(4);
    as.pop();
    as.peek();


    return 0;
}