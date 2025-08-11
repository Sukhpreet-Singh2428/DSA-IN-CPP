//! 3 Sum
//* (Hard Problem)

//? Eg:  arr[] = {-1,0,1,2,-1,-4}
//?      arr[i] + arr[j] + arr[k] = 0
//?      i != j != k
//? return --> {-1,2,-1}
//?        --> {0,1,-1}

//* Brute --> Better --> Optimal

//* Brute
// #include<iostream>
// #include<vector>
// #include<set>
// #include<algorithm>
// using namespace std;
// class Solution{
// public:
//     vector<vector<int>> _3sum(vector<int>& arr){
//         int n = arr.size();
//         set<vector<int>> st;
//         for(int i=0; i<n-2; i++){
//             for(int j=i+1; j<n-1; j++){
//                 for(int k=j+1; k<n; k++){
//                     if(arr[i] + arr[j] + arr[k] == 0){
//                         vector<int> temp = {arr[i], arr[j], arr[k]};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//         vector<vector<int>> ans(st.begin(), st.end());
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
//     Solution s;
//     vector<vector<int>> ans = s._3sum(arr);
//     for(int i=0; i<ans.size(); i++){
//         for(int j=0; j<ans[i].size(); j++){
//             cout << ans[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
//? Time Complexity : O(n^3 * log(no. of unique triplets))  [and we are sorting 3 elements so it is as good as O(1)]
//? Space Complexity : 2*O(no. of unique triplets)


//* Better 
//? (Hashing)
// #include<iostream>
// #include<vector>
// #include<set>
// #include<algorithm>
// using namespace std;
// class Solution{
// public:
//     vector<vector<int>> _3sum(vector<int>& arr){
//         int n = arr.size();
//         set<vector<int>> st;
//         for(int i=0; i<n-1; i++){
//             set<int> hashset;
//             for(int j=i+1; j<n; j++){
//                 int third = -(arr[i] + arr[j]);
//                 if(hashset.find(third) != hashset.end()){
//                     vector<int> temp = {arr[i], arr[j], third};
//                     sort(temp.begin(), temp.end());
//                     st.insert(temp);
//                 }
//                 hashset.insert(arr[j]);
//             }
//         }
//         vector<vector<int>> ans(st.begin(), st.end());
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
//     Solution s;
//     vector<vector<int>> ans = s._3sum(arr);
//     for(int i=0; i<ans.size(); i++){
//         for(int j=0; j<ans[i].size(); j++){
//             cout << ans[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
//? Time Complexity : O(N^2 * log(no. of unique triplets))
//? Space Complexity : O(N) + O(no. of unique triplets)*2


//* Optimal
//? (Two pointers)
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution{
public:
    vector<vector<int>> _3sum(vector<int>& arr){
        int n = arr.size();
       vector<vector<int>> ans;
       sort(arr.begin(), arr.end());
       for(int i=0; i<n; i++){
            if(i>0 && arr[i]==arr[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = arr[i] + arr[j] + arr[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k && arr[j] == arr[j-1]) j++;
                    while(j<k && arr[k] == arr[k+1]) k--;
                }
            }
       }
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
    Solution s;
    vector<vector<int>> ans = s._3sum(arr);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
//? Time Complexity : O(N*logN) + O(N^2)
//? Space Complexity : O(1)  [using spacce only to return answer]