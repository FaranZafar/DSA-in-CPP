#include<iostream>
using namespace std;
#define Max 10
class arraystack{
   private:
   int stack[Max];
   int top=-1;
   public:
   void push(int x){
    if (top==Max-1)
    {
        cout<<"Stack is overflowed\n";
        return;
    }
    stack[++top]=x;
   }
   int pop(){
    if (top==-1)
    {
        cout<<"Stack is underflow\n";
        return -1; // return error value
    }
    return stack[top--];
   }
   void peek(){
    if (top!=-1)
    {
        cout<<"top is:"<<stack[top]<<endl;
    }
   }
   bool isEmpty(){
       return top == -1;
   }

};
int main(){
    arraystack as;
    string str;
    cout<<"Enter String to reverse it:";
    cin>>str;
     
    for (char c:str)
    {
        as.push(c);
    }
    string reversed="";
    while (!as.isEmpty())
    {
        reversed+=(char)as.pop();
    }
    cout<<"reversed string is:"<<reversed<<endl;
    




    // for (char c:str)
    // {
    //     as.push(c);
    // }
    // string reversed = "";
    // while (!as.isEmpty())
    // {
    //     reversed += (char)as.pop();
    // }
    // cout << "Reversed string: " << reversed << endl;
}