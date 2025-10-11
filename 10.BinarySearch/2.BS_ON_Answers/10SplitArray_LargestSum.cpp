//! Split Array - Largest Sum / Painter's Partition
//* (Hard Problem)

//? Eg:  arr[] = {10, 20, 30, 40}   k = 2
//* Split the array into k subarrays such that the max subarray sum is minimum
//? --> return 60


//* Optimal : 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int countPartitions(vector<int>& arr, int pages){
    int n = arr.size();

    int partitions= 1;
    int subarraySum = 0;
    for(int i=0; i<n; i++){
        if( (subarraySum + arr[i]) <= pages ){
            subarraySum += arr[i];
        }
        else{
            partitions++;
            subarraySum = arr[i];
        }
    }
    return partitions;
}
int largestSubarraySumMinimized(vector<int>& arr, int m){
    int n = arr.size();
    int sum = 0;
    for(auto it : arr){
        sum += it;
    }

    if(m > n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = sum;
    int ans = high;
    while(low<=high){
        int mid = low + (high-low)/2;
        int partitions = countPartitions(arr, mid);
        if(partitions > m){
            low = mid+1;
        }
        else{
            ans = mid;
            high = mid-1;
        }
    }
    return ans;   //? return low
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int m;
    cin >> m;
    cout << largestSubarraySumMinimized(arr, m);
    return 0;
}
//? Time Complexity : O(log2(sum-max+1))*O(N)
//? Space Complexity : O(1)