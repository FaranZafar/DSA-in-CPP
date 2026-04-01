#include<iostream>
using namespace std;
#define limit 20 
class stack{
   int arr[limit];
   int topIndex;

   public:
   stack(){
    topIndex=-1; //stack is empty initialy
   }
   //add element function
   void push(int val){
    if(topIndex>=limit-1){
        cout<<"stack overflow! cannot Push"<<val<<endl;
        return;
    }
    arr[++topIndex]=val;
    cout<<"value pushed into stack"<<endl;
    }
    //remove the top value
    void pop(){
        if(topIndex<0){
            cout<<"stack is empty."<<endl;
            return;
        }
        topIndex--;
    }
    //return the top element with out removing it
    void getTop(){
        if(topIndex<0){
            cout<<"stack is empty.."<<endl;

        }else{
            cout<<"Top element is: "<<arr[topIndex]<<endl;
        }
    }

    bool isEmpty(){
        return (topIndex<0);
    }

};

int main(){
   stack s1;
   s1.push(10);
   s1.push(20);
   s1.push(40);
   while(!s1.isEmpty()){
        s1.getTop();
        s1.pop();
   }
   cout<<endl;

//    s1.getTop();
//    s1.pop();
//    s1.getTop();
   
   return 0;
}
