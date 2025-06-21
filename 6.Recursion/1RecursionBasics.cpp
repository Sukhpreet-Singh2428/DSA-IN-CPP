//! Recursion :
//* When a function calls itself until a specified condition is met.

//? Infinite Recursion 
// #include<iostream>
// using namespace std;
// void print(){
//     cout << 1 << endl;
//     print();
// }
// int main(){
//     print();
//     return 0;
// }


//* Stack Overflow
//? void print(){                       void print(){                       void print(){ 
//?     cout << 1 << endl;                  cout << 1 << endl;                  cout << 1 << endl;
//?     print();             --->           print();             --->           print();          --->    ...... they keep on calling
//? }                                   }                                   }
//?       (1)                                 (2)                                (3)          

//?   |                |
//?   |   print()      |
//?   |   print()      |
//?   |   print()      |
//?   |   print()      |
//?   |   print() (3)  |
//?   |   print() (2)  |
//?   |   print() (1)  |
//?   |    print()     |
//?   |_ _ _ _ _ _ _ _ |  

//* The function keeps calling other functions and does not executed and keep waiting 
//* first print function call then it calls print() (1) --> it calls print() (2) --> it calls print() (3) --> keep going 
//* they all are waiting in stack and they are not executed and waiting, after some moment when stacks fulls i.e, run out of memory 
//* then segmentation fault happens and commonly know as Stack Overflow
//! This is why infinite recursion is not writtens bcz they end up having Stack Overflow


//? Base Condition --> condition to stop recursion 
#include<iostream>
using namespace std;
int cnt = 0;
void f(){
    if(cnt==3){     //* <-- Base condition
        return;
    }
    cout << cnt << endl;
    cnt++;
    f();
}
int main(){
    f();
    return 0;
}


//* Recursion Tree :    <-- A visual representation of how recursive calls expand and return

//? for above code 
//?               f()
//?              / ↗
//?            f()
//?            / ↗
//?          f()
//?          / ↗
//?        f() 
//?       (return)
//* This is small representation of code how code working they calls the functions and functions....
//* and finally base condition met and that function returns and no more further calls and
//* the earlier ones starts executing one by one in the stack as one function returns so 
//* going back and one by one they call the executed/finished as one calls returns.