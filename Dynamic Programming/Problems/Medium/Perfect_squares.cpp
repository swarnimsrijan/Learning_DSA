class Solution {
public:
    int numSquares(int n) {
        if (n < 0) return -1;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], 1 + dp[i - j * j]);
            }
        }

        return dp[n];
    }

    // int solve(int n, vector<int>& dp){
//     if(n < 0) return -1;
//     if(n == 0) return 0;
//     if(dp[n] != -1) return dp[n];
//     int ans = INT_MAX;
//     for(int i = 1; i * i <= n; i++){
//         int sqa = i * i;
//         int count  = 1 + solve(n - sqa, dp);
//         ans = min(ans, count);
//     }
//     return dp[n] = ans;
// }
//     int numSquares(int n) {
//         vector<int> dp(n + 1, -1);
//         return solve(n, dp);
//     }
//}





    
};
