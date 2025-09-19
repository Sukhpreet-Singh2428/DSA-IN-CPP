//! Floor and ceil in Sorted Array
//* (Easy Problem)

//* Floor --> Largest no. in array <= x
//* Ceil --> Smallest no. in array >= x

//?  Eg:  arr[] = {10, 20, 30, 40, 50}   x = 25
//?   return floor = 20, ceil = 30

//* Brute --> Better --> Optimal 

//* Optimal : 
#include<iostream>
#include<vector>
using namespace std;
int floor(vector<int>& arr, int x){
    int n = arr.size(); 
    int ans = -1;

    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(x >= arr[mid]){
            ans = arr[mid];
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
int ceil(vector<int>& arr, int x){
    int n = arr.size(); 
    int ans = -1;

    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(x <= arr[mid]){
            ans = arr[mid];
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
    int x;
    cin >> x;
    cout << floor(arr, x) << endl;
    cout << ceil(arr, x) << endl;
    return 0;
}