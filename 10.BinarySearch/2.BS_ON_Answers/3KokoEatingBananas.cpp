//! Koko Eating Bananas
//* (Medium Problem)

//* koko eating bananas --> Return the min integer k such that 
//*                         koko can eat all bananas within h hours
//*  k --> bananas/hr

//? Eg:  piles[] = {3, 6, 7, 11}   h = 8
//*   --> return 4  (4 bananas/hr)
//?       3    6   7    11
//?       |    |   |     |
//?       1    2   2     3   =  8
//?  so min is 4 bananas/hr


//* Brute --> Better --> Optimal

//* Brute : 
//? Linear Search 
// #include<iostream>
// #include<vector>
// #include<algorithm>
// #include<math.h>
// using namespace std;
// int calculateTotalTime(vector<int>& arr, int perHour){
//     int n = arr.size();

//     int totalHour = 0;
//     for(int i=0; i<n; i++){
//         totalHour += ceil( (double)arr[i]/(double)perHour );
//     }
//     return totalHour;
// }
// int KokoEatingBananas(vector<int>& arr, int hour){
//     int n = arr.size();

//     int maxElement = *max_element(arr.begin(), arr.end());
//     for(int i=1; i<=maxElement; i++){
//         int reqTime = calculateTotalTime(arr, i);
//         if(reqTime <= hour){
//             return i;
//         }
//     }
//     return maxElement;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     int hour;
//     cin >> hour;
//     cout << KokoEatingBananas(arr, hour);
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
#include<climits>
using namespace std;
int calculateTotalTime(vector<int>& arr, int perHour){
    int n = arr.size();
    int total = 0;
    for(int i=0; i<n; i++){
        total += ceil( (double)arr[i]/(double)perHour );
    }
    return total;
}
int KokoEatingBananas(vector<int>& arr, int hour){
    int n = arr.size();

    int low = 0;
    int high = *max_element(arr.begin(), arr.end());
    int ans = INT_MAX;
    while(low<=high){
        int mid = low + (high-low)/2;
        int totalHrs = calculateTotalTime(arr, mid);
        if(totalHrs <= hour){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int hour;
    cin >> hour;
    cout << KokoEatingBananas(arr, hour);
    return 0;
}
//? Time Complexity : O(N * log2(max))
//? Space Complexity : O(1)