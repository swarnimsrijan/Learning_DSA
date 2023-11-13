class Solution {
public:
int minvalue(vector<vector<int>>& triangle, int rows, int columns, vector<vector<int>>& dp){
    if(rows == triangle.size() - 1)
    {
        return triangle[rows][columns];
    }
    if(dp[rows][columns] != -1){
        return dp[rows][columns];
    }

    int leftsum = minvalue(triangle, rows + 1, columns, dp);
    int rightsum = minvalue(triangle, rows + 1, columns + 1, dp);
    dp[rows][columns] = triangle[rows][columns] + min(leftsum, rightsum);
   
    return dp[rows][columns];

}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return minvalue(triangle, 0, 0, dp);
    }
};