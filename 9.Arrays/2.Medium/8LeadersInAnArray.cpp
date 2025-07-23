//! Leaders in an array 
//* (Medium Problem)

//? Leader --> everything in the right should be smaller.

//? Eg:  arr[] = {10, 22, 12, 3, 0, 6}
//?    --> return {22, 12, 6}  [following order of the array, they appears]

//* Brute --> Better --> Optimal


//* Brute : 
// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int> Leaders(vector<int>& arr, int n){
//     vector<int> v;
//     for(int i=0; i<n; i++){
//         bool leader = true;
//         for(int j=i+1; j<n; j++){
//             if(arr[j]>arr[i]){
//                 leader = false;
//                 break;
//             }
//         }
//         if(leader==true) v.push_back(arr[i]);
//     }
//     return v;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     vector<int> ans = Leaders(arr, n);
//     for(auto it : ans){
//         cout << it << " ";
//     }
//     return 0;
// }
//? Time Complexity : O(N^2)  [not exactly, but near about]
//? Space Complexity : O(N)  [At worst case]
//? But this is not exactly an extra space, we are using it to store 
//? leaders and return it in format 
//? We can say that, Space Complexity : O(1)


//* Optimal : 
//? (back iteration)
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
vector<int> Leaders(vector<int>& arr, int n){
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i=n-1; i>=0; i--){
        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi, arr[i]);
    }

    reverse(ans.begin(), ans.end());  //? In order to get output format or can use sort depends how to present it
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> ans = Leaders(arr, n);
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}
//? Time Complexity : O(N)
//? Space Complexity : O(1) [As we use ans(container) to store leaders and just for returing]