/*
Catalan no is a mathematical sequence which is used to find the number of possibilities of various combinations.
nth term represented by Cn = (2n)!
                            -------
                            (n+1)!n!

Sequence is: 1, 1, 2, 5, 14, 42, 132, 429.......
It follows the recursive order: 
            Cn+1 = (C0.Cn-1 + C1.Cn-2.............+Cn-1.c0)
*/

#include<bits/stdc++.h>
using namespace std;

//1st approach
//Recursive approach
//Tc - O(2^n) Sc- O(n) 
// unsigned long int catalan(int n){
//     unsigned long int res = 0;
//     if (n <= 1) return 1;
//     for(int i = 0; i < n; i++){
//         res += catalan(i)*catalan(n - i - 1);
//     }
//     return res;
// }

//2nd approach
//DP approach 
//Tc- O(n) Sc - O(n)

// unsigned long int catalan(int n){
//     unsigned long int catalan[n + 1];
//     catalan[0] = 1;
//     catalan[1] = 1;
//     for(int i = 2; i <= n; i++){
//         catalan[i] = 0;
//         for(int j = 0; j < i; j++){
//             catalan[i] += catalan[j] * catalan[i - j - 1];
//         }
//     }
//     return catalan[n];
// }

//3rd approach
//using mathematics
//n
// C  == (n - r - 1)! / r!
//  r     
// Tc - O(n) Sc - O(n)
unsigned long int binomial_coefficient(int n, int r){
    unsigned long int res = 1;
    if(r > n - r){
        r = n - r;
    }
    for(int i = 0; i < r; i++){
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
unsigned long int catalan(int n){
    unsigned long int ans = binomial_coefficient(2*n, n);
    return ans/(n+1);
}

int main(){
    int n;
    cout << "Enter the number:  ";
    cin >> n;
    cout << "The catalan value is: " << catalan(n);
}