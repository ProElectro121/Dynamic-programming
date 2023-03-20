/*There is a person who can do 1 task in a day ,  and he has 3 task
  and he an't do two task in a row
  find the max energy he can get while doing tasks in n days
*/

#include<bits/stdc++.h>
int maxCost(vector<vector<int>>& p , int col , int row , int dp[][3]) {
    if(row == -1) return 0;

    if(dp[row][col] != -1) return dp[row][col];

    // int x , y;

    // if(col == 0) {
    //     x = p[row][col] + maxCost(p , 1 , row - 1 , dp);
    //     y = p[row][col] + maxCost(p , 2 , row - 1 , dp);
    // }

    // if(col == 1) {
    //     x = p[row][col] + maxCost(p , 0 , row - 1 , dp);
    //     y = p[row][col] + maxCost(p , 2 , row - 1 , dp);
    // }

    // if(col == 2) {
    //     x = p[row][col] + maxCost(p , 0 , row - 1 , dp);
    //     y = p[row][col] + maxCost(p , 1 , row - 1 , dp);
    // }
    int maxi = -1;
    for(int i = 0; i <= 2; i++) {
        if(i != col) {
            maxi = max(maxi , p[row][col] + maxCost(p , i , row - 1 , dp));
        }
    }
   
    return dp[row][col] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &p) {
    int dp[n + 1][3];
    memset(dp , -1 , sizeof(dp));
    return max(maxCost(p , 0 , n - 1 , dp) , max(maxCost(p , 1 , n - 1 , dp) , maxCost(p , 2 , n - 1 , dp)));
}



/*using tabulation method*/

#include<bits/stdc++.h>
int ninjaTraining(int n, vector<vector<int>> &points) {
    int dp[n][3];
    memset(dp , -1 , sizeof(dp));

    dp[0][0] = points[0][0];    
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];


    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= 2; j++) {
            if(j == 0) {
                dp[i][j] = max(dp[i - 1][1] , dp[i - 1][2]) + points[i][j];
            }
            if(j == 1) {
                dp[i][j] = max(dp[i - 1][0] , dp[i - 1][2]) + points[i][j];
            }
            if(j == 2) {
                dp[i][j] = max(dp[i - 1][0] , dp[i - 1][1]) + points[i][j];
            }
        }
    }
    int maxi = -1;
    for(int j = 0; j < 3; j++) maxi = max(maxi , dp[n - 1][j]);
    return maxi;
}
