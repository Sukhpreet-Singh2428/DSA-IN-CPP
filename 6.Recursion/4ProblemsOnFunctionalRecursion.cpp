//! Problems on Recursion [ Functional Recursion ]

//? Reverse an array :

//* Using two pointer in Recursion 
// #include<iostream>
// using namespace std;
// void reverse(int* arr, int l, int r){
//     if(l>=r) return;
//     int temp = arr[l];
//     arr[l] = arr[r];
//     arr[r] = temp;
//     reverse(arr,l+1,r-1);
// }
// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     reverse(arr,0,n-1);
//     for(int i=0;i<n;i++){
//         cout << arr[i] << " ";
//     }
//     return 0;
// }

//* Using One pointer 
// #include<iostream>
// using namespace std;
// void reverse(int* arr, int i, int n){
//     if( i>=n/2 ) return;
//     swap(arr[i],arr[n-i-1]);   //? <-- there is an bulit swap also 
//     reverse(arr,i+1,n);
// }
// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     reverse(arr,0,n);
//     for(int i=0;i<n;i++){
//         cout << arr[i] << " ";
//     }
//     return 0;
// }



//? Check if a string is palindrome 

//* Using two pointer 
// #include<iostream>
// #include<string>
// using namespace std;
// bool CheckPalindrome(string &s, int l, int r){
//     if(l>=r) return true;
//     if(s[l]!=s[r]) return false; 
//     CheckPalindrome(s,l+1,r-1);
// }
// int main(){
//     string s;
//     getline(cin, s);   //* <-- to take input the whole string with spaces and cin >> s only take one word
//     int len = s.size();
//     if(CheckPalindrome(s,0,len-1)) cout << "true";
//     else cout << "false";
//     return 0;
// }

//* Using One pointer
// #include<iostream>
// #include<string>
// using namespace std;
// bool CheckPalindrome(string &s, int i, int n){
//     if(i>=n/2) return true;
//     if(s[i]!=s[n-i-1]) return false; 
//     CheckPalindrome(s,i+1,n);
// }
// int main(){
//     string s;
//     getline(cin, s);   //* <-- to take input the whole string with spaces and cin >> s only take one word
//     int len = s.size();
//     if(CheckPalindrome(s,0,len)) cout << "true";
//     else cout << "false";
//     return 0;
// }

//* Time Complexity : O(N/2)
//* Space Complexity --> auxiliary space --> stack space --> O(N/2)


//? Fibonacci Series up to Nth Term --> Multiple Recursion Calls