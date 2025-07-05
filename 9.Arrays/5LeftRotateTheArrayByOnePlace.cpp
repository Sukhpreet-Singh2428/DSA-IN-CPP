//! Left Rotate The Array By One Place 
//* (Easy problem)

//? eg :  arr[] = {1,2,3,4,5}  [try to solve in the given array, don't make the new array]
//? one left rotate --> {2,3,4,5,1}

//* Brute --> Better --> Optimal


//* Optimal :
#include<iostream>
#include<vector>
using namespace std;
void LeftRotateByOnePlace(vector<int>& arr, int n){
    int temp = arr[0];
    for(int i=1;i<n;i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    LeftRotateByOnePlace(arr,n);
    for(auto it : arr){
        cout << it << " ";
    }
    return 0;
}
//? Time Complexity : O(N)
//? Space Complexity : O(1)
//? Space in the algorithm : o(N) because we are using given array and modifying it 
//? and the extra space used is O(1) i.e, Space Complexity.
//? So there is the difference between these two terms
