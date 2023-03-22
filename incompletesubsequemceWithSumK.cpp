/*memoisation solution*/

#include <bits/stdc++.h> 
bool ispossible(vector<int>& nums , int index , int target , vector<vector<int>>& dp) {
    if(target == 0) return true;
    if(index == 0) return (nums[index] == target);

    if(dp[index][target] != -1) return dp[index][target]; 


    bool notTake = ispossible(nums , index - 1 , target , dp);

    bool take = false;
    if(nums[index] <= target) take = ispossible(nums , index - 1, target - nums[index] , dp);

    return dp[index][target] = (int)(take or notTake);
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n , vector<int>(k + 1 , -1));
    return ispossible(arr , n - 1 , k , dp);
}
