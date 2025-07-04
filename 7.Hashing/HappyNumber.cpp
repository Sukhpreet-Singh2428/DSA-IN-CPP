//? 📝 Problem Statement:
//? Write an algorithm to determine if a number n is a happy number.
//? A happy number is a number defined by the following process:
//? 1. Starting with any positive integer, replace the number by the sum of the squares of its digits.
//? 2. Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle that does not include 1.
//? 3. A number is happy if this process ends in 1.

//? 🧠 Example:
//? Input:
//? n = 19
//? Process:
//? 1² + 9² = 82  
//? 8² + 2² = 68  
//? 6² + 8² = 100  
//? 1² + 0² + 0² = 1
//? Output:
//? true ✅

//? ❌ Example 2:
//? Input:
//? n = 2
//? Process:
//? 2² = 4  
//? 4² = 16  
//? 1² + 6² = 37  
//? ...  
//? Cycle detected (never reaches 1)
//? Output:
//? false ❌

//? 🧩 Constraints:
//? 1 <= n <= 2^31 - 1


//* Code : 
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int f(int n){
    int sum = 0;
    while(n>0){
        int digit = n%10;
        sum += digit*digit;
        n /= 10;
    }
    return sum;
}
int happyNum(int n, unordered_set<int>& st){
    if(n==1) return 1;
    if(st.count(n)) return 0;
    st.insert(n);
    return happyNum(f(n), st);
}
int main(){
    int n;
    cin >> n;
    unordered_set<int> st;
    int x = happyNum(n,st);
    cout << x;    //? 1 --> true , 0 --> false
    return 0;
}
//? Time Complexity : O( log10N ) or O( logN )
//? Space Complexity : O( logN )