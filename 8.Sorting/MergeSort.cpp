//! Merge Sort :

//* Merge Sort ---> Divide & Merge

//? Eg :  [ 3,1,2,4,1,5,2,6,4 ]   n = 9

//? Divide   --> { either in 5 4 or 4 5}   [Hypothetical]
//?
//?                   [ 3,1,2,4,1,5,2,6,4 ]
//?                 (5)   ↙        ↘  (4) 
//? ([1,1,2,3,4])  [3,1,2,4,1]      [5,2,6,4] {similarly}
//?              (3)↙   ↘(2)                             
//?  ([1,2,3])  [3,1,2]  [4,1]  ([1,4])                                            
//?             ↙  ↘    ↙↗  ↘↖                                                 
//?  ([1,3]) [3,1]  [2]  [4]   [1]
//?        ↙↗  ↘↖
//?        [3]  [1]
//?      (now merge it)   <-- similar for all, we merge them in ascending order
//?       [3]    [1]
//?        ↘↖   ↗↙
//?         [1,3] 
//?  --> After divide & merge : arr = [1,1,2,2,3,4,4,5,6]
//* NOTE/POINT : when we divide array in bigger,smaller or smaller,bigger
//* like here we did 5,4 so follow similar famous below also like futher
//* also divide it similarly bigger,smaller (here 3,2)


//* Pesudo Code :
//? Eg :
//?                 low          high
//?                   ↖         ↗
//?                   [ 3,2,4,1,3 ]
//?                     ↙      ↘
//?                 [3,2,4]    [1,3]
//?                  |   |
//?                 low  high

//? mergeSort(arr, low, high) {     <-- recursion 
//?     if(low >= high) return;
//?     mid = (low + high)/2;
//?     mergeSort(arr, low, mid);        (Divide)
//?     mergeSort(arr, mid+1, high);     (Divide)
//?     merge(arr, low, mid, high);      (Merge)
//?}  
//? merge(arr, low, mid, high) {     
//?     temp --> [ ] (temperory array)
//?     left = low;
//?     right = mid + 1;
//?     while(left<=mid && right<=high){
//?         if(arr[left] <= arr[right]){
//?             temp.add(arr[left]);  (here .add just means add arr[left] to temp, it's pesudo code : .add is not in function at all)
//?             let++;
//?         }
//?         else{
//?             temp.add(arr[right]);
//?             right++;
//?         }
//?     }
//?     
//?     while(left<=mid){
//?         temp.add(arr[left]);
//?         left++;
//?     }
//?     while(right<=high){
//?         temp.add(arr[right]);
//?         right++;
//?     }
//?
//?     for( i=low --> i<=high){
//?         arr[i] = temp[i-low];
//?     }
//?}  


//* Code : 
#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid+1;
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}
void mergesort(vector<int>& arr, int low, int high){
    if(low>=high) return;
    int mid = (low + high)/2;
    mergesort(arr,low,mid);
    mergesort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    mergesort(arr,0,n-1);
    for(auto it : arr){
        cout << it << " ";
    }
    return 0;
}

//* Time Complexity : O( N * log2N )
//*                        [n]
//*                       ↙   ↘
//*                    n/2       n/2
//*                   ↙  ↘      ↙  ↘
//*                n/4   n/4   n/4   n/4
//*                 .      .    .      .
//*                 .      .    .      .
//* 
//* Dividing by 2 and we remember that for division by a has time complexity of logaN
//* so Time complexity is O(log2N) for Divide
//* and for merge is worst case is O(N)
//* Total Time Complexity is O( N * log2N )
//* { N * log2N (multiply) bcz as we know that after every division they are merge up(starts from bottom, when there are only single single elements) }

//* Space Complexity : O(N)