//! Find out how many times the array is Rotated
//* (Easy Problem)

//? Eg:  arr[] = {3, 4, 5, 1, 2}
//?   ---> return 3


//* Binary Search : 
//? Logic :-
//? Find the min in rotated sorted   (previous problem logic)
//? keep track of index of min in rotated sorted array, and i.e, the answer
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int MinimumInRotatedSortedArray(vector<int>& arr){
    int n = arr.size(); 
    int low = 0;
    int high = n-1;
    int ans = INT_MAX;
    int ind = -1;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[low] <= arr[high]){
            if(arr[low] < ans){     //? <-- simply here, write manually the codition to get for automatic ans = min(ans, arr[low]);
                ans = arr[low];
                ind = low;
            }
            break;
        }
        if(arr[low]<=arr[mid]){
            if(arr[low] < ans){
                ans = arr[low];
                ind = low;
            }
            low = mid+1;
        }
        else{
            if(arr[mid] < ans){
                ans = arr[mid];
                ind = mid;
            }
            high = mid-1;
        }
    }
    return ind;
}
int NumberOfTmeArrayIsRotated(vector<int>& arr){
    int n = arr.size(); 
    int ans = MinimumInRotatedSortedArray(arr);
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << NumberOfTmeArrayIsRotated(arr);
    return 0;
}
//? Time Complexity : O(log2N)
//? Space Complexity : O(1)