//! Linear Search 
//* (Easy Problem)

//? Eg :  arr[] = {6,7,8,4,1}  num = 4 
//?    --> return 3 (index)

//* Brute --> Better --> Optimal


//* Optimal
#include<iostream>
#include<vector>
using namespace std;
int LinearSearch(vector<int>& arr, int num, int n){
    for(int i=0; i<n; i++){
        if(arr[i]==num) return i;
    }
    return -1;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int num;
    cin >> num;
    cout << LinearSearch(arr, num, n);
    return 0;
}
//? Time Complexity : O(N) (worst case)
//? Space Complexity : O(1)