//! Search in Rotated Sorted Array - II   [duplicates]
//* (Medium Problem)

//? Eg:  arr[] = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6}   target = 3
//?    ---> return true;


//* Binary Search : 
#include<iostream>
#include<vector>
using namespace std;
bool SerachRotatedSortedArray2(vector<int>& arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] == target) return true;

        if(arr[low] == arr[mid] && arr[mid] == arr[high]){    //* <------
            low++;
            high--;
            continue;
        }
        if(arr[low] <= arr[mid]){
            if(arr[low]<=target && target<=arr[mid]){
                high = high -1;
            }
            else{
                low = low+1;
            }
        }
        else{
            if(arr[mid] <= target && target <= arr[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return false;
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
    cout << SerachRotatedSortedArray2(arr, target);
    return 0;
}
//? Time Complexity : O(Log2N)  --> average ,  O(n/2)
//? Space Complexity : O(1)