#include<bits/stdc++.h>
using namespace std;

//1st approach 
//Tc :- O(N), Sc :- O(1)
// int c(int n, int r){
//     if(r > n) return -1;
//     int res = 1;
//     for(int i = 1; i <= r; i++){
//         res *= (n - i + 1);
//         res /= i;
//     }
//     return res;
// }

//2nd approach 
//recursive approach
//Tc - O(N), Sc - O(N)
// int c(int n, int r){
//     if(r > n) return -1;
//     if(r == 0 || r == n) return 1;
//     if(n == 0) return 0;
//     return (n / r) * c(n-1, r-1);
// }

//3rd approach
//recursive approach
//c(n, r) = c(n - 1, r - 1) + c(n -1, r)
//Tc :- O(N * max(r, n - r)), Sc :- O(N * max(r, n - r))
// int c(int n, int r){
//     if(n < r) return -1;
//     if(r == 0 || r == n) return 1;
//     if(n == 0) return 0;
//     return c(n - 1, r - 1) + c(n - 1, r);
// }

//Dp approach
//Tabulation approach(Bottom up)
//Tc - O(n * r), Sc - O(n * r)
// int min(int a, int b){ return (a < b ? a : b);}
// int c(int n, int r){
//     int dp[n+1][r+1];
//     int i, j;
//     for(i = 0; i <= n; i++){
//         for(j = 0; j <= min(i, r); j++){
//             if(j == 0 || j == i){
//                 dp[i][j] = 1;
//             }
//             else{
//                 dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
//             }
//         }
//     }
//     return dp[n][r];
// }

//space optimized dp approach
//Tc - O(n*k), Sc - O(k)
// int c(int n, int r){
//     int C[r + 1];
//     memset(C, 0, sizeof(C));
 
//     C[0] = 1; // nC0 is 1
 
//     for (int i = 1; i <= n; i++)
//     {
       
//         // Compute next row of pascal triangle using
//         // the previous row
//         for (int j = min(i, r); j > 0; j--)
//             C[j] = C[j] + C[j - 1];
//     }
//     return C[r];
// }

//Memoization approach

int binomialCoeffUtil(int n, int k, int** dp)
{
    // If value in lookup table then return
    if (dp[n][k] != -1)      
        return dp[n][k];
    // store value in a table before return
    if (k == 0 || k == n) {
        dp[n][k] = 1;
        return dp[n][k];
    }
    // save value in lookup table before return
    dp[n][k] = binomialCoeffUtil(n - 1, k - 1, dp) +
               binomialCoeffUtil(n - 1, k, dp);
    return dp[n][k];
}
 
int c(int n, int k)
{
    int** dp; // make a temporary lookup table
    dp = new int*[n + 1];
 
    // loop to create table dynamically
    for (int i = 0; i < (n + 1); i++) {
        dp[i] = new int[k + 1];
    }
 
    // nested loop to initialise the table with -1
    for (int i = 0; i < (n + 1); i++) {
        for (int j = 0; j < (k + 1); j++) {
            dp[i][j] = -1;
        }
    }
 
    return binomialCoeffUtil(n, k, dp);
}

int main(){
    int n, r;
    cout << "Enter n and r: ";
    cin >> n >> r;
    cout << c(n ,r);
    return 0;
}