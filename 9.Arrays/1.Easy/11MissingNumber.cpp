//! Missing number 
//* (easy problem)

//? Eg:  arr[] = {1,2,4,5}  N = 5 (1 to n+1)
//?    --> Return 3

//* Brute --> Better --> Optimal 


//* Brute : 
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int MissingNumber(vector<int>& arr, int n){
//     for(int i=1; i<=n+1; i++){
//         int flag = 0;
//         for(int j=0; j<n; j++){
//             if(arr[j]==i){
//                 flag = 1;
//                 break;
//             }
//         }
//         if(flag==0) return i;
//     }
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << MissingNumber(arr,n);
//     return 0;
// }
//? Time Complexity : O(N*N) [worst case : hypotheticall,y bcz for most of cases inner loop never run till n due to the break]
//? Space Complexity : O(1)


//* Better : 
// #include<iostream>
// #include<vector> 
// using namespace std; 
// int MissingNumber(vector<int>& arr, int n){
//     int hash[n+2] = {0};   //? 1 to n+1
//     for(int i=0; i<n; i++){
//         hash[arr[i]] = 1;
//     }
//     for(int i=1; i<=n+1; i++){
//         if(hash[i]==0) return i;
//     }
//     return -1;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << MissingNumber(arr,n);
//     return 0;
// }
//? Time Complexity : O(N) + O(N)
//? Space Complexity : O(N)


//* Optimal : 
//* (1) Sum :
// #include<iostream>
// #include<vector> 
// using namespace std; 
// int MissingNumber(vector<int>& arr, int n){
//     int sum = (n+1)*(n+2)/2;   //? n*(n+1)/2
//     int s2 = 0;
//     for(int i=0; i<n; i++){
//         s2 += arr[i];
//     }
//     return sum-s2;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << MissingNumber(arr,n);
//     return 0;
// }
//? Time Complexity : O(N)
//? Space Complexity : O(1)


//* (2) XOR :
//? a^a = 0
//? 2^2 = 0
//? 5^5 = 0
//? 2^2^5^5 = 0
//? 2^2^2^2 = 0
//? 2^2^2^2^2 = 2 {0^2 = 2}
//* XOR1 = 1^2^3^4^5
//* XOR2 = 1^2^4^5
//* XOR1 ^ XOR2 = 3
//* (1^1) ^ (2^2) ^ (3) ^ (4^4) ^ (5^5) = 3
//?   0       0      3      0       0 

#include<iostream>
#include<vector> 
using namespace std; 
int MissingNumber(vector<int>& arr, int n){
    int XOR1 = 0;
    // for(int i=1; i<=n+1; i++){  //? --> O(N) + O(N) = O(2N)
    //     XOR1 = XOR1^i;
    // }
    int XOR2 = 0;
    for(int i=0; i<n; i++){
        XOR2 = XOR2^arr[i];
        XOR1 = XOR1^(i+1);
    }
    XOR1 = XOR1^(n+1);    //? --> Now TC : O(N)
    return XOR1^XOR2;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << MissingNumber(arr,n);
    return 0;
}
//? Time Complexity : O(N)
//? Space Complexity : O(1)

//? For very large n (risk of overflow), XOR is safer because it does not involve large intermediate sums