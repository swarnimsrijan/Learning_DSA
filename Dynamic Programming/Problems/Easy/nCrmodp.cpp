#include<bits/stdc++.h>
using namespace std;

//Recursive approach
// int nCrmodp(int n, int r, int p){
//     if(r == 0 || r == n) return 1;
//     if(n == 0) return 0; 
//     return (nCrmodp(n - 1, r - 1, p) + nCrmodp(n - 1, r, p)) % p ;
// }

//Dyanamic approach
// int nCrmodp(int n, int r, int p){
//     int dp[n + 1][r + 1];
//     int i, j;
//     for(int i = 0 ;i <= n; i++){
//         for(int j = 0; j <= min(i, r); j++){
//             if(j == 0 || j == i){
//                 dp[i][j] = 1;
//             }
//             else
//                 dp[i][j] = dp[i-1][j-1] + dp[i - 1][j];
//         }
//     }
//     return dp[n][r]%p;
// }


//more optimized dp approach
int nCrmodp(int n, int r, int p){
    int dp[r + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1 ;i <= n; i++){
        for(int j = min(i, r); j > 0; j--){
            dp[j] = (dp[j -1] + dp[j]) % p;
        }
    }
    return dp[r];
}


int main(){
    int n, r, p, test;
    cout << "Enter the no of testcases: ";
    cin >> test;
    while(test--){
        cout << "Enter the numbers n, r, p: ";
        cin >> n >> r >> p;
        cout << "The result is: " << nCrmodp(n, r, p) << endl;
    }
    return 0;
}