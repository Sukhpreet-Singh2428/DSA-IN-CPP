//! Check if the array is sorted
//* (easy problem)

//? eg : arr[] = {1,2,2,3,3,4} 
//?      arr[] = {1,2,1,3,4} (NOT)

#include<iostream>
#include<vector>
using namespace std;
bool isSorted(vector<int>& arr){
    for(int i=1; i<arr.size(); i++){
        if(arr[i] >= arr[i-1]){

        }
        else return false;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    if(isSorted(arr)) cout << "true";
    else cout << "false";
    return 0;
}
//? Time Complexity : O(N)