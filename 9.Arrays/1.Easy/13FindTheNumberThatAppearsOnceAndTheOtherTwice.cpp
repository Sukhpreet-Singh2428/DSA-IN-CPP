//! Find the Number that Appears once, and the others twice.
//* (easy problem)

//? Eg :  arr[] = {1,1,2,3,3,4,4}
//?   --> return 2

//* Brute --> Better --> Optimal


//* Brute 
//? (Linear search for every number)
// #include<iostream>
// #include<vector>
// using namespace std;
// int NumberThatAppearsOnce(vector<int>& arr, int n){
//     for(int i=0; i<n; i++){
//         int num = arr[i];
//         int cnt = 0;
//         for(int j=0; j<n; j++){
//             if(arr[j]==num) cnt++;
//         }
//         if(cnt==1) return num;
//     }
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << NumberThatAppearsOnce(arr,n);
//     return 0;
// }
//? Time Complexity : O(N^2) 
//? Space Complexity : O(1)


//* Better 
//? (Hashing)
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int NumberThatAppearsOnce(vector<int>& arr, int n){
//     int maxi = *max_element(arr.begin(), arr.end());  //* --> O(N)
//     int hashArray[maxi+1] = {0};
//     for(int i=0; i<n; i++){      //* --> O(N)
//         hashArray[arr[i]]++;
//     }
//     for(int i=0; i<n; i++){      //* --> O(N)
//         if(hashArray[arr[i]]==1) return arr[i];
//     }
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << NumberThatAppearsOnce(arr,n);
//     return 0;
// }
//? Time Complexity : O(3N) --> O(N)
//? Space Complexity : O(maxi + 1)
//! But : 
//* Array hashing will not use if it has negatives, 10^9, 10^12
//* We use : --> map --> unordered_map with key long long, map<long long, int>

//* for(int i=0; i<n; i++){
//*     mpp[arr[i]]++;
//* }
//* --> map : --> TC = O(NlogM)
//* --> unordered_map --> TC = O(N) [for best case]
//*                       TC = O(N^2) [for worst case, that rare happen]
//* (As we know that map takes logN and unordered_map takes O(1) but O(N) for worst case at rarely happens)
//* so if array has critical values or worst case can happen then switch/prefer map over unordered_map

//? using map
// #include<iostream>
// #include<vector>
// #include<map>
// using namespace std;
// int NumberThatAppearsOnce(vector<int>& arr, int n){
//     map<long long, int> mpp;
//     for(int i=0; i<n; i++){
//         mpp[arr[i]]++; 
//     }
//     for(auto it : mpp){
//         if(it.second==1) return it.first;
//     }
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << NumberThatAppearsOnce(arr,n);
//     return 0;
// }
//? Time Complexity : O(NLogM) + O(N/2 + 1)
//? Space Complexity : O( N/2 + 1 ) [most of the number appears twice and there is one that appears once]


//* Optimal 
//? ( XOR )
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int NumberThatAppearsOnce(vector<int>& arr, int n){
    int XOR = 0;
    for(int i=0; i<n; i++){
        XOR = XOR^arr[i];
    }
    return XOR;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << NumberThatAppearsOnce(arr,n);
    return 0;
}
//* arr[] = {1,1,2,3,3,4,4}
//* XOR = 0
//* XOR = 0^1^1^2^3^3^4^4
//* !^1 = 0, 2^2 = 0, 3^3 = 0, 4^4 = 0
//* 0^2 = 2

//? Time Complexity : O(N)
//? Space Complexity : O(1)