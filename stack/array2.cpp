#include<iostream>
using namespace std;
#define Max 10
class arraystack{
   private:
   char stack[Max];
   int top=-1;
   public:
   void push(char x){
    if (top==Max-1)
    {
        cout<<"Stack is overflowed\n";
        return;
    }
    stack[++top]=x;
   }
   char pop(){
    if (top==-1)
    {
        cout<<"Stack is underflow\n";
        return '\0'; // return error value
    }
    return stack[top--];
   }
   bool isballanced(string exp){
    for(char c:exp){
        if (c=='('||c=='{'||c=='[')
        {
            push(c);
        } else if (c==')' || c=='}' || c==']') {
            if(isEmpty()) return false;
            char open = pop();
            if ((c==')' && open!='(') ||
                (c=='}' && open!='{') ||
                (c==']' && open!='['))
            {
                return false;
            }
        }
    }
    return isEmpty();
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
   string exp;
   cout<<"enter expression:";
   cin>>exp;
   if (as.isballanced(exp))
   {
    cout<<"balanced"<<endl;
   }else{
    cout<<"not balanced"<<endl;
   }
   return 0;
}