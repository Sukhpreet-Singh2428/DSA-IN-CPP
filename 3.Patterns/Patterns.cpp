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
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=i; j++){
//             cout << "* ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//! (3)
//? 1
//? 1 2 
//? 1 2 3
//? 1 2 3 4
//? 1 2 3 4 5
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=i; j++){
//             cout << j << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//! (4)
//? 1
//? 2 2 
//? 3 3 3
//? 4 4 4 4
//? 5 5 5 5 5 
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     for(int i=1; i<=n; i++){
//         for(int j=1; j<=i; j++){
//             cout << i << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//! (5)
//? * * * * *
//? * * * *
//? * * *
//? * * 
//? *
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     for(int i=n; i>=1; i--){
//         for(int j=i; j>=1; j--){
//             cout << "* ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//! (6)
//? 1 2 3 4 5
//? 1 2 3 4
//? 1 2 3
//? 1 2
//? 1
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     for(int i=n; i>=1; i--){
//         for(int j=i; j>=1; j--){
//             cout << i-j+1 << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//! (7)
//?     *
//?    ***
//?   *****
//?  *******
//? *********
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n-i;j++){
//             cout << " ";
//         }
//         for(int k=1;k<=2*i-1;k++){
//             cout << "*";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//! (8)
//? *********
//?  *******
//?   *****
//?    ***
//?     *
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     for(int i=n; i>=1; i--){
//         for(int j=1;j<=n-i;j++){
//             cout << " ";
//         }
//         for(int k=1;k<=2*i-1;k++){
//             cout << "*";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//! (9)
//?     *
//?    ***
//?   *****
//?  *******
//? *********
//?  *******
//?   *****
//?    ***
//?     *
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n-i;j++){
    //         cout << " ";
    //     }
    //     for(int k=1;k<=2*i-1;k++){
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
    // for(int i=n-1;i>=1;i--){
    //     for(int j=1;j<=n-i;j++){
    //         cout << " ";
    //     }
    //     for(int k=1;k<=2*i-1;k++){
    //         cout << "*";
    //     }
    //     cout << endl;
    // }
//     return 0;
// }

//! (10)
//? *
//? * * 
//? * * * 
//? * * * * 
//? * * * * * 
//? * * * * 
//? * * *
//? * * 
//? *
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             cout << "* ";
//         }
//         cout << endl;
//     }
//     for(int i=n-1;i>=1;i--){
//         for(int j=1;j<=i;j++){
//             cout << "* ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//! (11)
//? 1
//? 0 1
//? 1 0 1
//? 0 1 0 1
//? 1 0 1 0 1
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     for(int i=1;i<=n;i++){
//         int x = 1;
//         for(int j=1;j<=i;j++){
//             if(i%2!=0){
//                 cout << x << " ";
//                 if(x==0) x++;
//                 else x--;
//             } else{
//                 if(x==0) x++;
//                 else x--;
//                 cout << x << " ";
//             } 
//         }
//         cout << endl;
//     }
//     return 0;
// }

//! (12)
//* 1      1
//* 12    21
//* 123  321
//* 12344321
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     int space = 2*(n-1);
//     for(int i=1;i<=n;i++){
//         //* numbers
//         for(int j=1;j<=i;j++){
//             cout << j;
//         }
//         //* space
//         for(int j=1;j<=space;j++){
//             cout << " ";
//         }
//         //* numbers
//         for(int j=i;j>=1;j--){
//             cout << j;
//         }
//         cout << endl;
//         space -= 2;
//     }
//     return 0;
// }

//! (13)
//? 1
//? 2 3
//? 4 5 6
//? 7 8 9 10
//? 11 12 13 14 15
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     int num = 1;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             cout << num++ << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//! (14)
//? A
//? AB
//? ABC
//? ABCD
//? ABCDE
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     for(int i=1;i<=n;i++){
//         char letter = 'A';
//         for(int j=1;j<=i;j++){
//             cout << letter++;
//         }
//         cout << endl;
//     }
//     return 0;
// }

//! (15)
//? ABCDE
//? ABCD
//? ABC
//? AB
//? A
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     for(int i=n;i>=1;i--){
//         char letter = 'A';
//         for(int j=1;j<=i;j++){
//             cout << letter++;
//         }
//         cout << endl;
//     }
//     return 0;
// }

//! (16)
//? A
//? BB
//? CCC
//? DDDD
//? EEEEE
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     char letter = 'A';
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=i;j++){
//             cout << letter;
//         }
//         cout << endl;
//         letter++;
//     }
//     return 0;
// }

//! (17)
//*     A
//*    ABA
//*   ABCBA
//*  ABCDCBA
//* ABCDEDCBA
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     for(int i=1;i<=n;i++){
//         char letter = 'A';
//         for(int j=1;j<=n-i;j++){
//             cout << " ";
//         }
//         for(int j=1;j<=i;j++){
//             cout << letter++;
//         }
//         letter -= 2;
//         for(int j=i-1;j>=1;j--){
//             cout << letter--;
//         }
//         cout << endl;
//     }
//     return 0;
// }

//! (18)
//* E
//* D E
//* C D E
//* B C D E
//* A B C D E
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     char letter = 'A' + n;
//     for(int i=1;i<=n;i++){
//         char ch = letter - i;
//         for(int j=1;j<=i;j++){
//             cout << ch++ << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//! (19)                       stars,   spaces    , stars
//? **********                   5        0           5
//? ****  ****                   4        2           4
//? ***    ***                   3        4           4
//? **      **                   and so on we calculate.....
//? *        *                   then we think the logic to match things
//? *        *                   accordingly
//? **      **                   DRY RUN helps
//? ***    ***
//? ****  ****
//? **********
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     for(int i=1;i<=n;i++){
//         //* stars
//         for(int j=1;j<=n-i+1;j++){
//             cout << "*";
//         }
//         //* spaces
//         int spaces = 2*(i-1);
//         for(int j=1; j<=spaces; j++){
//             cout << " ";
//         }
//         //* stars
//         for(int j=n-i+1; j>=1; j--){
//             cout << "*";
//         }
//         cout << endl;
//     }
//     for(int i=n;i>=1;i--){
//         //* stars
//         for(int j=1; j<=n-i+1; j++){
//             cout << "*";
//         }
//         //* spaces
//         int spaces = 2*(i-1);
//         for(int j=1; j<=spaces; j++){
//             cout << " ";
//         }
//         //* stars
//         for(int j=n-i+1; j>=1; j--){
//             cout << "*";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//! (20)
//? *        *
//? **      **
//? ***    ***
//? ****  ****
//? **********
//? ****  ****
//? ***    ***
//? **      **
//? *        *
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     for(int i=1;i<=n;i++){
//         //* stars
//         for(int j=1;j<=i;j++){
//             cout << "*";
//         }
//         //* spaces
//         int spaces = 2*(n-i);
//         for(int j=1;j<=spaces;j++){
//             cout << " ";
//         }
//         //* stars
//         for(int j=i;j>=1;j--){
//             cout << "*";
//         }
//         cout << endl;
//     }
//     for(int i=n-1;i>=1;i--){
//         //* stars
//         for(int j=1;j<=i;j++){
//             cout << "*";
//         }
//         //* spaces
//         int spaces = 2*(n-i);
//         for(int j=1;j<=spaces;j++){
//             cout << " ";
//         }
//         //* stars
//         for(int j=i;j>=1;j--){
//             cout << "*";
//         }
//         cout << endl;
//     }
//     return 0;
// }

//! (21)
//? *****
//? *   *
//? *   *
//? *   *
//? *****
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     for(int i=1;i<=n;i++){
//         for(int j=1;j<=n;j++){
//             if(i==1 || j==1 || i==n || j==n){
//                 cout << "*";
//             }
//             else{
//                 cout << " ";
//             }
//         }
//         cout << endl;
//     }
// }

//! (22)
//* 4 4 4 4 4 4 4
//* 4 3 3 3 3 3 4
//* 4 3 2 2 2 3 4
//* 4 3 2 1 2 3 4
//* 4 3 2 2 2 3 4
//* 4 3 3 3 3 3 4
//* 4 4 4 4 4 4 4

//! n - val = new matrix
//? 0 0 0 0 0 0 0
//? 0 1 1 1 1 1 0
//? 0 1 2 2 2 1 0
//? 0 1 2 3 2 1 0
//? 0 1 2 2 2 1 0
//? 0 1 1 1 1 1 0
//? 0 0 0 0 0 0 0 
//! n - new matrix val = val
#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i=0; i<2*n-1;i++){
        for(int j=0; j<2*n-1;j++){
            int top = i;              //* these four are the distances from an val to access
            int left = j;
            int right = (2*n-2) - j;
            int down = (2*n-2) - i;
            cout << (n -min(min(top,down), min(left,right)));
        }
        cout << endl;
    }
    return 0;
}
