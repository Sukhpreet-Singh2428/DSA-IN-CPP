//! Count Subarrays with Given XOR k
//* (Hard Problem)

//? Eg:  arr[] = {4,2,2,6,4}  k=6
//?      {4,2}
//?      {6}
//?      {2,2,6}
//?      {4,2,2,6,4}
//? --> return 4

//* Brute --> Better --> Optimal

//* Brute 
// #include<iostream>
// #include<vector>
// using namespace std;
// int CountSubarraysWithXORk(vector<int>& arr, int k){
//     int n = arr.size();
//     int cnt = 0;
//     for(int i=0; i<n; i++){
//         for(int j=i; j<n; j++){
//             int XOR = 0;
//             for(int k=i; k<=j; k++){
//                 XOR = XOR ^ arr[k];
//             }
//             if(XOR == k) cnt++;
//         }
//     }
//     return cnt;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     int k;
//     cin >> k;
//     cout << CountSubarraysWithXORk(arr, k);
//     return 0;
// }
//? Time Complexity : O(N^3)
//? Space Complexity : O(1)


//* Better 
// #include<iostream>
// #include<vector>
// using namespace std;
// int CountSubarraysWithXORk(vector<int>& arr, int k){
//     int n = arr.size();
//     int cnt = 0;
//     for(int i=0; i<n; i++){
//         int XOR = 0;
//         for(int j=i; j<n; j++){
//             XOR = XOR ^ arr[j];
//             if(XOR == k) cnt++;
//         }
//     }
//     return cnt;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     int k;
//     cin >> k;
//     cout << CountSubarraysWithXORk(arr, k);
//     return 0;
// }
//? Time Complexity : O(N^2)
//? Space Complexity : O(1)


//* Optimal
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int CountSubarraysWithXORk(vector<int>& arr, int k){
    int n = arr.size();
    int cnt = 0;
    int preXOR = 0;
    unordered_map<int,int> mpp;
    mpp[preXOR]++;
    for(int i=0; i<n; i++){
        preXOR = preXOR ^ arr[i];

        int rem = preXOR ^ k;

        cnt += mpp[rem];

        mpp[preXOR]++;
    }
    return cnt;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    cout << CountSubarraysWithXORk(arr, k);
    return 0;
}
//? Time Complexity : O(N)  [or O(NlogN) for map]
//? Space Complexity : O(1)