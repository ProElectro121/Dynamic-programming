/*Using memoisation*/

class Solution {
private:
    int minCost(vector<vector<int>>& grid , int i , int j , int m , int n , vector<vector<int>>& dp) {
        if(i == m - 1 and j == n - 1) return grid[i][j];

        int left = INT_MAX;
        int right = INT_MAX;

        if(dp[i][j] != -1) return dp[i][j];

        if(i + 1 < m and j < n) {
            left = grid[i][j] + minCost(grid , i + 1, j , m , n , dp);
        }
        if(j + 1 < n and i < m) {
            right = grid[i][j] + minCost(grid , i , j + 1 , m , n , dp);
        }
        return dp[i][j] = min(left , right);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return minCost(grid , 0 , 0 , m , n , dp);
    }
};

/*Using Tabulation*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int dp[m][n];
        memset(dp , INT_MAX , sizeof(dp));

        dp[0][0] = grid[0][0];

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 and j == 0) continue;

                if(i == 0) {
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                }
                else if(j == 0) {
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j] , dp[i][j - 1]) + grid[i][j];
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
