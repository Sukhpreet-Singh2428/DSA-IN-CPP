//! Second Largest element in an Array 
//* (Easy Problem)

//? Eg :  arr[] = {1,2,4,7,7,5}
//? Largest is 7 but second largest in not 7 here, it's actually 5.

//* Brute --> Better --> Optimal

//* Brute :
//? --> Sort
// #include<iostream>
// #include<vector>
// using namespace std;
// int partition(vector<int>& arr, int low, int high){
//     int pivot = arr[low];
//     int i = low;
//     int j = high;
//     while(i<j){
//         while(arr[i]<=pivot && i<=high-1){
//             i++;
//         }
//         while(arr[j]>pivot && j>=low+1){
//             j--;
//         }
//         if(i<j) swap(arr[i],arr[j]);
//     }
//     swap(arr[low],arr[j]);
//     return j;
// }
// void quicksort(vector<int>& arr, int low, int high){
//     if(low<high){
//         int pIndex = partition(arr,low,high);
//         quicksort(arr,low,pIndex-1);
//         quicksort(arr,pIndex+1,high);
//     }
// }
// void SecondLargestElement(vector<int>& arr){
//     quicksort(arr,0,arr.size()-1);
//     int largest = arr[arr.size()-1];
//     int secondLargest = -1;    //* or secondLargest = INT_MIN if negative numbers are also there 
//     for(int i=arr.size()-2; i>=0 ;i--){
//         if(arr[i] != largest){
//             secondLargest = arr[i];
//             break;
//         }
//     }
//     cout << secondLargest;
// }
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     SecondLargestElement(arr);
//     return 0;
// }
//? Time Complexity : O( NlogN + N ) 
//? sort --> NlogN
//? for thw worst case like arr[] = {1,7,7,7,7,7} here in the loop we go till the i=0
//? so in that case it takes O(N) or even if second largest doesn't exist then also it 
//? ends up taking o(N)
//? So Total Time Complexity : O( NlogN + N ) 


//* Better : 
//? Largest --> Second largest 
//? Two pass : first pass largest , second pass Slargest
//? --> O(2N)
// #include<iostream>
// #include<vector>
// #include<climits>
// using namespace std;
// void SecondLargestElement(vector<int>& arr){
//     int largest = arr[0];
//     for(int i=1; i<arr.size(); i++){
//         if(arr[i]>largest) largest = arr[i];
//     }
//     int Slargest = INT_MIN;  //* If negative numbers are also in array 
//     for(int i=0; i<arr.size(); i++){
//         if(arr[i]>Slargest && arr[i]!=largest) Slargest = arr[i];
//     }
//     cout << Slargest;
// }
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     SecondLargestElement(arr);
//     return 0;
// }
//? Time Complexity : O(N+N) --> O(2N)


//* Optimal : 
// #include<iostream>
// #include<vector>
// #include<climits>
// using namespace std;
// int SecondLargestElement(vector<int>& arr){
//     int largest = arr[0];
//     int Slargest = INT_MIN;  //* If negative numbers are also in array 
//     for(int i=1; i<arr.size(); i++){
//         if(arr[i]>largest){
//             Slargest = largest;
//             largest = arr[i];
//         }
//         else if(arr[i]>Slargest && arr[i]<largest){
//             Slargest = arr[i];
//         }
//     }
//     return Slargest;
// }
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     cout << SecondLargestElement(arr);
//     return 0;
// }
//? Time Complexity : O(N)


//! Second Smallest Element in an array 
//? Supposing Array has Second smallest element in it 

//* Optimal : 
#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int SecondSmallestElement(vector<int>& arr){
    int smallest = arr[0];
    int Ssmallest = INT_MAX;   
    for(int i=1; i<arr.size(); i++){
        if(arr[i]<smallest){
            Ssmallest = smallest;
            smallest = arr[i]; 
        }
        else if(arr[i]<Ssmallest && arr[i]>smallest){
            Ssmallest = arr[i];
        }
    }
    return Ssmallest;
}
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << SecondSmallestElement(arr);
    return 0;
}
//? Time Complexity : O(N)