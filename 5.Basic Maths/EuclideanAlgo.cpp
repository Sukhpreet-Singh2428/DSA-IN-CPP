//* Euclidean Algorithm  (optimal way to find GCD)
//! Euclidean Algorithm  --> gcd(a,b) = gcd(a%b, b)     a>b

#include<iostream>
using namespace std;
void EuclideanAlgo(int a, int b){
    while(a>0 && b>0){
        if(a>b) a = a % b;
        else b = b % a;
    }
    if(a==0) cout << b;
    else cout << a;
}
int main(){
    int a,b;
    cin >> a >> b;
    EuclideanAlgo(a,b);
    return 0;
}
//* Time Complexity : O( log Φ(min(a,b)) )


//? For more in details : go through BasicMaths.cpp file