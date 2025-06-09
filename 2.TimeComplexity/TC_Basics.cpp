//? What is Time Complexity ?
//! Time complexity is not equal to time taken by code
//! Example: if we run the same code on two system: one old window and other new macbook
//! old windows takes 2s for execution and new macbook takes 1s for execution so it doesn't mean code has 
//! tc = 2s or tc = 1s bcz it vary system to system, later run on an another new system that take less than 1s, so
//! time complexity never means time taken
//* Time Complexity: Rate at which the time taken increases with respect to the input size.
//* TC --> Big-O Notation --> o( )

//! Rules:
//* --> Always compute TC in worst case scenerio
//* --> avoid constants
//* --> avoid lower values

//* Example:
//* for(int i=1; i<N; i++){     
//*     cout << "Raj";
//* }
//* TC : o(N * 3)
//? Over N times, it is doing 3 things increament, check(condition) and print

//! Rule : Always compute TC in worst case scenerio
//!        There are 3 Cases : Best Case, Average Case and Worst Case
//* Example:
//? if(marks < 25) cout << "grade D";
//? else if(marks < 45) cout << "grade C";
//? else if(marks < 65) cout << "grade B";
//? else cout << "grade A";
//* marks = 10 --> o(2)  <-- Best case
//* marks = 70 --> o(4)  <-- worst case

//! Rule : Avoid Constants
//? Example:
//? o(4N^3 + 3N^2 + 8)
//? input N = 10^5
//? o(4 * 10^15 + 3 * 10^10 + 8)
//* 4 * 10^15 + 3 * 10^10 : itself much a big number than + 8 to that has no significane
//* so we don't take 8, as 8 has no significance here
//? Similar in code:
//? int n = 2;
//? for(int i=1; i<N; i++){     
//?     cout << "Raj";
//? }
//* so we think TC will : o(N*3 + 1)
//* But we never take these unit operations. TC remains : o(N*3)
//! We Avoid Constants, TC : o(N*3)

//! Rule : Avoid Lower Values
//? Example:
//? o(4N^3 + 3N^2 + 8)
//? input N = 10^5
//? o(4 * 10^15 + 3 * 10^10 + 8)
//* Adding 10^10 to 10^15 has no significacne at all, As 10^15 is itself is an huge value so adding
//* 10^10 to it has no siginficance. It is not adding that much difference/operations SO WE AVOID LOWER VALUES
//! SO in such a case, we avoid lower values 

//? Big - O            Theta                      Omega
//?    |                  |                         |
//?    v                  v                         v
//* worst-case        [Average Complexity]      Best-case
//* [upper - band]                             [Lower band]   

//! Questions:

//? for(int i=0; i<N; i++){
//?     for(int j=0; j<N; j++){
//?         Block of code
//?         [Constant time]
//?     }
//? }
//* i=0   {j = 0,1,2,3,..........,N}
//* i=1   {j = 0,1,2,3,..........,N}
//* i=2   {j = 0,1,2,3,..........,N}
//*  .
//*  .
//*  .
//* i=N-1   {j = 0,1,2,3,..........,N}
//* N + N + N + ...... + N
//* N * N 
//* There are also certain things increment or checking condition or comparsion which we not consider
//! As we Avoid Lower Values : <-- RULE
//* O(N * N) --> O(N^2) <-- TC

//? for(int i=0; i<N; i++){
//?     for(int j=0; j<=i; j++){
//?         Block of code
//?         [Constant time]
//?     }
//? }
//* i=0   {j = 0}
//* i=1   {j = 0,1}
//* i=2   {j = 0,1,2}
//*  .
//*  .
//*  .
//* i=N-1   {j = 0,1,2,3,..........,N-1}
//* --> 1 + 2 + 3 + 4 + ...... + N
//* --> [N*(N+1)]/2
//* --> O(N^2/2 + N/2)  <-- Exact TC
//* --> O(N^2/2) --> near to O(N^2)  According to rules


//! Space Complexity :
//? It's the memory space your program takes. but this varies from system to system.
//? So we can't depend on machine/system.
//* So we will use Big O Notation again.

//! Space Complexity :- Auxiliary space + Input space
//* Auxiliary Space --> Space that you take to solve the problem
//* Input Space --> the space that you take to store the input

//? Example : 
//? take a and b input 
//? cin >> a >> b
//? then performing c = a + b
//* there c is auxiliary space and a,b is input space
//* so overall space compliexity is o(3)
//? Example : 
//? int arr[N];
//* Space compliexity here is o(N)