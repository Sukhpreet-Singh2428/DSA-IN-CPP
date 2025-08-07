//! Pascal Triangle
//* (Hard Problem)

//? 
//?              1
//?           1      1  
//?        1     2      1
//?      1    3     3      1
//?   1     4     6     4     1
//?  1    5    10    10   5      1

//? (1) Give Row & Column, tell the element at that place
//?     R = 5, C = 3
//?  --> ans = 6

//? (2) Print any Nth row of pascal triangle
//?     N = 5
//?    1 4 6 4 1

//? (3) Given N, Print the entire triangle, N = 6


//! (1)

//* Brute : 
// ? -->    r-1
// ?            C
// ?              c-1
// #include<iostream>
// using namespace std;
// int fact(int n){
//     if(n<=1) return 1;
//     return n*fact(n-1);
// }
// int pascalTriangle(int r, int c){
//     int ans = fact(r-1)/( fact(c-1) * fact((r-1)-(c-1)));  //* This for is if we taking 1-based indexing like row starting from 1 [taking starting row as row 1]
//     int ans = fact(r)/( fact(c) * fact(r-c));  //* and this for zero-based 
//     return ans;  
// }
// int main(){
//     int r,c;
//     cin >> r >> c;
//     cout << pascalTriangle(r,c);
//     return 0;
// }
//? Time Complexity : O(r) + O(c) + O(r-c)
//? Space Complexity : O(1)


//* Optimal : 
//? optimal version to use nCr

//? 10c3 = 10! / 3! * 7!
//?      = 10 * 9 * 8 * 7! / 3 * 2 * 1 * 7!
//?      = 10 * 9 * 8 / 3 * 2 * 1
//? 
//? --> 10/1 * 9/2 * 8/3
// #include<iostream>
// using namespace std;
// int pascalTriangle(int n, int r){
//     long long res = 1;
//     for(int i=0; i<r; i++){
//         res = res*(n-i);
//         res = res/(i+1);
//     }
//     return res;
// }
// int main(){
//     int r,c;
//     cin >> r >> c;
//     cout << pascalTriangle(r,c);
//     return 0;
// }
//? Time Complexity : O(N) --> O(r)
//? space Complexity : O(1)


//! (2)

//* ( Nth row --> N elements )

//* Brute 
// #include<iostream>
// using namespace std;
// int NcR(int n, int r){
//     long long res = 1;
//     for(int i=0; i<r; i++){
//         res = res*(n-i);
//         res = res/(i+1);
//     }
//     return res;
// }
// void pascalTriangle(int n){
//     for(int c = 1; c<=n; c++){
//         cout << NcR(n-1, c-1) << " ";    //? 1 based indexing row
//     }
// }
// int main(){
//     int n;
//     cin >> n;
//     pascalTriangle(n);
//     return 0;
// }
//? Time Complexity : O(N*r)
//? Space Complexity : O(1)


//* optimal 
// #include<iostream>
// using namespace std;
// void pascalTriangle(int n){
//     long long ans = 1;
//     cout << ans << " ";
//     for(int i=1; i<n; i++){
//         ans = ans*(n-i);
//         ans = ans/i;
//         cout << ans << " ";
//     }
// }
// int main(){
//     int n;
//     cin >> n;
//     pascalTriangle(n);
//     return 0;
// }
//? Time Complexity : O(N)
//? Space Complexity : O(1)


//! (3)

//* Brute 
// #include<iostream>
// #include<vector>
// using namespace std;
// int NcR(int n, int r){
//     long long res = 1;
//     for(int i=0; i<r; i++){
//         res = res*(n-i);
//         res = res/(i+1);
//     }
//     return (int)res;
// }
// vector<vector<int>> pascalTriangle(int n){
//     vector<vector<int>> ans;
//     for(int i=1; i<=n; i++){
//         vector<int> temp;
//         for(int j=1; j<=i; j++){
//             temp.push_back(NcR(i-1, j-1));
//         }
//         ans.push_back(temp);
//     }
//     return ans;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<vector<int>> ans =  pascalTriangle(n);
//     for(int i=0; i<ans.size(); i++){
//         for(int j=0; j<ans[i].size(); j++){
//             cout << ans[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }
//? Time Complexity : O(N*N*r)  = nearly O(N^3)
//? Space Complexity : O(1)  [as we are using space in order to return ans, not to solve the problem]


//* Optimal
//? (using the generate row optimal logic)
#include<iostream>
#include<vector>
using namespace std;
vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col = 1; col<row; col++){
        ans = ans*(row-col);
        ans = ans/col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> ans;
    for(int i=1; i<=n; i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}
int main(){
    int n;
    cin >> n;
    vector<vector<int>> ans =  pascalTriangle(n);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}