//* Patterns --> Nested Loops
//? Some rules : 
//! (1). for the outer loop, count the no. of lines
//! (2). for the innner loop, focus on the columns, and connnect them
//!      somehow to the rows
//! (3). Print them "*" inside the inner for loop
//! (4). Observe symmetry [optional]

//? Questions :- 

//! (1)
//?   * * * *
//?   * * * *
//?   * * * *
//?   * * * *
// #include<iostream>
// using namespace std;
// int main(){
//     for(int i=1;i<=4;i++){
//         for(int j=1;j<=4;j++){
//             cout << "* ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//! (2)
//? *
//? * *
//? * * * 
//? * * * * 
//? * * * * *
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}