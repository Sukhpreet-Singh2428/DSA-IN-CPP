//! Majority Element ( > n/2 times)
//* (Medium Problem)
//* --> Moore's Voting Algorithm

//? eg : arr[] = {2,2,3,3,1,2,2}
//?  --> return 2

//* Brute --> Better --> Optimal


//* Brute : 
//? (Linear Search for every element)
// #include<iostream>
// #include<vector>
// using namespace std;
// int MajorityElement(vector<int>& arr, int n){
//     for(int i=0; i<n; i++){
//         int cnt = 0;
//         for(int j=0; j<n; j++){
//             if(arr[j]==arr[i]) cnt++;
//         }
//         if(cnt > n/2) return arr[i];
//     }
//     return -1;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << MajorityElement(arr, n);
//     return 0;
// }
//? Time Complexity : O(N^2)
//? Space Complexity : O(1)


//* Better : 
//? (Hashing)
// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;
// int MajorityElement(vector<int>& arr, int n){
//     unordered_map<int, int> mpp;
//     for(auto it : arr){
//         mpp[it]++;
//     }
//     for(auto it : mpp){
//         if(it.second > arr.size()/2){
//             return it.first;
//         }
//     }
//     return -1;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     cout << MajorityElement(arr, n);
//     return 0;
// }
//? Time Complexity : O(N) + O(N) --> but we know that for worst case (i.e, extremely rare) 
//?                                  it turns to O(N^2). In that case we use map 
//?                                  then TC : O(NlogN) + O(N)
//? Space Complexity : O(N)  [worst case if only are unique element]


//* Optimal : 

//* Moore's Voting Algorithm 

#include<iostream>
#include<vector>
using namespace std;
int MajorityElement(vector<int>& arr, int n){
    int cnt = 0;
    int el;
    for(int i=0; i<n; i++){
        if(cnt==0){
            cnt = 1;
            el = arr[i];
        }
        else if(arr[i]==el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    //* verify  <-- this step will never be done if the problem states majority element always will exists
    int cnt1 = 0;
    for(int i=0; i<n; i++){
        if(arr[i]==el) cnt1++;
    }
    if(cnt1 > n/2){
        return el;
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
    cout << MajorityElement(arr, n);
    return 0;
}
//? Time Complexity : O(N) + O(N) [this verify, will not perform if majority element always exists]
//? Space Complexity : O(1)

//* -----------------------------------------------
//* 🧠 Thought Process: Moore’s Voting Algorithm
//* -----------------------------------------------

//? 🔸 Problem:
//? We need to find the element that occurs more than ⌊n/2⌋ times in the array.
//? It is guaranteed that such an element may or may not exist, so verification is needed.

//? 🔸 Intuition:
//? If an element is a "majority", it will survive cancellation against all other elements.
//? We use a smart count-based approach to identify this potential majority.

//? 🔸 Strategy:
//? - Maintain two variables:
//?     → element (potential candidate)
//?     → count (number of votes for that candidate)
//? - Traverse the array:
//?     - If count is 0, choose the current element as the new candidate.
//?     - If current element == candidate → count++
//?     - Else → count--

//? This ensures that majority elements get reinforced, and minority elements cancel out.

//? 🔸 Final Check:
//? Since the algorithm only gives a potential candidate, we run one more loop to verify 
//? its actual count (only if majority element is not guaranteed).

//? 🔸 Why is this Optimal?
//? - Time Complexity: O(N) → single pass to find candidate, one optional pass to verify.
//? - Space Complexity: O(1) → no extra space used.

//? 💡 This algorithm is known as Moore’s Voting Algorithm.
//? Used frequently in coding interviews (Google, Amazon, etc.)