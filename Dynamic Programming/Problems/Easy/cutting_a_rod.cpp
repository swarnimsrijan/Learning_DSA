#include<bits/stdc++.h>
using namespace std;
//Recursive approach
//Tc- O(2^n), Sc - O(2^n)
// int cuts(int price[], int index, int n){
//     if(index == 0){
//         return n * price[0];
//     }
//     int res = cuts(price, index - 1, n);
//     int rod_length = index + 1;
//     if(rod_length <= n){
//         res = max(res, price[index] + cuts(price, index -1, n - rod_length));
//     }
//     return res;
// }

//dp approach
int cuts(int price[], int index, int n, int dp[][]){
    if(index == 0){
        return n * price[0];
    }
    if(dp[index][n] != -1){
        return dp[index][n];
    }
    int res = cuts(price, index - 1, n, dp);
    int rod_length = index ++;
    if(rod_length <= n){
        res = max(res, price[index] + cuts(price, index - 1, n - rod_length, dp));
    }
    return dp[index][n] = res;
}


//dp iterative approach
int cutRod(int prices[], int n)
{
    int mat[n + 1][n + 1];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                mat[i][j] = 0;
            }
            else {
                if (i == 1) {
                    mat[i][j] = j * prices[i - 1];
                }
                else {
                    if (i > j) {
                        mat[i][j] = mat[i - 1][j];
                    }
                    else {
                        mat[i][j] = max(prices[i - 1]
                                            + mat[i][j - i],
                                        mat[i - 1][j]);
                    }
                }
            }
        }
    }
    return mat[n][n];
}
//dp bottomup solution
int cutRod(int price[], int n)
{
   int val[n+1];
   val[0] = 0;
   int i, j;
 
   // Build the table val[] in bottom up manner and return the last entry
   // from the table
   for (i = 1; i<=n; i++)
   {
       int max_val = INT_MIN;
       for (j = 0; j < i; j++)
         max_val = max(max_val, price[j] + val[i-j-1]);
       val[i] = max_val;
   }
 
   return val[n];
}

int main(){
    int test;
    cout << "Enter the number of testcases: ";
    cin >> test;
    while(test--){
        int n;
        cout << "Enter the size: ";
        cin >> n;
        int price[n];
        int dp[n][n + 1];
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= n; j++){
                dp[i][j] = -1;
            }
        }
        cout << "Enter the elements of array: ";
        for(int i= 0 ;i < n; i++){
            cin >> price[i];
        }
        cout << "Maximum obtainable value: " << cuts(price, n - 1, n, dp);
    }
    return 0;
}