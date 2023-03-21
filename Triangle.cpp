/*Memoisation solution*/

class Solution {
public:
class Solution {
private:
    int minpathSum(vector<vector<int>>& triangle , int i , int j ,int m , vector<vector<int>>& dp) {
        if(i == m - 1) return triangle[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int left = minpathSum(triangle , i + 1 , j , m , dp) + triangle[i][j];
        int right = minpathSum(triangle , i + 1, j + 1 , m , dp) + triangle[i][j];

        return dp[i][j] = min(left , right);
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp;
        for(int i = 1; i <= m; i++) {
            dp.push_back(vector<int>(i , -1));
        }
        return minpathSum(triangle , 0 , 0 ,m , dp);
    }
};


/*Using tabulaiton*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp;
        int m = triangle.size();

        for(int i = 1; i <= m; i++) {
            dp.push_back(vector<int>(i , 0));
        }
        dp[0][0] = triangle[0][0];

        for(int i = 1; i < m; i++) {
            for(int j = 0; j <= i; j++) {
                if(j == 0) {
                    dp[i][j] = dp[i - 1][j] + triangle[i][j];
                }
                else if(j == i) {
                    dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
                }
                else {
                    dp[i][j] = min(dp[i - 1][j - 1] , dp[i - 1][j]) + triangle[i][j];
                }
            }
        }
        int maxi = INT_MAX;
        for(int i = 0; i < m; i++) {
            maxi = min(maxi , dp[m - 1][i]);
        }
        return maxi;
    }
};
