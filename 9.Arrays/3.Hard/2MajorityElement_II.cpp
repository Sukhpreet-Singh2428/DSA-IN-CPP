//! Majority Element ( > n/3 times )
//* (Hard Problem)

//? Eg:  arr[] = {1,1,1,3,3,2,2,2}  n = 8
//? --> return {1,2}

//? Q). How many integers at MAX be there in the answer ??
//*     At Max 2 elements
//* eg :  8/3 = 2
//* so only those elements return whose freq > 2 i.e, 3
//* if there are more than 2, tells take 3 elements whose freq>2 i.e, 3 or more
//* --> 3 + 3 + 3 = 9 elements but size is 8. which is not possible
//* So only at Max 2 elements are possible who are > n/3


//* Brute 
// #include<iostream>
// #include<vector>
// using namespace std;
// class Solution{
// public:
//     vector<int> majorityElement2(vector<int>& arr){
//         vector<int> ans;
//         int n = arr.size();
//         for(int i=0; i<n; i++){
//             if(ans.size()==0 || ans[0] != arr[i]){
//                 int cnt = 0;
//                 for(int j=0; j<n; j++){
//                     if(arr[j] == arr[i]) cnt++;
//                 }
//                 if(cnt > n/3){
//                     ans.push_back(arr[i]);
//                 }
//             }
//             if(ans.size()==2) break;
//         }
//         return ans;
//     }
// };
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     Solution ans;
//     vector<int> v = ans.majorityElement2(arr);
//     for(auto it : v){
//         cout << it << " ";
//     }
//     return 0;
// }
//? Time Complexity : O(N^2)
//? Space Complexity : O(1)


//* Better 
//? (Hashing)
// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;
// class Solution{
// public:
//     vector<int> majorityElement2(vector<int>& arr){
//         vector<int> ans;
//         int n = arr.size();
//         unordered_map<int,int> mpp;
//         int mini = (int)(n/3) + 1;
//         for(int i=0; i<n; i++){
//             mpp[arr[i]]++;
//             if(mpp[arr[i]] == mini) ans.push_back(arr[i]);
//             if(ans.size()==2) break;
//         }
//         return ans;
//     }
// };
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     Solution ans;
//     vector<int> v = ans.majorityElement2(arr);
//     for(auto it : v){
//         cout << it << " ";
//     }
//     return 0;
// }
//? Time Complexity : O(N)
//? Space Complexity : O(N)


//* Optimal
//! Boyer-Moore Voting Algorithm

#include<iostream>
#include<vector>
#include<climits>
using namespace std;
class Solution{
public:
    vector<int> majorityElement2(vector<int>& arr){
        int n = arr.size();
        
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN;
        int el2 = INT_MIN;
        for(int i=0; i<n; i++){
            if(cnt1 == 0 && el2 != arr[i]){
                cnt1 = 1;
                el1 = arr[i];
            }
            else if(cnt2 == 0 && el1 != arr[i]){
                cnt2 = 1;
                el2 = arr[i];
            }
            else if(arr[i] == el1) cnt1++;
            else if(arr[i] == el2) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        vector<int> ans;
        //* manually checking 
        cnt1 = 0, cnt2 = 0;
        for(int i=0; i<n; i++){
            if(el1 == arr[i]) cnt1++;
            if(el2 == arr[i]) cnt2++;
        }

        int mini = (int)(n/3) + 1;
        if(cnt1>=mini) ans.push_back(el1);
        if(cnt2>= mini) ans.push_back(el2);

        if(ans.size()==2 && ans[0]>ans[1]) swap(ans[0], ans[1]);  //? In case, wants to return in sorted order

        return ans;
    }
};
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    Solution ans;
    vector<int> v = ans.majorityElement2(arr);
    for(auto it : v){
        cout << it << " ";
    }
    return 0;
}
//? Time Complexity : O(2N)
//? Space Complexity : O(1)