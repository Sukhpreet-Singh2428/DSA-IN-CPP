//! Remove Duplicates in-place from Sorted Array 
//* (easy problem)

//? eg : arr[] = {1,1,2,2,2,3,3}
//?  --> arr[] = {1,2,3,_,_,_,_}  (We have to modify the given array, can't create new array)
//?  --> return 3 (return no. of unique elements)

//? Given a sorted array arr[] of integers, your task is to remove the duplicates in-place, 
//? such that each unique element appears only once. The relative order of the elements should be 
//? kept the same. After removing the duplicates, return the total number of unique elements.

//? You must not use any extra space (no additional array or data structures). 
//? Instead, modify the input array in-place to contain the unique elements at the beginning.
//? Output:
//? Return an integer k, the number of unique elements.
//? The first k elements of arr should contain the unique elements in the original order.
//? The remaining elements can be left as any value (ignored).


//* Brute --> Better --> Optimal

//* Brute : 
// #include<iostream>
// #include<vector>
// #include<set>
// using namespace std;
// int RemoveDuplicate(vector<int>& arr){
//     set<int> st;
//     for(int i=0; i<arr.size(); i++){
//         st.insert(arr[i]);
//     }
//     int index = 0;
//     for(auto it : st){
//         arr[index] = it;   //? Set stores in sorted order i.e, ascending order and we modifying the array values till no. of unique elements.
//         index++;
//     }
//     return index;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << RemoveDuplicate(arr);
//     return 0;
// }
//? Time Complexity :
//? set insert takes NlogN and their is also loop over N(N bcz for worst case if there are all unique elements)
//? TC : O( NlogN + N )
//? Space Complexity : O(N)


//* Optimal : 
//? Two pointer 
#include<iostream>
#include<vector>
using namespace std;
int RemoveDuplicate(vector<int>& arr){
    int i = 0;
    for(int j=1; j<arr.size(); j++){
        if(arr[j] != arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    cout << RemoveDuplicate(arr);
    return 0;
}
//? Time Complexity : O(N)
//? Space Complexity : O(1)