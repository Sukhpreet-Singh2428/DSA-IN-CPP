//! Search Insert Position
//* (Easy Problem)

//? Eg :  arr[] = {1, 2, 4, 7}  x = 6
//? --> return 3  [ {1, 2, 4, 6, 7} ]

//* Brute --> Better --> Optimal


//* Optimal : 
//? (Lower Bound concept)
#include<iostream>
#include<vector>
using namespace std;
int SearchInsertPosition(vector<int>& arr, int x){
    int n = arr.size();

    int low = 0;
    int high = n-1;
    int ans = n;
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid] >= x){
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
    int x; 
    cin >> x;
    cout << SearchInsertPosition(arr, x);
    return 0;
}