#include<iostream>
using namespace std;
#define max 30
class stack{
    int arr[max];
    int topIndex;
    public:
    stack(){
        topIndex=-1;
    }
    //value pushing function
    void push(int val){
        if(topIndex>=max-1){
           cout<<"Stack is overflowed."<<val<<" not pushed"<<endl;
           return;
        }
        arr[++topIndex]=val;
        cout<<"value pushed inthe stack.."<<endl;
    }
    //value pop function
    void pop(){
        if(topIndex<0){
            cout<<"stack is empty.."<<endl;
            return;
        }
        topIndex--;
        cout<<"value is poped successfully.."<<endl;
    }
    void top(){
        if(topIndex<0){
            cout<<"stack is empty.."<<endl;
        }else{
            cout<<"top element is:"<<arr[topIndex]<<endl;
        }
    }
    //check stack
    bool isEmpty(){
        return (topIndex<0);
    }
    bool isFull(){
        return (topIndex>=max-1);
    }
   
  
 
};
 //function to check matching
  bool isMatching(char open,char close){
        return (open=='(' && close ==')')||
        (open =='{' && close =='}')||
        (open =='[' && close == ']');
    }
   //main function
    bool isBalance(string exp){
        stack s;
        for(int i=0;i<exp.length();i++){
            char ch=exp[i];
            //opening brackets
            if(ch =='('|| ch=='{' || ch =='['){
                s.push(ch);
            }
            //closing brackets 
            else if(ch ==')'|| ch =='}'|| ch ==']'){
                if(s.isEmpty()) return false;
                 char top=s.top();
                 

                if(!isMatching(top,ch)) return false;
            } 
        }
        return s.isEmpty();
    }
int main(){
    // stack s2;
    // s2.push(1);
    // s2.push(2);
    // s2.push(3);
    // s2.push(4);
    // while (!s2.isEmpty())
    // {
    //     s2.top();
    //     s2.pop();
    // }
    // cout<<endl;
    string exp;
    cout<<"enter expression:";
    cin>>exp;
    // if()
    
    return 0;
}