//! Left Rotate the Array By D Places
//* (Easy problem)

//? eg :  arr[] = {1,2,3,4,5,6,7}   d = 2
//? after rotated by 2 --> {3,4,5,6,7,1,2}

//* Brute --> Better --> Optimal 


//* Brute : 
// #include<iostream>
// #include<vector>
// using namespace std;
// void LeftRotate(vector<int>& arr, int n, int d){
//     d = d % n;     //* After the n rotations or multiply of n rotations, we get back to the given array
//     int temp[d];
//     for(int i=0;i<d;i++){    //? Storing  [Dry Run for more better understanding]
//         temp[i] = arr[i];
//     }
//     for(int i = d; i<n; i++){    //? Shifting 
//         arr[i-d] = arr[i];
//     }
//     for(int i = n-d; i<n; i++){   //? after shifting, adding elements to the end 
//         arr[i] = temp[i - (n-d)];
//     }
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     int d;
//     cin >> d;
//     LeftRotate(arr,n,d);
//     for(auto it : arr){
//         cout << it << " ";
//     }
//     return 0;
// }
//? Time Complexity : O(d) + O(n-d) + O(d) --> O(n + d)
//? Space Complexity : O(d) [extra space]



//* Optimal 
//? (trying to solve in space complexity : O(1))
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void leftRotate(vector<int>& arr, int n, int k){
    if(k>n) k = k%n;
    reverse(arr.begin(), arr.begin()+k);    //* O(k)
    reverse(arr.begin()+k, arr.end());      //* O(n-k)
    reverse(arr.begin(), arr.end());        //* O(n)
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    leftRotate(arr,n,k);
    for(auto it : arr){
        cout << it << " ";
    }
    return 0;
}
//? Time Complexity : O(2N) --> nearly equal to O(N)
//? Space Complexity : O(1)


//! Right Rotate the Array By D Places
//? Eg: [1,2,3,4,5,6,7], D=2 => [6,7,1,2,3,4,5]

//* Optimal
// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// void RightRotate(vector<int>& arr, int n, int k){
//     if(k>n) k = k%n;
//     reverse(arr.end()-k, arr.end());
//     reverse(arr.begin(), arr.end()-k);
//     reverse(arr.begin(), arr.end());
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     int k;
//     cin >> k;
//     RightRotate(arr, n, k);
//     for(auto it : arr){
//         cout << it << " ";
//     }
//     return 0;
// }
//? Time Complexity : O(2N) <-- = O(N)
//? Space Complexity : O(1)