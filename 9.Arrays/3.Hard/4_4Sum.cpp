//! 4 Sum
//* (Hard Problem)

//? Eg:  arr[] = {1,0,-1,0,-2,2}  target = 0
//?    num[i] + num[j] + num[k] + num[l] = target
//?    i != j != k != l
//? --> return  [-2,-1,1,2], [-2,0,0,2], [-1,0,0,1]


//* Brute --> Better --> Optimal 

//* Brute 
// #include<iostream>
// #include<vector>
// #include<set>
// #include<algorithm>
// using namespace std;
// class Solution{
// public:
//     vector<vector<int>> _4Sum(vector<int>& arr, int target){
//         int n = arr.size();
//         set<vector<int>> st;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 for(int k = j+1; k<n; k++){
//                     for(int l = k+1; l<n; l++){
//                         long long sum = arr[i] + arr[j];
//                         sum += arr[k];
//                         sum += arr[l];
//                         if(sum == target){
//                             vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
//                             sort(temp.begin(), temp.end());
//                             st.insert(temp);
//                         }
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
//     int target;
//     cin >> target;  //? --> 0
//     Solution s;
//     vector<vector<int>> ans = s._4Sum(arr, target);
//     for(int i=0; i<ans.size(); i++){
//         for(int j=0; j<ans[i].size(); j++){
//             cout << ans[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;    
// }
//? Time Complexity : O(N^4)
//? Space Complexity : 2 * O(no. of quads)


//* Better
// #include<iostream>
// #include<vector>
// #include<set>
// #include<algorithm>
// using namespace std;
// class Solution{
// public:
//     vector<vector<int>> _4Sum(vector<int>& arr, int target){
//         int n = arr.size();
//         set<vector<int>> st;
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 set<long long> hashset;
//                 for(int k=j+1; k<n; k++){
//                     long long sum = arr[i] + arr[j];
//                     sum += arr[k];
//                     long long fourth = target - sum;
//                     if(hashset.find(fourth) != hashset.end()){
//                         vector<int> temp = {arr[i], arr[j], arr[k], (int)fourth};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                     hashset.insert(arr[k]);
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
//     int target;
//     cin >> target;  //? --> 0
//     Solution s;
//     vector<vector<int>> ans = s._4Sum(arr, target);
//     for(int i=0; i<ans.size(); i++){
//         for(int j=0; j<ans[i].size(); j++){
//             cout << ans[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;    
// }
//? Time Complexity : O(N^3 * log(m))
//? Space Complexity : O(N) + O(no. of quads)*2


//* Optimal
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;
class Solution{
public:
    vector<vector<int>> _4Sum(vector<int>& arr, int target){
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            if(i>0 && arr[i] == arr[i-1]) continue;
            for(int j=i+1; j<n; j++){
                if(j != i+1 && arr[j] == arr[j-1]) continue;
                int k = j+1;
                int l = n-1;
                while(k<l){
                    long long sum = arr[i] + arr[j] + arr[k] + arr[l];
                    if(sum == target){
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        ans.push_back(temp);
                        k++;
                        l--;
                        while(k<l && arr[k] == arr[k-1]) k++;
                        while(k<l && arr[l] == arr[l+1]) l--;
                    }
                    else if(sum < target) k++;
                    else l--;
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
    int target;
    cin >> target;  //? --> 0
    Solution s;
    vector<vector<int>> ans = s._4Sum(arr, target);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;    
}
//? Time Complexity : O(N^3)
//? Space Complexity : O(1)  [we are using space to return the ans O(no. of quards), not for solving the problem]