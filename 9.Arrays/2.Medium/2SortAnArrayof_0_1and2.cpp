//! Sort an array of 0's, 1's and 2's
//* (Medium problem)
//* --> Dutch National Flag Algorithm

//? Eg :  arr[] = {0,1,2,0,1,2,1,2,0,0,0,1}


//* Brute --> Better --> Optimal

//* Brute :
//? (Sorting --> merge sort)
// #include<iostream>
// #include<vector>
// using namespace std;
// void merge(vector<int>& arr, int low, int mid, int high){
//     vector<int> temp;
//     int left = low;
//     int right = mid+1;
//     while(left<=mid && right<=high){
//         if(arr[left]<=arr[right]){
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else{
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }
//     while(left<=mid){
//         temp.push_back(arr[left]);
//         left++;
//     }
//     while(right<=high){
//         temp.push_back(arr[right]);
//         right++;
//     }
//     for(int i=low; i<=high; i++){
//         arr[i] = temp[i-low];
//     }
// }
// void mergesort(vector<int>& arr, int low, int high){
//     if(low>=high) return;
//     int mid = low + (high-low)/2;
//     mergesort(arr,low,mid);
//     mergesort(arr,mid+1,high);
//     merge(arr,low,mid,high);
// }
// void sortAnArray(vector<int>& arr, int n){
//     mergesort(arr,0,n-1);
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     sortAnArray(arr, n);
//     for(auto it : arr){
//         cout << it << " ";
//     }
//     return 0;
// }
//? Time Complexity : O(NLogN)
//? Space Complexity : O(N)


//* Better : 
// #include<iostream>
// #include<vector>
// using namespace std;
// void sortAnArray(vector<int>& arr, int n){
//     int cnt0 = 0, cnt1 = 0, cnt2 = 0;
//     for(int i=0; i<n; i++){
//         if(arr[i]==0) cnt0++;
//         else if(arr[i]==1) cnt1++;
//         else cnt2++;
//     }
//     for(int i=0; i<cnt0; i++) arr[i] = 0;
//     for(int i=cnt0; i<cnt0 + cnt1; i++) arr[i] = 1;
//     for(int i=cnt0 + cnt1; i<n; i++) arr[i] = 2;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0; i<n; i++){
//         cin >> arr[i];
//     }
//     sortAnArray(arr,n);
//     for(auto it : arr){
//         cout << it << " ";
//     }
//     return 0;
// }
//? Time Complexity : O(2N)
//? Space Complexity : O(1)


//* Optimal : 
//! Dutch National Flag Algorithm 

//? Algorithm contains three pointers
//? --> low, mid and high

//? 3 RULES : 
//? [0 ,..., low-1]  --> 0         extreme left
//? [low ,...., mid-1]  --> 1
//? [high+1 ,....., n-1]  --> 2    extreme right

//? Hypothetically array : 
//? 0     low-1  low      mid-1  mid       high  high+1   n-1
//? |       |     |         |     |         |      |       |
//? 0 0 0 0 0     1 1 1 1 1 1     - - - - - -      2 2 2 2 2 
//?                                 0/1/2
//? |________________________|     unsorted        |________|
//?        sorted                                    sorted

//?      low
//?       |
//? eg :  0,1,2,0,1,2,1,2,0,0,0,1
//?       |                     |
//?      mid                   high
//? 
//?   a[mid] == 0  --> swap(a[low], a[mid])
//?                    low++, mid++
//?   a[mid] == 1  --> mid++
//?   a[mid] == 2  --> swap(a[mid], a[high])
//?                    high--


#include<iostream>
#include<vector>
using namespace std;
void sortAnArray(vector<int>& arr, int n){
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
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
    sortAnArray(arr,n);
    for(auto it : arr){
        cout << it << " ";
    }
    return 0;
}
//? Time Complexity : O(N)   [single iteration]
//? Space Complexity : O(1)