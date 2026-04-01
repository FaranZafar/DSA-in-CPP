#include<iostream>
using namespace std;
#define max 10
class stack{
  int arr[max];
  int topIndex;
  public:
  stack(){
    topIndex=-1;
  }
  void push(int val){
    if (topIndex>=max-1)
    {
        cout<<"stack is overfowed..."<<val<<" not pushed.."<<endl;
    }
    arr[++topIndex]=val;
    cout<<"value " <<val<< " pushed successfully.."<<endl;
    
  }
  void pop(){
    if (topIndex<0)
    {
        cout<<"stack is empty of this operation not performed.."<<endl;
    }
    topIndex--;
    cout<<"top value removed"<<endl;
  }
  void top(){
    if (topIndex<0)
    {
        cout<<"stack is empty.."<<endl;
    }else{
        cout<<"top index value is "<<arr[topIndex]<<endl;
    }
    
    
  }
  bool isEmpty(){
        return (topIndex<0);
    }

};
int main(){
   stack s;
   s.push(12);
   s.push(10);
   s.pop();
   s.top();
   s.pop();
   s.top();
}