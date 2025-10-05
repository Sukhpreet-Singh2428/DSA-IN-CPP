//! Capacity to Ship Packages Within D days 
//* (Hard Problem)

//? Least capacity to ship packages within d days
//? Eg:  weights[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}    days = 5
//?   --> return 15

//* Brute --> Better --> Optimal

//* Brute :
//? Linear Search 
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int reqDays(vector<int>& weight, int capacity){
//     int n = weight.size();

//     int days = 1;
//     int load = 0;
//     for(int i=0; i<n; i++){
//         if((load + weight[i]) > capacity){
//             days++;
//             load = weight[i];
//         }
//         else{
//             load += weight[i];
//         }
//     }
//     return days;
// }
// int CapacityToShipPackagesWithinDdays(vector<int>& weight, int days){
//     int n = weight.size(); 

//     int maxi = *max_element(weight.begin(), weight.end());
//     int sumOfWeights = 0;
//     for(auto it : weight){
//         sumOfWeights += it;
//     }
//     for(int i=maxi; i<=sumOfWeights; i++){
//         int requiredDays = reqDays(weight, i);
//         if(requiredDays <= days){
//             return i;
//         }
//     }
//     return -1;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> weight(n);
//     for(int i=0; i<n; i++){
//         cin >> weight[i];
//     }
//     int days;
//     cin >> days;
//     cout << CapacityToShipPackagesWithinDdays(weight, days);
//     return 0;
// }
//? Time Complexity : O((sum-max)+1) * O(n)
//? Space Complexity : O(1)


//* Optimal : 
//? Binary Search 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int reqDays(vector<int>& weight, int capacity){
    int n = weight.size();

    int days = 1;
    int load = 0;
    for(int i=0; i<n; i++){
        if((load + weight[i]) > capacity){
            days++;
            load = weight[i];
        }
        else{
            load += weight[i];
        }
    }
    return days;
}
int CapacityToShipPackagesWithinDdays(vector<int>& weight, int days){
    int n = weight.size(); 
    int sumOfWeights = 0;
    for(auto it : weight){
        sumOfWeights += it;
    }

    int low = *max_element(weight.begin(), weight.end());
    int high = sumOfWeights;
    int ans = high;
    while(low<=high){
        int mid = low + (high-low)/2;
        int requiredDays = reqDays(weight, mid);
        if(requiredDays <= days){
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
    vector<int> weight(n);
    for(int i=0; i<n; i++){
        cin >> weight[i];
    }
    int days;
    cin >> days;
    cout << CapacityToShipPackagesWithinDdays(weight, days);
    return 0;
}
//? Time Complexity : O( log2(sum-max+1) * N)
//? Space Complexity : O(1)