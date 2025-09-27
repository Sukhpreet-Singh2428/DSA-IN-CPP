//! Find Maximum in Rotated Sorted Array II  [Duplicates]
//* (Hard Problem)

//? Eg :  arr[] = {2, 2, 2, 0, 1}
//?    ---> return 0


//* Binary Search : 
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int findMinimumInRotatedSortedArray_II(vector<int>& arr){
    int n = arr.size();

    int low = 0;
    int high = n-1;
    int mini = INT_MAX;
    if(n==1) return arr[0];
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[low]==arr[mid] && arr[mid]==arr[high]){
            mini = min(mini, arr[low]);
            low++;
            high--;
            continue;
        }
        if(arr[low]<=arr[mid]){
            mini = min(mini, arr[low]);
            low = mid+1;
        }
        else{
            mini = min(mini, arr[mid]);
            high = mid-1;
        }
    }
    return mini;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << findMinimumInRotatedSortedArray_II(arr);
    return 0;
}