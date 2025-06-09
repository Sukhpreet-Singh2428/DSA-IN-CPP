// #include<iostream>
// using namespace std;
//! Outputs :
// int main(){
//     // std::cout << "Hey !!" << "\n";
//     // std::cout << "Hey !!" << std::endl;
//     // std::cout << "Sukhpreet Singh";
//*     cout << "Hey !!" << endl;
//*     cout << "Sukhpreet Singh";
//     return 0;
// }

//! INPUTS : 
// int main(){
//     int x,y;
//*     cin >> x >> y;
//*     cout << "Value of x: " << x << " and y: " << y;
//     return 0;
// }

// Prefix	Purpose	Example: (Better comments)
    // !	Important or alert	// ! This is a critical warning
    // *	Highlighted or emphasized	// * This is a highlighted note
    // ?	Question or clarification	// ? Is this the best approach?
    // TODO	To-do items	// TODO: Refactor this method
    // FIXME	Needs fixing	// FIXME: This causes a bug

//! DATATYPES :
// int main(){
    // int
    // int x = 10;
    // long
    //* long y = 15;  // <-- bigger than int in range
    // long long x = 150000000
    // float, double
    // float x = 5.6;
    // double y = 5;
    // cout << "Value of y: " << y;
    
    //* String and getline
    // string s;
    // cin >> s;
    // cout << s;  //! only first word keep up before space

    // string str;
    // getline(cin,str);  //! Entire Line is keep up 
    // cout << str;       //? but Not the next line is keep up after ENTER

    //* char
    // char ch = 'g';
    // cin >> ch;
    // cout << ch;

//     return 0;
// }

//! If - Else:
//? Write a program that takes an input of age and prints if you are adult or not
// #include<iostream>
// using namespace std;
// int main(){
//     int age;
//     cin >> age;
//     if(age>=18){
//         cout << "You are Adult";
//     }else{
//         cout << "you are Not Adult";
//     }
//     return 0;
// }

//? A school has following rules for grading system:
//? a. Below 25 - F 
//? b. 25 to 44 - E
//? c. 45 to 49 - D
//? d. 50 to 59 - C
//? e. 60 to 79 - B
//? f. 80 to 100 - A
//? Ask user to enter marks and print the corresponding grade.
// #include<iostream>
// using namespace std;
// int main(){
//     int marks;
//     cin >> marks;
//     //! if(marks < 25) cout << "F";
//     //! if(marks>=25 && marks<=44) cout << "E";
//     //! if(marks>=45 && marks<=49) cout << "D";
//     //! if(marks>=50 && marks<=59) cout << "C";
//     //! if(marks>=60 && marks<=79) cout << "B";
//     //! if(marks>=80 && marks<=100) cout << "A";

//     //* More time saving and not checking condition again and again !
//     //! if(marks < 25) cout << "F";
//     //! else if(marks<=44) cout << "E";
//     //! else if(marks<=49) cout << "D";
//     //! else if(marks<=59) cout << "C";
//     //! else if(marks<=79) cout << "B";
//     //! else if(marks<=100) cout << "A";
//     return 0;
// }

//? Take the age from the user and then decide accordingly 
//? 1. If age < 18
//?    print -> not eligible for job
//? 2. If age >= 18 
//?    print -> "eligible for job"
//? 3. If age >= 55 and age <= 57,
//?    print -> "eligible for job, but retirement soon."
//? 4. If age -> "retirement time"
// #include<iostream>
// using namespace std;
// int main(){
//     int age;
//     cin >> age;
//     if(age<18) cout << "Not eligible for job";
//     else if(age<=54){
//         cout << "eligible for job";
//     }
//     else if(age<=57){
//         cout << "eligible for job, but retirement soon.";
//     }
//     else{
//         cout << "retirement time";
//     }
//     return 0;
// }

//! Switch statements :
//? Take the day no and print the corresponding day
//? for 1 print Monday
//? for 2 print Tuesday and so on for 7 print Sunday.
// #include<iostream>
// using namespace std;
// int main(){
//     int day;
//     cin >> day;

//     switch(day){
//         case 1:
//             cout << "Monday";
//             break;
//         case 2:
//             cout << "Tuesday";
//             break;
//         case 3: 
//             cout << "Wednesday";
//             break;
//         case 4:
//             cout << "Thuresday";
//             break;
//         case 5:
//             cout << "Friday";
//             break;
//         case 6:
//             cout << "Saturday";
//             break;
//         case 7:
//             cout << "Sunday";
//             break;
//         default:
//             cout << "Invalid";
//     }
//     return 0;
// }

//! Arrays and Strings: 
// #include<iostream>
// using namespace std;
// int main(){
//     //* array
//     int arr[5];
//     for(int i=0;i<5;i++){
//         cin >> arr[i];
//     }
//     cout << arr[3];
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main(){
//     //* 2D array
//     int arr[3][5];
//     for(int i=0;i<3;i++){
//         for(int j=0;j<5;j++){
//             cin >> arr[i][j];
//         }
//     }
//     for(int i=0;i<3;i++){
//         for(int j=0;j<5;j++){
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main(){
//     //* Strings
//     string s = "Striver";
//     cout << s[0];
//!     int len = s.size();
//     s[len - 1] = 'z';
//     cout << s[len-1];
//     return 0;
// }

//! LOOPS:
// #include<iostream>
// using namespace std;
// int main(){
    //* for loop
    // for(int i=1;i<=5;i++){
    //     cout << "Sukhpreet" << endl;
    // }

    //* while loop
    // int i = 1;
    // while(i<=5){
    //     cout << "Sukhpreet" << endl;
    //     i++;
    // }

    //* do while loop
    // int i = 2;
    // do {
    //     cout << "Sukhpreet" << endl;
    //     i++;
    // } while(i<=1);
    // return 0;
// }

//! Functions:
#include<iostream>
using namespace std;
//* Void function
// void printName(){
//     cout << "Heyy, Sukhpreet!";
// }
// int main(){
//     printName();
//     return 0;
// }

//* parameterised void function
// void printName(string name){
//     cout << "Hey " << name << endl;
// }
// int main(){
//     string name1;
//     cin >> name1;
//     string name2;
//     cin >> name2;
//     printName(name1);
//     printName(name2);
//     return 0;
// }

//* Return function
// int sum(int num1, int num2){
//     int sum = num1 + num2;
//     return sum;
// }
// int main(){
//     int num1, num2;
//     cin >> num1 >> num2;
//     int res = sum(num1,num2);
//     cout << res;
//     return 0;
// }

//* Pass by Value 
// void dosomething(int num){
//     cout << num << endl;   //* --> 10
//     num += 5;
//     cout << num << endl;   //* --> 15
// }
// int main(){
//     int num = 10;
//     dosomething(num);
//     cout << num << endl;   //* --> 10
//     return 0;
// }

//* Pass by reference 
// void dosomething(int* num){
//     cout << *num << endl;   //* --> 10
//     *num += 5;
//     cout << *num << endl;   //* --> 15
// }
// int main(){
//     int num = 10;
//     dosomething(&num);
//     cout << num << endl;   //* --> 15
//     return 0;
// }

void dosomething(int* arr, int n){
    arr[0] += 100;
    cout << "Value inside function: " << arr[0] << endl;
}
int main(){
    int n = 5;
    int arr[5];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    dosomething(arr,n);
    cout << "Value inside int main: " << arr[0] << endl;
    return 0;
}