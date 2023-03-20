/*Count all possible path from index (0 , 0) to (row  , col) and robot can move in rigth and  bottom direction*/

/*Memoisation solution
  for recurrsion time complexity is 2^(m * n) and space complexity is (m + 1, n  + 1) 
*/

class Solution {
private:
    
    int totaluniquepaths(int i , int j , int row , int col ,  vector<vector<int>>& dp) {
        if(i == row  - 1 and j == col - 1) return 1;

        if(dp[i][j] != -1) return dp[i][j];
        int x = 0 , y = 0;
        if(i + 1 < row and j < col)
          x = totaluniquepaths(i + 1 , j , row , col , dp);

        if(j + 1 < col and i < row)
          y = totaluniquepaths(i , j + 1 , row , col , dp);

        return dp[i][j] = x + y;   
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return totaluniquepaths(0 , 0 , m , n , dp);
    }
};


/*Tabulation solution */

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n , -1));

        dp[0][0] = 1;

        for(int i = 0 ; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(i == 0 and j == 0) continue;
                if(i == 0) {
                    dp[i][j] = dp[i][j - 1] ;
                }
                else if(j == 0){
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1] ;
                }                
            }
        }
        return dp[m - 1][n - 1];
    }
};
