class Solution {
private:
    int maxpick(vector<vector<int>>& grid , int i , int j1 ,int j2 , int m , int n , vector<vector<vector<int>>>& dp) {
        if(i == m - 1) {
            if(j1 == j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int dx[] = {-1 , 0 , 1};
        int maxi = 0;
        for(int ind  = 0; ind < 3; ind++) {
            for(int j = 0; j < 3; j++) {
                int alicemove =j1 + dx[ind];
                int bobmove = j2 + dx[j];
                int value = 0;

                if(j1 == j2) {
                    value = grid[i][j1];
                }
                else {
                    value = grid[i][j1] + grid[i][j2];
                }
                if(alicemove >= 0 and alicemove < n and bobmove >= 0 and bobmove < n) {
                    maxi = max(maxi ,value + maxpick(grid , i + 1, alicemove , bobmove , m, n , dp));
                }
            }
        }
        return dp[i][j1][j2] = maxi;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(m , vector<vector<int>> (n , vector<int>(n , -1)));
        return maxpick(grid , 0 , 0 , n - 1 , m , n , dp);
    }
};
