//! Hashing   <-- One of the most important topics of DSA 

//? Eg: Array --> 1 2 1 3 2

//? How many times 1 appears in array --> 2
//? 3 --> 1
//? 4 --> 0
//? 2 --> 2
//? 10 --> 0

//* Brute Approach/Code :
// #include<iostream>
// using namespace std;
// int f(int number, int arr[], int n){
//     int cnt = 0;
//     for(int i=0;i<n;i++){
//         if(arr[i]==number) cnt++;
//     }
//     return cnt;
// }
// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }
//     cout << f(1,arr,n);    //? <-- f(number, arr)
//     return 0;
// }
//* Time Complexity : For every number, we running loop till n times 
//* O(N) * 5   <-- for array 1,2,1,3,2
//* For an large array, having Q numbers  [ here Q can only be no. of elements i.e, n or maybe some extra number also to check like the above eg having 10 ]
//* TC : O(Q * N)
//* So for Q queries and array size N -> TC = O(Q * N)
//* Example: Array = {1, 2, 1, 3, 2}, Queries = {1, 3, 4, 2, 10} (Q = 5)
//? And if we only have to check for array elements only, then
//? TC : O(N * N)


//! Hashing : --> pre storing / fetching  [pre store something and fetch when required]

//* HashArray or Frequency Array :
//? eg : Array : 1,3,2,1,3 and we know that at max the element of array is upto 12
//? 5 --> 1 3 2 1 3  [size of array and elements]
//? 5 : 1 4 2 3 12 [No. of Queries and numbers]
//* Number hashing 
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//     }

//     //* precompute [prestoring or pre calucation]
//     int hash[13] = {0};   //* If the problems states elements it contains is upto 10000 --> hash[10001];
//     for(int i=0; i<n; i++){   //? In this particular eg, elements value are upto 12 so hash[13]
//         hash[arr[i]] += 1;
//     }

//     int q;
//     cin >> q;
//     while(q--){
//         int number;
//         cin >> number;
//         //* fetch
//         cout << hash[number] << endl;
//     }
//     return 0;
// }
//* Points :
//? For int :
//? max hash[10^6] can declare <-- inside main {beyond this it will throw segmentation error bcz it can't give/not have that much memeory}
//? max hash[10^7] <-- globally


//* Character hashing 
//? eg : s = "abcdabejc"
//? Q queries --> a, c, z, ....

//! Brute code/approach : --> same as for number above 
// //* Hashing : 
// #include<iostream>
// #include<string>
// using namespace std;
// int main(){
//     string s;
//     getline(cin, s);

    // //* pre compute 
    // int hash[26] = {0};     //? <-- only if string has only lowercase letters/Characters
    // for(int i=0;i<s.size();i++){
    //     hash[s[i] - 'a']++;
    // }

    // int q;
    // cin >> q;
    // while(q--){
    //     char ch;
    //     cin >> ch;
    //     //* fetch
    //     cout << hash[ch-'a'] << endl;
    // }

//     //* pre compute 
//     int hash[256] = {0};     //* We know that there are total 256 Characters
//     for(int i=0;i<s.size();i++){
//         hash[s[i]]++;
//     }

//     int q;
//     cin >> q;
//     while(q--){
//         char ch;
//         cin >> ch;
//         //* fetch
//         cout << hash[ch] << endl;
//     }
//     return 0;
// }
//* Point :
//? unlike int hash, there is no problem as at max there are 256 characters 
//? and array can store 256 characters 


//! In Number Hashing :   --->   STL  
//!                              ↙        
//!                            Map          
//!                       Unordered-map

//? As arrays can do only upto nearly equal to 10^7

//*  Map :
//*  map<key, value>
//*       |     |
//*    number  frequency
//? Example :
//? for array : 1 2 3 1 3 2 12
//? Map:
//?     12 --> 1      (4)
//?     3 --> 2       (3)
//?     2 --> 2       (2)
//?     1 --> 2       (1)
//? So here map takes 4 spaces in memory unlike if we use array hashing here it takes 13 spaces hash[13]
//? Map are more efficient then using array hashing 
//? and mpp[4] = 0 {automatically gives zero if it's not there}

// #include<iostream>
// #include<map>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     map<int, int> mpp;
    // for(int i=0;i<n;i++){
    //     cin >> arr[i];
    //     mpp[arr[i]]++;
    // }

    // //* pre-compute
    // map<int, int> mpp;        //? or we can pre-compute while taking input
    // for(int i=0;i<n;i++){     //? it will save our one for loop 
    //     mpp[arr[i]]++;
    // }

    //* iterate in the map
    // for(auto it : mpp){    //? Map stores in sorted order 
    //     cout << it.first << "-->" << it.second << endl;
    // }

//     int q;
//     cin >> q;
//     while(q--){
//         int number;
//         cin >> number;
//         //* fetch
//         cout << mpp[number] << endl;
//     }
//     return 0;
// }

//* Unordered Map
// #include<iostream>
// #include<unordered_map>
// using namespace std;
// int main(){
//     int n;
//     cin >> n;
//     int arr[n];
//     unordered_map<int, int> mpp;
//     for(int i=0;i<n;i++){
//         cin >> arr[i];
//         mpp[arr[i]]++;
//     }

//     //* pre-compute
//     unordered_map<int, int> mpp;
//     for(int i=0;i<n;i++){          //? or we can pre-compute while taking input
//         mpp[arr[i]]++;             //? it will save our one for loop 
//     }

    //* iterate in the unordered map
    // for(auto it : mpp){           //? We know that it's unordered 
    //     cout << it.first << "-->" << it.second << endl;
    // }

//     int q;
//     cin >> q;
//     while(q--){
//         int number;
//         cin >> number;
//         //* fetch
//         cout << mpp[number] << endl;
//     }
//     return 0;
// }

//* Time complexity : 

//* Map :
//?     storing   }
//?               }  -- O(logN)  [all best, avg, worst]
//?     fetching  }

//* Unordered Map :
//?     storing   }
//?               }  -- O(1)  [average and best]
//?     fetching  }  -- O(N)  [Worst]

//! We always prefer to use first unordered map because it rarely worst case happen
//! most of the time it end up taking O(1) [constant one]
//! If worst case happen and unordered map gives TLC then we switch to the Map.

//? And why worst case happens in unordered map ?
//? Bcz of internal Collisions 

//* Theory : (FOR UNDERSTAND COLLISION)
//* Hashing techniques -->  (1) Division Method  (Linear chaining)
//*              (2) Folding Method     (not asks only know the name)
//*              (3) Mid Square Method  (not asks only know the name)

//? division method :  it trims the array like size 0 to 9
//? arr[i] % 10
//? eg :
//? {2, 5, 16, 28, 139, 38, 48, 28, 18}
//?          0
//?          1
//?          2 --> 2
//?          3
//?          4
//?          5 --> 5
//?          6
//?          7 
//?          8  --> 18 --> 28 --> 28 --> 38 --> 48  (sorted)  [this is collision] [more we study in LinkedList]
//?          9  --> 9

//? arr : 18 28 38 48 58 .... 138
//?          0
//?          1
//?          2 
//?          3
//?          4
//?          5
//?          6
//?          7 
//?          8  --> 18 --> 28 --> 38 ...... --> 138  [This is an Collision where every value falls at same point]
//?          9  
//? that's why in unordered map the worst case has O(N) which is extremely rare 

//* Points :
//* In Map --> map<key, value>
//* key can be any data structure --> int, char, float, string, pairs, any data-structure
//* But in unordered map --> unordered_map<key, value>
//* here key limiteds to single type or structure only like int, char, float
//* we not take pair or vector as a key in unordered map 