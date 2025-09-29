//! Find Sqaure Root of a number
//* (Medium Problem)

//? Eg :  n = 25   --> return 5
//?       n = 30   --> return 5

//* Brute --> Better --> Optimal


//* Linear Search : 
// #include<iostream>
// using namespace std;
// int SqaureRoot(int n){
//     int ans = 1;
//     for(int i=1; i<=n; i++){
//         if(i*i <= n){
//             ans = i;
//         }
//         else{
//             break;
//         }
//     }
//     return ans;
// }
// int main(){
//     int n;
//     cin >> n;
//     cout << SqaureRoot(n);
//     return 0;
// }
//? Time Complexity : O(N)
//? Space Complexity : O(1)


//* Binary Search : 
#include<iostream>
using namespace std;
int SqaureRoot(int n){
    int ans = 1;
    int low = 1; 
    int high = n;
    while(low<=high){
        int mid = low + (high-low)/2;
        if((mid*mid) <= n){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    cout << SqaureRoot(n);
    return 0;
}