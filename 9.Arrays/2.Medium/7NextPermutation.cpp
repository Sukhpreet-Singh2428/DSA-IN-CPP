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
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// void recurPermute(vector<int>& ds, vector<int>& arr, vector<vector<int>>& ans, int freq[]){
//     if(ds.size()==arr.size()){
//         ans.push_back(ds);
//         return;
//     }
//     for(int i=0; i<arr.size(); i++){
//         if(!freq[i]){
//             ds.push_back(arr[i]);
//             freq[i] = 1;
//             recurPermute(ds, arr, ans, freq);
//             freq[i] = 0;
//             ds.pop_back();
//         }
//     }
// }
// vector<vector<int>> AllPermute(vector<int>& arr){
//     vector<vector<int>> ans;
//     vector<int> ds;
//     int freq[arr.size()] = {0};
//     recurPermute(ds, arr, ans, freq);
//     return ans;
// }
// void NextPermutation(vector<int>& arr, int n){
//     vector<vector<int>> all = AllPermute(arr);

//     sort(all.begin(), all.end());

//     int index = -1;
//     for(int i=0; i<all.size(); i++){
//         if(all[i]==arr){
//             index = i;
//             break;
//         }
//     }

//     if(index != -1 && index+1 < all.size()){
//         for(auto it : all[index+1]){
//             cout << it << " ";
//         }
//     }
//     else{
//         for(auto it : all[0]){
//             cout << it << " ";
//         }
//     }
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     NextPermutation(arr, n);
//     return 0;
// }
//? Time Complexity : O( N! * N)
//? Space Complexity : O(N) + O(N)


//* Better : 
//? STL --> next_permutation()
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// vector<int> NextPermutation(vector<int>& arr, int n){
//     next_permutation(arr.begin(), arr.end());
//     return arr;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     vector<int> ans = NextPermutation(arr, n);
//     for(auto it : ans){
//         cout << it << " ";
//     }
//     return 0;
// }


//* Optimal :  
//? (How the next_permutation works and implements)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> NextPermutation(vector<int>& arr, int n){
    int ind = -1;
    for(int i=n-2; i>=0; i--){
        if(arr[i]<arr[i+1]){
            ind = i;
            break;
        }
    }
    if(ind==-1){
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for(int i=n-1; i>ind; i--){
        if(arr[i]>arr[ind]){
            swap(arr[i], arr[ind]);
            break;
        }
    }

    reverse(arr.begin()+ind+1, arr.end());
    return arr;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> ans = NextPermutation(arr, n);
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}
//? Time Complexity : O(3N) [worst case]
//? Space Complexity : O(1)


//* The steps are the following:

//* Find the break-point, i: Break-point means the first index i from the back of the given array where arr[i] becomes smaller than arr[i+1].
//* For example, if the given array is {2,1,5,4,3,0,0}, the break-point will be index 1(0-based indexing). Here from the back of the array, 
//* index 1 is the first index where arr[1] i.e. 1 is smaller than arr[i+1] i.e. 5.
//* To find the break-point, using a loop we will traverse the array backward and store the index i where arr[i] is less than the value at index (i+1) i.e. arr[i+1].
//* If such a break-point does not exist i.e. if the array is sorted in decreasing order, the given permutation is the last one in the sorted order 
//* of all possible permutations. So, the next permutation must be the first i.e. the permutation in increasing order.
//* So, in this case, we will reverse the whole array and will return it as our answer.
//* If a break-point exists:
//* Find the smallest number i.e. > arr[i] and in the right half of index i(i.e. from index i+1 to n-1) and swap it with arr[i].
//* Reverse the entire right half(i.e. from index i+1 to n-1) of index i. And finally, return the array.
