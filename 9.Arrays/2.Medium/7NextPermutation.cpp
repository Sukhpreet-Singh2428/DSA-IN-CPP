//! Next Permutation 
//* (Medium Problem)

//?  Eg :  arr[] = {3,1,2}   --> 3! = 6
//?       return --> 3 2 1

//?        1 2 3 
//?        1 3 2 
//?        2 1 3 
//?        2 3 1 
//?        3 1 2 
//?        3 2 1

//* Brute --> Better --> Optimal

//* Brute : 
//? 1. Generate all permutation in sorted order
//? 2. Linear Search 
//? 3. Next Permutation

//? Recursion : (All permutation)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void recurPermute(vector<int>& ds, vector<int>& arr, vector<vector<int>>& ans, int freq[]){
    if(ds.size()==arr.size()){
        ans.push_back(ds);
        return;
    }
    for(int i=0; i<arr.size(); i++){
        if(!freq[i]){
            ds.push_back(arr[i]);
            freq[i] = 1;
            recurPermute(ds, arr, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> AllPermute(vector<int>& arr){
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[arr.size()] = {0};
    recurPermute(ds, arr, ans, freq);
    return ans;
}
void NextPermutation(vector<int>& arr, int n){
    vector<vector<int>> all = AllPermute(arr);

    sort(all.begin(), all.end());

    int index = -1;
    for(int i=0; i<all.size(); i++){
        if(all[i]==arr){
            index = i;
            break;
        }
    }

    if(index != -1 && index+1 < all.size()){
        for(auto it : all[index+1]){
            cout << it << " ";
        }
    }
    else{
        for(auto it : all[0]){
            cout << it << " ";
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    NextPermutation(arr, n);
    return 0;
}
//? Time Complexity : O( N! * N)
//? Space Complexity : O(N) + O(N)


//* Better : 
//? STL --> next_permutation()