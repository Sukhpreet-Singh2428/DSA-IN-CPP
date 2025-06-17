//? Basic Maths :

//! Digits :

//* Extraction of Digits
//? N = 7789 % 10 --> 9 
//? N = N/10
//? N = 778 % 10 --> 8
//? N = N/10;
//? N = 77 % 10 --> 7
//? N = N/10
//? N = 7 % 10 --> 7
//? N = N/10
//? N = 0
//* Code
// #include<iostream>
// using namespace std;
// void extractionDigits(int num){
//     while(num>0){
//         int digit = num%10;
//         cout << digit << endl;
//         num /= 10;
//     }
// }
// int main(){
//     int num = 7789;
//     extractionDigits(num);
//     return 0;
// }


//? Count Digits : 
// #include<iostream>
// #include<math.h>
// using namespace std;
//! Brute :
// void CountDigits(int num){
//     int cnt = 0;
//     while(num>0){
//         cnt++;
//         num /= 10;
//     }
//     cout << cnt;
// }
//* Optimal : 
// void CountDigits(int num){
//     int cnt = (int)(log10(num) + 1);
//     //? num = 7789
//     //? log10(7789)  --> 3.81 --> 3.81 + 1 = 4.81 --> (int)4.81 --> 4 <-- Number of digits
//     cout << cnt;
// }
// int main(){
//     int num;
//     cin >> num;
//     CountDigits(num);
//     return 0;
// }

//! Time Complexity : 
//! TC --> O( log10(N) )
//* Tip / point :
//* whenever there is division like N/10 , N/5, N/2
//* TC --> O(log10(N)), O(log5(N)), O(log2(N))


//? Reverse a Number 
// #include<iostream>
// using namespace std;
//* Only Optimal Approach : 
// void ReverseNumber(int num){
//     int resNum = 0;
//     while(num>0){
//         int digit = num%10;
//         resNum = resNum*10 + digit;
//         num /= 10;
//     }
//     cout << resNum;
// }
// int main(){
//     int num;
//     cin >> num;
//     ReverseNumber(num);
//     return 0;
// }


//? Palindrome Number 
// #include<iostream>
// using namespace std;
// //* Already Optimal way to do
// void PalindromeNumber(int num){
//     int orig = num;
//     int revNum = 0;
//     while(num>0){
//         revNum = revNum*10 + num%10;
//         num /= 10;
//     }
//     if(revNum == orig) cout << "true";
//     else cout << "false";
// }
// int main(){
//     int num;
//     cin >> num;
//     PalindromeNumber(num);
//     return 0;
// }


//? Armstrong Number 
#include<iostream>
using namespace std;
void ArmstrongNumber(int num){
    
}
int main(){
    int num;
    cin >> num;
    ArmstrongNumber(num);
    return 0;
}