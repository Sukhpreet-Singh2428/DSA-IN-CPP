//! Find Kth Missing Number
//* (Easy Problem)


//? Eg:  arr[] = {2, 3, 4, 7, 11}   k = 5
//?   --> return 9


//* Brute --> Better --> Optimal 


//* Brute : 
//? Linear Search 
// #include<iostream>
// #include<vector>
// using namespace std;
// int KthMissingNumber(vector<int>& arr, int k){
//     int n = arr.size();

//     for(int i=0; i<n; i++){
//         if(arr[i] <= k){
//             k++;
//         }
//         else{
//             break;
//         }
//     }
//     return k;
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
//     cout << KthMissingNumber(arr, k);
//     return 0;
// }
//? Time Complexity : O(N)
//? Space Complexity : O(1)


//* Optimal : 
//? Binary Search 

//* --> Two nearby index
#include<iostream>
#include<vector>
using namespace std;
int KthMissingNumber(vector<int>& arr, int k){
    int n = arr.size();

    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        int missing = arr[mid] - (mid+1);
        if(missing < k){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    //* ans -> arr[high] + more     --> more = k - missing
    //* arr[high] + k - (arr[high] - (high+1))
    //* arr[high] + k - (arr[high] - high - 1)
    //* arr[high] + k - arr[high] + high + 1 
    //* k + high + 1
    return high+k+1;  //? or low + k   as low = high+1
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
    cout << KthMissingNumber(arr, k);
    return 0;
}
//? Time Complexity : O(logN)
//? Space Complexity : O(1)