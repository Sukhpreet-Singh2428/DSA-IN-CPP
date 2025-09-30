//! Find Nth root of a Number
//* (Medium Problem)

//? Eg:  N = 3, M = 27  --> return 3
//?      N = 4, M = 69  --> return -1


//* Brute --> Better --> Optimal


//* Linear Search : 
// #include<iostream>
// using namespace std;
// int power(int a, int b){
//     int ans = 1;
//     while(b--){
//         ans = ans*a;
//     }
//     return ans;
// }
// int findNthRoot(int n, int m){
//     for(int i=1; i<=m; i++){
//         int val = power(i, n);
//         if(val == m){
//             return i;
//         }
//         else if(val > m){
//             break;
//         }
//     }
//     return -1;
// }
// int main(){
//     int n;
//     cin >> n;
//     int m;
//     cin >> m;
//     cout << findNthRoot(n, m);
//     return 0;
// }
//? Time Complexity : O(M*N)
//? Space Complexity : O(1)


//* Binary Search : 
#include<iostream>
using namespace std;
//? return 1 if == m
//? return 0 if < m
//? return 2 if > m
int func(int mid, int n, int m){
    long long ans = 1;
    for(int i=1; i<=n; i++){
        ans = ans * mid;
        if(ans > m) return 2;
    }
    if(ans == m) return 1;
    return 0;
}
int findNthRoot(int n, int m){
    int low = 1;
    int high = m;
    while(low<=high){
        int mid = low + (high-low)/2;
        int midN = func(mid, n, m);
        if(midN == 1){
            return mid;
        }
        else if(midN == 0) low = mid+1;
        else high = mid-1;
    }
    return -1;
}
int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    cout << findNthRoot(n, m);
    return 0;
}
//? Time Complexity : O(log2M * N)
//? Space Complexity : O(1)