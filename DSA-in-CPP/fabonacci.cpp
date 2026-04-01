//for loop
// #include<iostream>
// using namespace std;
// int main(){
//     int previous1=0;
//     int previous2=1;
//     int newFabonacci=0;
//     for (int i = 0; i <18; i++)
//     {
//         newFabonacci=previous1+previous2;
//         cout<<newFabonacci<<endl;
//         previous1=previous2;
//         previous2=newFabonacci;
//     }
    
// }

// using recursion
// #include<iostream>
// using namespace std;
// void fabinocci(int c, int count, int previous1, int previous2){
//     if (count <= c)
//     {
//         int newFabinocci = previous1 + previous2;
//         cout << newFabinocci << endl;
//         fabinocci(c, count + 1, previous2, newFabinocci);
//     }
//     else{
//         return;
//     }
// };
// int main(){
//    fabinocci(5, 0, 0, 1);
// }

//    f(n-1)+(n-2)

#include<iostream>
using namespace std;
int f(int n){
    if(n<=1){
        return n;
    }else{
        return f(n-1)+f(n-2);
    }
}
int main(){
 cout<<f(19);
}