//! Maximum Consecutive Ones 
//* (easy problem)

//? Eg :  arr[] = {1,1,0,1,1,1,0,1,1}
//?       --> return 3

//* Brute --> Better --> Optimal


//* Optimal : 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int MaximumConsecutiveOnes(vector<int>& arr){
    int maxi = 0;
    int cnt = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            cnt++;
            maxi = max(maxi,cnt);
        }
        else cnt = 0;
    }
    return maxi;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n ; i++){
        cin >> arr[i];
    }
    cout << MaximumConsecutiveOnes(arr);
    return 0;
}
//? Time Complexity : O(N)
//? Space Complexity : O(1)