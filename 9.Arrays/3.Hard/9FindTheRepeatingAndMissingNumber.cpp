//! Find the Repeating and Missing Number
//* (Hard Problem)

//? Eg:  arr = [4, 3, 6, 2, 1, 1]   n = 6    [ 1 to 6 ]
//?     repeating --> 1
//?     missing --> 5
//?     --> {1,5}

//* Brute --> Better --> Optimal

//* Brute : 
// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int> RepeatingAndMissing(vector<int>& arr){
//     int n = arr.size();
//     int repeating = -1;
//     int missing = -1;

//     for(int i=1; i<=n; i++){
//         int cnt = 0;
//         for(int j=0; j<n; j++){
//             if(arr[j] == i) cnt++;
//         }
//         if(cnt==2) repeating = i;
//         else if(cnt==0) missing = i;

//         if(repeating != -1 && missing != -1){
//             break;
//         }
//     }

//     return {repeating, missing};
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     vector<int> ans =  RepeatingAndMissing(arr);
//     for(auto it : ans){
//         cout << it << " ";
//     }
//     return 0;
// }
//? Time Complexity : O(N^2)
//? Space Complexity : O(1)


//* Better : 
// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int> RepeatingAndMissing(vector<int>& arr){
//     int n = arr.size();
//     int repeating = -1;
//     int missing = -1;
    
//     vector<int> hash(n+1, 0);
//     for(int i=0; i<n; i++){
//         hash[arr[i]]++;
//     }
//     for(int i=1; i<=n; i++){
//         if(hash[i]==2) repeating = i;
//         else if(hash[i]==0) missing = i;

//         if(repeating != -1 && missing != -1){
//             break;
//         }
//     }
//     return {repeating, missing};
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     vector<int> ans =  RepeatingAndMissing(arr);
//     for(auto it : ans){
//         cout << it << " ";
//     }
//     return 0;
// }

// #include<iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;
// vector<int> RepeatingAndMissing(vector<int>& arr){
//     int n = arr.size();
//     int repeating = -1;
//     int missing = -1;
//     unordered_map<int,int> mpp;

//     for(auto it : arr){
//         mpp[it]++;
//     }

//     for(auto it : mpp){
//         if(it.second>1) repeating = it.first;
//     }
//     for(int i=1; i<=n; i++){
//         if(mpp[i] == 0) missing = i;
//     }

//     return {repeating, missing};
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     vector<int> ans =  RepeatingAndMissing(arr);
//     for(auto it : ans){
//         cout << it << " ";
//     }
//     return 0;
// }
//? Time Complexity : O(2N)
//? Space Complexity : O(N)


//* Optimal : 

//* optimal 1
//? Maths
#include<iostream>
#include<vector>
using namespace std;
vector<int> RepeatingAndMissing(vector<int>& arr){
    long long int n = arr.size();
    //? S - Sn = x - y
    //? S2 - S2n
    long long SN = (n * (n+1))/2;
    long long S2N = (n * (n+1) * (2*n+1))/6;
    long long S = 0, S2 = 0;
    for(int i=0; i<n; i++){
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }
    long long int val1 = S - SN;   //? x - y
    long long int val2 = S2 - S2N;
    val2 = val2/val1;    //? X + Y
    long long x = (val1 + val2)/2;
    long long y = x - val1;
    return { (int)x, (int)y };

}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    vector<int> ans =  RepeatingAndMissing(arr);
    for(auto it : ans){
        cout << it << " ";
    }
    return 0;
}
//? Time Complexity : O(N)
//? Space Complexity : O(1)


//* Optimal 2
//? (XOR)
//? We can do this method after learning bit Manipulation