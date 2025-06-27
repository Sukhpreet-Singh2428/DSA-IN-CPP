//! Bubble Sort : 
//* Push the max. to the last by ADJACENT SWAPS 

// #include<iostream>
// void SWAP(int* i, int *j){
//     int temp = *i;
//     *i = *j;
//     *j = temp;
// }
// void BubbleSort(int arr[], int n){
//     for(int i=0; i<n-1; i++){
//         for(int j=0; j<n-i-1; j++){
//             if(arr[j]>arr[j+1]){
//                 SWAP(&arr[j], &arr[j+1]);
//             }
//         }
//     }
// }
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     BubbleSort(arr,n);
//     for(int i=0;i<n;i++){
//         cout << arr[i] << " ";
//     }
//     return 0;
// }


//? Modify Version : 
//* Optimisation :
#include<iostream>
void SWAP(int* i, int *j){
    int temp = *i;
    *i = *j;
    *j = temp;
}
void BubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int didSWAP = 0;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                SWAP(&arr[j], &arr[j+1]);
                didSWAP = 1;
            }
        }
        if(didSWAP==0){
            break;
        }
    }
}
using namespace std;
int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    BubbleSort(arr,n);
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    return 0;
}
//* Time Complexity : O(N^2)  [worst complexity, Average]
//*                   O(N) [Best complexity of Bubble sort possible]
//?                   eg : arr = 1 2 3 4 5 6 already sorted gives O(N) in optimal version