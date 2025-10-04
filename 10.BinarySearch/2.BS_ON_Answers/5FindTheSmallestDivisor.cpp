//! Find the Smallest Divisor
//* (Medium Problem)

//? Eg:   arr[] = {1, 2, 5, 9}   threshold = 6
//?    --> return 5

//* Brute --> Better --> Optimal 


//* Brute : 
//? Linear Search 
// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<math.h>
// using namespace std;
// int findTheSmallestDivisor(vector<int>& arr, int threshold){
//     int n = arr.size();

//     int maxi = *max_element(arr.begin(), arr.end());
//     for(int d = 1; d<=maxi; d++){
//         int sum = 0;
//         for(int i=0; i<n; i++){
//             sum += ceil( (double)arr[i]/(double)d );
//         }
//         if(sum <= threshold){
//             return d;
//         }
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
//     int threshold;
//     cin >> threshold;
//     cout << findTheSmallestDivisor(arr, threshold);
//     return 0;
// }
//? Time Complexity : O(max*N)
//? Space Complexity : O(1)


//* Optimal : 
//? Binary Search 
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int sumOfDivisions(vector<int>& arr, int divisor){
    int n = arr.size(); 

    int sum = 0;
    for(int i=0; i<n; i++){
        sum += ceil( (double)arr[i]/(double)divisor );
    }
    return sum;
}
int findTheSmallestDivisor(vector<int>& arr, int threshold){
    int n = arr.size();

    int low = 1;
    int high = *max_element(arr.begin(), arr.end());
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        int sum = sumOfDivisions(arr, mid);
        if(sum <= threshold){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int threshold;
    cin >> threshold;
    cout << findTheSmallestDivisor(arr, threshold);
    return 0;
}
//? Time Complexity : O(N*log2(max))
//? Space Complexity : O(1)