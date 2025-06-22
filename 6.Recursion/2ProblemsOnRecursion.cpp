//! Basic Recursion Problems

//? Print Name N terms using Recursion
// #include<iostream>
// using namespace std;
// void print(int i, int n){
//     if(i>n){
//         return;
//     }
//     cout << "Sukhpreet" << endl;
//     print(i+1,n);
// }
// int main(){
//     int n;
//     cin >> n;
//     print(1,n);
//     return 0;
// }
//?        n = 3
//?                  f(1,3)  --> cout 
//?                  / ↗
//?                f(2,3)  --> cout 
//?                / ↗
//?              f(3,3)  --> cout 
//?              / ↗
//?            f(4,3) --> return 
//* Time complexity --> O(N)
//* Space Complexity --> (we generally assume it stack space) --> O(N)  <-- in above code SC O(3) as there is 3 stack space occupied


//? Print linearly from 1 to N 
// #include<iostream>
// using namespace std;
// void f(int i, int n){
//     if(i>n){
//         return;
//     }
//     cout << i << endl;
//     f(i+1,n);
// }
// int main(){
//     int n;
//     cin >> n;
//     f(1,n);
//     return 0;
// }


//? Print linearly from N to 1
// #include<iostream>
// using namespace std;
// void f(int i, int n){
//     if(i<1){
//         return;
//     }
//     cout << i << endl;
//     f(i-1,n);
// }
// int main(){
//     int n;
//     cin >> n;
//     f(n,n);
//     return 0;
// }


//? Print Linearly from 1 to N
//* ( But by BackTrack )
//! Not allowing to do --> f(i+1, n)  --> not allow plus  
//* Backtracking : 
// #include<iostream>
// using namespace std;
// void f(int i, int n){
//     if(i<1){
//         return;
//     }
//     f(i-1,n);             //* <--- Doing backtrack, Not using + , tracking/printing from the back
//     cout << i << endl;    //* <--- focuses on the order of lines 
// }
// int main(){
//     int n;
//     cin >> n;
//     f(n,n);
//     return 0;
// }
//?  n = 3
//? f(3,3)
//? 3 < 1 --> false, it calls f(2,3) and waits in stack to be executed
//? 2 < 1 --> false, it calls f(1,3) and waits in stack to be executed
//? 1 < 1 --> false, it calls f(0,3) and waits in stack to be executed
//? 0 < 1 --> true, it returns 
//? --> now, the call f(0,3) of f(1,3) returns so that 
//? function executed and line cout runs and prints it's i value i.e, 1
//? --> the call f(1,3) of f(2,3) is executed so now cout line runs
//? prints it's i value i.e, 2
//? --> the call f(2,3) of f(3,3) is executed so now cout line runs
//? prints it's i value i.e, 3
//? 
//?                  f(3,3)  --> cout  (3)
//?                  / ↗
//?                f(2,3)  --> cout (2)
//?                / ↗
//?              f(1,3)  --> cout (1)
//?              / ↗
//?            f(0,3) --> return 


//? Print Lineraly from N to 1 
//* ( But using BackTrack )
//! Not Doing with '-' or not allowed to f(i-1,N)
//* Backtracking :
#include<iostream>
using namespace std;
void f(int i, int n){
    if(i>n){
        return;
    }
    f(i+1,n);
    cout << i << endl;
}
int main(){
    int n;
    cin >> n;
    f(1,n);
    return 0;
}
//?                  f(1,3)  --> cout  (3)
//?                  / ↗
//?                f(2,3)  --> cout (2)
//?                / ↗
//?              f(3,3)  --> cout (1)
//?              / ↗
//?            f(4,3) --> return 