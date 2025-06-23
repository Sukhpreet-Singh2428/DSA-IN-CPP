//! Multiple Recursion Calls :

//? Fibonacci Series up to Nth Term
#include<iostream>
using namespace std;
int fibo(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fibo(n-1) + fibo(n-2);
}
int main(){
    int num;
    cin >> num;
    for(int i=0; i<=num; i++){
        cout << fibo(i) << " ";
    }
    return 0;
}
//? Now at this level, we can easily dry run it !! 

//? Recursion Tree :
//?                           f(4)
//?                       ↙↗       ↘↖ 
//?                    f(3)           f(2)
//?                 ↙↗  ↘↖         ↙↗   ↘↖ 
//?               f(2)   f(1)      f(1)   f(0)
//?              ↙↗  ↘↖         (return 1)  (return 0)
//?            f(1)   f(0)
//?      (return 1)   (return 0)

//* Time Complexity: O(2^N)
//* Space Complexity: O(N) (due to recursion stack)