//! Recursion :

//?         Sum of first N numbers 
//?          ↙              ↘
//?     parameter           functional


//* Parameterised :
// #include<iostream>
// using namespace std;
// void f(int i, int sum){
//     if(i<1){
//         cout << sum;
//         return;
//     }
//     f(i-1, sum+i);
// }
// int main(){
//     int n;
//     cin >> n;
//     f(n,0);
//     return 0;
// }
//?        n = 3
//?                  f(3,0)  
//?                  / ↗
//?                f(2,3)  
//?                / ↗
//?              f(1,5)  
//?              / ↗
//?            f(0,6) 


//* Functional :
// #include<iostream>
// using namespace std;
// int f(int n){
//     if(n==0){
//         return 0;
//     }
//     return n + f(n-1);
// }
// int main(){
//     int n;
//     cin >> n;
//     cout << f(n);
//     return 0;
// }
//? You can dry run :
//? for n = 3
//? first f(3) --> return 3 + f(2)
//? so here it is waiting for unknown value of f(2)
//? f(2) called --> return 2 + f(1)
//? here it is waiting too 3 + something...
//? f(1) called --> return 1 + f(0)
//? here too waiting 
//? f(0) --> it returns --> return 0
//? value of f(1) is 1
//? value of f(2) is 3
//? value of f(3) is --> 3 + something... i.e, --> 3 + 3 --> 6
//? so at the end end 6 is return 


//? Factorial of N :

//* functional Recursion 
#include<iostream>
using namespace std;
int fact(int n){
    if(n==0){
        return 1;
    }
    return n*fact(n-1);
}
int main(){
    int n;
    cin >> n;
    cout << fact(n);
    return 0;
}
//? Time Complexity : O(N)
//? Space Complexity --> auxiliary space --> stack space --> O(N)