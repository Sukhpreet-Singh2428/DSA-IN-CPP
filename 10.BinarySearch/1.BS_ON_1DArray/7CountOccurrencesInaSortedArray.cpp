//! Count Occurrence In a Sorted Array
//* (Easy Problem)

//? Eg :  arr[] = {0, 0, 1, 1, 1, 2, 3}  target = 1
//?    ---> return 3


//* Binary Search : 
//? Exact similiar to first and last Occurrence Problem 
//? just return (lastOccurrence-firstOccurrence)+1 for count the occurrence
#include<iostream>
#include<vector>
using namespace std;
int First(vector<int>& arr, int x){
    int n = arr.size(); 
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] == x){
            ans = mid;
            high = mid-1;
        }
        else if(arr[mid] < x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
int Last(vector<int>& arr, int x){
    int n = arr.size(); 
    int low = 0;
    int high = n-1;
    int ans = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] == x){
            ans = mid;
            low = mid+1;
        }
        else if(arr[mid] < x){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
int CountOccurrenceInSortedArray(vector<int>& arr, int target){
    int n = arr.size(); 

    int firstOccurrence = First(arr, target);
    int lastOccurrence = Last(arr, target); 

    return (lastOccurrence-firstOccurrence)+1;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int target;
    cin >> target;
    cout << CountOccurrenceInSortedArray(arr, target);
    return 0;
}