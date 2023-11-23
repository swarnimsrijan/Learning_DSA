#include<bits/stdc++.h>
using namespace std;


//Recursive aproach
//Tc - O(2^mn)  Sc -O(m+n) 
// int solution(vector<vector<int>>& grid, int i, int j, int m, int n) {
//     if (i == m || j == n){
//         return 0;
//     }
//     if (grid[i][j] == 1){
//         return 0;
//     }
//     if (i == m - 1 && j == n - 1){
//         return 1;
//     }
//     return solution(grid, i + 1, j, m, n) + solution(grid, i, j + 1, m, n);
// }


//Top down d9p approach
//Tc :- O(mn) Sc:- O(mn)
// int solution(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& dp) {
//     if (i == m || j == n){
//         return 0;
//     }
//     if (grid[i][j] == 1){
//         return 0;
//     }
//     if (i == m - 1 && j == n - 1){
//         return 1;
//     }
//     if(dp[i][j] != -1) return dp[i][j];
//     return solution(grid, i + 1, j, m, n, dp) + solution(grid, i, j + 1, m, n, dp);
// }

//Tabulation dp approach
// int solution(vector<vector<int>>& grid, int i, int j, int m, int n) {
//     vector<vector<int>> dp(m, vector<int>(n, 0));
//     if (grid[0][0] == 0){
//         dp[0][0] = 1;
//     }
//     for(int i = 1; i < m; i++){
//         if(grid[i][0] == 0){
//             dp[i][0] = dp[i - 1][0];
//         }
//     }
//     for(int i = 1; i < n; i++){
//         if(grid[0][i] == 0){
//             dp[0][i] = dp[0][i - 1];
//         }
//     }
//     for(int i = 1; i < m; i++){
//         for(int j = 1; j < n; j++){
//             if(grid[i][j] == 0){
//                 dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//             }
//         }
//     }
//     return dp[m - 1][n - 1];
// }

int solution(vector<vector<int>>& grid, int i, int j, int m, int n) {
    //vector<vector<int>> dp(m, vector<int>(n, 0));
    if (grid[0][0] == 0){
        return 0;
    }
    grid[0][0] = 1;
    for(int i = 1; i < m; i++){
        if(grid[i][0] == 0){
            grid[i][0] = grid[i - 1][0];
        }
        else{
            grid[i][0] = 0;
        }
    }
    for(int i = 1; i < n; i++){
        if(grid[0][i] == 0){
            grid[0][i] = grid[0][i - 1];
        }
        else{
            grid[0][i] = 0;
        }
    }
    for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
            if(grid[i][j] == 0){
                grid[i][j] = grid[i - 1][j] + dp[i][j - 1];
            }
            else{
                grid[i][j] = 0;
            }
        }
    }
    return grid[m - 1][n - 1];
}
int main() {
    vector<vector<int>> grid = { { 0, 0, 0 },
                             { 0, 1, 0 },
                             { 0, 0, 0 } };
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << solution(grid, 0, 0, m, n) << "\n";
    return 0;
}
